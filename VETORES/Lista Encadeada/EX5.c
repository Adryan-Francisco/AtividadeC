#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct No {
    int value;
    struct No *prox;
};

// Função para inserir no final da lista
struct No* inserirNoFim(struct No *head, int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    novo->value = valor;
    novo->prox = NULL;

    if (head == NULL) return novo;

    struct No *atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;

    return head;
}

// Função para imprimir a lista
void imprimirlista(struct No *head) {
    struct No *atual = head;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->value);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para buscar um elemento na lista
struct No* buscarElemento(struct No *head, int valorBusca) {
    struct No *atual = head;

    while (atual != NULL) {
        if (atual->value == valorBusca) {
            return atual; // Retorna o ponteiro para o nó encontrado
        }
        atual = atual->prox;
    }

    return NULL; // Valor não encontrado
}

// Função principal
int main() {
    struct No *lista = NULL;

    // Criando a lista: 10 -> 20 -> 30 -> NULL
    lista = inserirNoFim(lista, 10);
    lista = inserirNoFim(lista, 20);
    lista = inserirNoFim(lista, 30);

    // Imprimir a lista
    imprimirlista(lista);

    // Buscar o valor 20
    struct No *resultado = buscarElemento(lista, 20);
    if (resultado != NULL) {
        printf("Valor %d encontrado no endereço %p.\n", resultado->value, (void*)resultado);
    } else {
        printf("Valor 20 não encontrado.\n");
    }

    // Buscar um valor inexistente (99)
    resultado = buscarElemento(lista, 99);
    if (resultado != NULL) {
        printf("Valor %d encontrado no endereço %p.\n", resultado->value, (void*)resultado);
    } else {
        printf("Valor 99 não encontrado.\n");
    }

    return 0;
}
