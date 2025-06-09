#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do paciente
struct Paciente {
    char nome[30];
    int idade;
    struct Paciente *prox;
};

// Função para inserir paciente com ou sem prioridade
void inserirComPrioridade(struct Paciente **inicio, struct Paciente **fim) {
    struct Paciente *novo = (struct Paciente*)malloc(sizeof(struct Paciente));
    if (!novo) {
        printf("Falha na alocação de memória.\n");
        return;
    }

    printf("Digite o nome do paciente (sem espaços): ");
    scanf("%s", novo->nome);
    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->idade);
    novo->prox = NULL;

    // PRIORIDADE: idade >= 60
    if (novo->idade >= 60) {
        // Inserir no início da fila
        novo->prox = *inicio;
        *inicio = novo;

        if (*fim == NULL) {
            *fim = novo;
        }

        printf("Paciente com PRIORIDADE inserido no início da fila.\n");
    } else {
        // Inserir no final da fila (fila comum)
        if (*fim == NULL) {
            *inicio = novo;
            *fim = novo;
        } else {
            (*fim)->prox = novo;
            *fim = novo;
        }

        printf("Paciente comum inserido no final da fila.\n");
    }
}

// Atender paciente (sempre o primeiro da fila)
void atenderPaciente(struct Paciente **inicio, struct Paciente **fim) {
    if (*inicio == NULL) {
        printf("Fila vazia! Nenhum paciente para atender.\n");
        return;
    }

    struct Paciente *temp = *inicio;
    printf("Atendendo: %s (idade %d)\n", temp->nome, temp->idade);
    *inicio = temp->prox;

    if (*inicio == NULL) {
        *fim = NULL;
    }

    free(temp);
}

// Mostrar todos os pacientes da fila
void mostrarFila(struct Paciente *inicio) {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("\nFila de pacientes (prioritários primeiro):\n");
    while (inicio != NULL) {
        printf("- %s (idade %d)\n", inicio->nome, inicio->idade);
        inicio = inicio->prox;
    }
}

int main() {
    struct Paciente *inicio = NULL;
    struct Paciente *fim = NULL;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirComPrioridade(&inicio, &fim);
                break;
            case 2:
                atenderPaciente(&inicio, &fim);
                break;
            case 3:
                mostrarFila(inicio);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    // Liberação da memória
    while (inicio != NULL) {
        atenderPaciente(&inicio, &fim);
    }

    return 0;
}
