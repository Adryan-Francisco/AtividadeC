#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do n� da fila
struct No {
    int value;
    struct No* prox;
};

// Fun��o para enfileirar (enqueue): insere no final da fila
void enqueue(struct No** inicio, struct No** fim, int value) {
    struct No* novo = (struct No*)malloc(sizeof(struct No)); // Aloca o novo n�
    if (novo == NULL) {
        printf("Falha na aloca��o de mem�ria!\n");
        return;
    }

    novo->value = value; // Atribui o valor ao novo n�
    novo->prox = NULL;   // O pr�ximo n� ser� NULL, j� que � o �ltimo n� da fila

    if (*fim == NULL) {
        // Se a fila estiver vazia, o novo n� ser� tanto o in�cio quanto o fim
        *inicio = novo;
        *fim = novo;
    } else {
        // Caso contr�rio, o fim atual vai apontar para o novo n�
        (*fim)->prox = novo;
        *fim = novo; // Atualiza o fim da fila
    }
}

// Fun��o para desenfileirar (dequeue): remove o n� do in�cio da fila
int dequeue(struct No** inicio, struct No** fim) {
    if (*inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }

    struct No* temp = *inicio;  // Armazena o n� que ser� removido
    int valor = temp->value;     // Armazena o valor para retornar

    *inicio = temp->prox; // Avan�a o in�cio da fila

    // Se a fila ficar vazia, atualiza o fim tamb�m
    if (*inicio == NULL) {
        *fim = NULL;
    }

    free(temp); // Libera a mem�ria do n� removido
    return valor;
}

// Fun��o para consultar o in�cio da fila (peek): retorna o valor sem remover
int peek(struct No* inicio) {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    return inicio->value;
}

// Fun��o para imprimir a fila
void printQueue(struct No* inicio) {
    printf("In�cio da fila\n");
    while (inicio != NULL) {
        printf("%d -> ", inicio->value);
        inicio = inicio->prox; // Avan�a para o pr�ximo n�
    }
    printf("NULL (fim)\n");
}

// Fun��o principal
int main() {
    struct No* inicio = NULL; // Ponteiro para o in�cio da fila
    struct No* fim = NULL;    // Ponteiro para o fim da fila

    // Enfileirando tr�s elementos
    enqueue(&inicio, &fim, 10);
    enqueue(&inicio, &fim, 20);
    enqueue(&inicio, &fim, 30);

    // Mostra a fila atual
    printQueue(inicio);

    // Consulta o primeiro elemento (peek)
    printf("In�cio da fila (peek): %d\n", peek(inicio));

    // Remove um elemento da fila
    int removed = dequeue(&inicio, &fim);
    printf("Desenfileirado: %d\n", removed);

    // Mostra a fila ap�s a remo��o
    printQueue(inicio);

    return 0;
}
