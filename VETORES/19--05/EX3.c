#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um paciente (nó da fila)
struct Patient {
    char name[30];          // Nome do paciente
    int age;                // Idade do paciente
    struct Patient* prox;   // Próximo paciente na fila
};

// Função para enfileirar (inserir paciente no final da fila)
void enqueue(struct Patient** start, struct Patient** end) {
    struct Patient* new = (struct Patient*)malloc(sizeof(struct Patient));  // Aloca memória para o novo paciente
    if (new == NULL) {
        printf("Falha na alocação de memória!\n");
        return;
    }

    printf("Digite o nome do paciente (sem espaços): ");
    scanf("%s", new->name);  // Lê o nome do paciente
    printf("Digite a idade do paciente: ");
    scanf("%d", &new->age);   // Lê a idade do paciente

    new->prox = NULL;  // Como é o último paciente, o ponteiro 'prox' é NULL

    if (*start == NULL) {
        // Se a fila estiver vazia, o novo paciente será o primeiro e o último
        *start = new;
        *end = new;
    } else {
        // Se a fila não estiver vazia, adiciona o novo paciente ao final
        (*end)->prox = new;
        *end = new;  // Atualiza o ponteiro do final da fila
    }

    printf("Paciente inserido com sucesso na fila.\n");
}

// Função para atender (remover) o paciente da frente da fila
void attendPatient(struct Patient** start, struct Patient** end) {
    if (*start == NULL) {
        printf("Fila vazia! Nenhum paciente para atender.\n");
        return;
    }

    struct Patient* temp = *start;  // Armazena o paciente que será atendido
    printf("Atendendo o paciente: %s (idade %d)\n", temp->name, temp->age);

    *start = temp->prox;  // Avança o início da fila para o próximo paciente

    if (*start == NULL) {
        // Se a fila ficar vazia após o atendimento, atualiza o fim da fila
        *end = NULL;
    }

    free(temp);  // Libera a memória do paciente atendido
}

// Função para mostrar todos os pacientes na fila
void showRow(struct Patient* start) {
    if (start == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\nFila de pacientes:\n");
    while (start != NULL) {
        printf("%s (idade %d)\n", start->name, start->age);
        start = start->prox;  // Avança para o próximo paciente
    }
}

// Função principal com o menu interativo
int main() {
    struct Patient* start = NULL;  // Ponteiro para o início da fila
    struct Patient* end = NULL;    // Ponteiro para o final da fila
    int option;

    do {
        printf("\n=== MENU DA FILA DE PACIENTES ===\n");
        printf("1. Inserir paciente na fila\n");
        printf("2. Atender próximo paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                enqueue(&start, &end);  // Chama a função para inserir paciente na fila
                break;
            case 2:
                attendPatient(&start, &end);  // Chama a função para atender paciente
                break;
            case 3:
                showRow(start);  // Exibe todos os pacientes na fila
                break;
            case 0:
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 0);  // Repete até o usuário escolher sair

    // Libera a memória restante da fila (se houver pacientes)
    while (start != NULL) {
        attendPatient(&start, &end);
    }

    return 0;
}
