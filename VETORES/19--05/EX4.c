#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um paciente (n� da fila)
struct Patient {
    char name[30];          // Nome do paciente
    int age;                // Idade do paciente
    struct Patient* prox;   // Pr�ximo paciente na fila
};

// Fun��o para enfileirar (inserir paciente no final da fila)
void enqueue(struct Patient** start, struct Patient** end) {
    struct Patient* new = (struct Patient*)malloc(sizeof(struct Patient));  // Aloca mem�ria para o novo paciente
    if (new == NULL) {
        printf("Falha na aloca��o de mem�ria!\n");
        return;
    }

    printf("Digite o nome do paciente (sem espa�os): ");
    scanf("%s", new->name);  // L� o nome do paciente
    printf("Digite a idade do paciente: ");
    scanf("%d", &new->age);   // L� a idade do paciente

    new->prox = NULL;  // Como � o �ltimo paciente, o ponteiro 'prox' � NULL

    if (*start == NULL) {
        // Se a fila estiver vazia, o novo paciente ser� o primeiro e o �ltimo
        *start = new;
        *end = new;
    } else {
        // Se a fila n�o estiver vazia, adiciona o novo paciente ao final
        (*end)->prox = new;
        *end = new;  // Atualiza o ponteiro do final da fila
    }

    printf("Paciente inserido com sucesso na fila.\n");
}

// Fun��o para atender (remover) o paciente da frente da fila
void attendPatient(struct Patient** start, struct Patient** end) {
    if (*start == NULL) {
        printf("Fila vazia! Nenhum paciente para atender.\n");
        return;
    }

    struct Patient* temp = *start;  // Armazena o paciente que ser� atendido
    printf("Atendendo o paciente: %s (idade %d)\n", temp->name, temp->age);

    *start = temp->prox;  // Avan�a o in�cio da fila para o pr�ximo paciente

    if (*start == NULL) {
        // Se a fila ficar vazia ap�s o atendimento, atualiza o fim da fila
        *end = NULL;
    }

    free(temp);  // Libera a mem�ria do paciente atendido
}

// Fun��o para mostrar todos os pacientes na fila
void showRow(struct Patient* start) {
    if (start == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\nFila de pacientes:\n");
    while (start != NULL) {
        printf("%s (idade %d)\n", start->name, start->age);
        start = start->prox;  // Avan�a para o pr�ximo paciente
    }
}

// Fun��o principal com o menu interativo
int main() {
    struct Patient* start = NULL;  // Ponteiro para o in�cio da fila
    struct Patient* end = NULL;    // Ponteiro para o final da fila
    int option;

    do {
        printf("\n=== MENU DA FILA DE PACIENTES ===\n");
        printf("1. Inserir paciente na fila\n");
        printf("2. Atender pr�ximo paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                enqueue(&start, &end);  // Chama a fun��o para inserir paciente na fila
                break;
            case 2:
                attendPatient(&start, &end);  // Chama a fun��o para atender paciente
                break;
            case 3:
                showRow(start);  // Exibe todos os pacientes na fila
                break;
            case 0:
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (option != 0);  // Repete at� o usu�rio escolher sair

    // Libera a mem�ria restante da fila (se houver pacientes)
    while (start != NULL) {
        attendPatient(&start, &end);
    }

    return 0;
}
