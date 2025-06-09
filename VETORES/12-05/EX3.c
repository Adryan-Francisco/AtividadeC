#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct No {
    int valor;
    struct No *prox;
};

// Função para inserir no final da lista
struct No* inserirNoFim(struct No* head, int valor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->prox = NULL;

    if (head == NULL) {
        return novo;
    }

    struct No* atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;

    return head;
}

// Função para imprimir a lista
void imprimirLista(struct No* head) {
    struct No* atual = head;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para remover um elemento da lista
struct No* removerElemento(struct No* head, int valorRemover) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    // Caso o valor esteja no primeiro nó
    if (head->valor == valorRemover) {
        struct No* temp = head;
        head = head->prox;
        free(temp);
        return head;
    }

    // Procurar o valor na lista
    struct No* anterior = head;
    struct No* atual = head->prox;

    while (atual != NULL && atual->valor != valorRemover) {
        anterior = atual;
        atual = atual->prox;
    }

    // Valor não encontrado
    if (atual == NULL) {
        printf("Valor %d não encontrado na lista.\n", valorRemover);
        return head;
    }

    // Remover o nó
    anterior->prox = atual->prox;
    free(atual);

    return head;
}

// Função principal
int main() {
    struct No* lista = NULL;

    // Criar a lista: [10 -> 20 -> 30 -> 40]
    lista = inserirNoFim(lista, 10);
    lista = inserirNoFim(lista, 20);
    lista = inserirNoFim(lista, 30);
    lista = inserirNoFim(lista, 40);

    imprimirLista(lista); // Deve imprimir: 10 -> 20 -> 30 -> 40 -> NULL

    // Remover o valor 30
    lista = removerElemento(lista, 30);
    imprimirLista(lista); // Deve imprimir: 10 -> 20 -> 40 -> NULL

    // Tentar remover valor inexistente (99)
    lista = removerElemento(lista, 99);

    // Remover o primeiro elemento (10)
    lista = removerElemento(lista, 10);
    imprimirLista(lista); // Deve imprimir: 20 -> 40 -> NULL

    return 0;
}
