#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do paciente
struct Paciente {
    char nome[30];
    int idade;
    struct Paciente *prox;
};

// Função para inserir paciente
void inserirPaciente(struct Paciente **inicioPrioritaria, struct Paciente **fimPrioritaria,
                     struct Paciente **inicioComum, struct Paciente **fimComum) {
    struct Paciente *novo = (struct Paciente *)malloc(sizeof(struct Paciente));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Digite o nome do paciente (sem espaços): ");
    scanf("%s", novo->nome);

    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->idade);

    novo->prox = NULL;

    if (novo->idade >= 60) {
        // Inserir na fila prioritária
        if (*fimPrioritaria == NULL) {
            *inicioPrioritaria = novo;
            *fimPrioritaria = novo;
        } else {
            (*fimPrioritaria)->prox = novo;
            *fimPrioritaria = novo;
        }
        printf("Paciente PRIORITÁRIO inserido.\n");
    } else {
        // Inserir na fila comum
        if (*fimComum == NULL) {
            *inicioComum = novo;
            *fimComum = novo;
        } else {
            (*fimComum)->prox = novo;
            *fimComum = novo;
        }
        printf("Paciente COMUM inserido.\n");
    }
}

// Função para atender paciente (prioridade primeiro)
void atenderPaciente(struct Paciente **inicioPrioritaria, struct Paciente **fimPrioritaria,
                     struct Paciente **inicioComum, struct Paciente **fimComum) {
    struct Paciente *temp;

    if (*inicioPrioritaria != NULL) {
        // Atender da fila prioritária
        temp = *inicioPrioritaria;
        printf("Atendendo (PRIORITÁRIO): %s (idade %d)\n", temp->nome, temp->idade);
        *inicioPrioritaria = temp->prox;
        if (*inicioPrioritaria == NULL) {
            *fimPrioritaria = NULL;
        }
        free(temp);
    } else if (*inicioComum != NULL) {
        // Atender da fila comum
        temp = *inicioComum;
        printf("Atendendo (COMUM): %s (idade %d)\n", temp->nome, temp->idade);
        *inicioComum = temp->prox;
        if (*inicioComum == NULL) {
            *fimComum = NULL;
        }
        free(temp);
    } else {
        printf("Nenhum paciente na fila.\n");
    }
}

// Mostrar as filas
void mostrarFilas(struct Paciente *inicioPrioritaria, struct Paciente *inicioComum) {
    printf("\n--- Fila Prioritária ---\n");
    if (inicioPrioritaria == NULL) {
        printf("(vazia)\n");
    } else {
        while (inicioPrioritaria != NULL) {
            printf("- %s (idade %d)\n", inicioPrioritaria->nome, inicioPrioritaria->idade);
            inicioPrioritaria = inicioPrioritaria->prox;
        }
    }

    printf("\n--- Fila Comum ---\n");
    if (inicioComum == NULL) {
        printf("(vazia)\n");
    } else {
        while (inicioComum != NULL) {
            printf("- %s (idade %d)\n", inicioComum->nome, inicioComum->idade);
            inicioComum = inicioComum->prox;
        }
    }
}

// Função principal com menu
int main() {
    struct Paciente *inicioPrioritaria = NULL, *fimPrioritaria = NULL;
    struct Paciente *inicioComum = NULL, *fimComum = NULL;
    int opcao;

    do {
        printf("\n===== MENU FILA COM PRIORIDADE =====\n");
        printf("1. Inserir paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Mostrar filas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirPaciente(&inicioPrioritaria, &fimPrioritaria, &inicioComum, &fimComum);
                break;
            case 2:
                atenderPaciente(&inicioPrioritaria, &fimPrioritaria, &inicioComum, &fimComum);
                break;
            case 3:
                mostrarFilas(inicioPrioritaria, inicioComum);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    // Libera memória restante
    while (inicioPrioritaria != NULL || inicioComum != NULL) {
        atenderPaciente(&inicioPrioritaria, &fimPrioritaria, &inicioComum, &fimComum);
    }

    return 0;
}
