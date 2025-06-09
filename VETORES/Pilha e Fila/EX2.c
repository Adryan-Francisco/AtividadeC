#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da fila
struct No {
    int value;
    struct No* prox;
};

// Função para enfileirar (enqueue): insere no final da fila
void enqueue(struct No** inicio, struct No** fim, int value) {
    struct No* novo = (struct No*)malloc(sizeof(struct No)); // Aloca o novo nó
    if (novo == NULL) {
        printf("Falha na alocação de memória!\n");
        return;
    }

    novo->value = value; // Atribui o valor ao novo nó
    novo->prox = NULL;   // O próximo nó será NULL, já que é o último nó da fila

    if (*fim == NULL) {
        // Se a fila estiver vazia, o novo nó será tanto o início quanto o fim
        *inicio = novo;
        *fim = novo;
    } else {
        // Caso contrário, o fim atual vai apontar para o novo nó
        (*fim)->prox = novo;
        *fim = novo; // Atualiza o fim da fila
    }
}

// Função para desenfileirar (dequeue): remove o nó do início da fila
int dequeue(struct No** inicio, struct No** fim) {
    if (*inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }

    struct No* temp = *inicio;  // Armazena o nó que será removido
    int valor = temp->value;     // Armazena o valor para retornar

    *inicio = temp->prox; // Avança o início da fila

    // Se a fila ficar vazia, atualiza o fim também
    if (*inicio == NULL) {
        *fim = NULL;
    }

    free(temp); // Libera a memória do nó removido
    return valor;
}

// Função para consultar o início da fila (peek): retorna o valor sem remover
int peek(struct No* inicio) {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    return inicio->value;
}

// Função para imprimir a fila
void printQueue(struct No* inicio) {
    printf("Início da fila\n");
    while (inicio != NULL) {
        printf("%d -> ", inicio->value);
        inicio = inicio->prox; // Avança para o próximo nó
    }
    printf("NULL (fim)\n");
}

// Função principal
int main() {
    struct No* inicio = NULL; // Ponteiro para o início da fila
    struct No* fim = NULL;    // Ponteiro para o fim da fila

    // Enfileirando três elementos
    enqueue(&inicio, &fim, 10);
    enqueue(&inicio, &fim, 20);
    enqueue(&inicio, &fim, 30);

    // Mostra a fila atual
    printQueue(inicio);

    // Consulta o primeiro elemento (peek)
    printf("Início da fila (peek): %d\n", peek(inicio));

    // Remove um elemento da fila
    int removed = dequeue(&inicio, &fim);
    printf("Desenfileirado: %d\n", removed);

    // Mostra a fila após a remoção
    printQueue(inicio);

    return 0;
}
