#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct No {
    int valor;
    struct No *anterior;
    struct No *proximo;
};

// Inserir no início
void inserirInicio(struct No **inicio, struct No **fim, int valor) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = novo;
    } else {
        *fim = novo; // lista estava vazia
    }

    *inicio = novo;
    printf("Inserido %d no início.\n", valor);
}

// Inserir no fim
void inserirFim(struct No **inicio, struct No **fim, int valor) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = *fim;

    if (*fim != NULL) {
        (*fim)->proximo = novo;
    } else {
        *inicio = novo; // lista estava vazia
    }

    *fim = novo;
    printf("Inserido %d no fim.\n", valor);
}

// Remover do início
void removerInicio(struct No **inicio, struct No **fim) {
    if (*inicio == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    struct No *temp = *inicio;
    printf("Removendo %d do início.\n", temp->valor);

    *inicio = temp->proximo;
    if (*inicio != NULL) {
        (*inicio)->anterior = NULL;
    } else {
        *fim = NULL; // lista ficou vazia
    }

    free(temp);
}

// Remover do fim
void removerFim(struct No **inicio, struct No **fim) {
    if (*fim == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    struct No *temp = *fim;
    printf("Removendo %d do fim.\n", temp->valor);

    *fim = temp->anterior;
    if (*fim != NULL) {
        (*fim)->proximo = NULL;
    } else {
        *inicio = NULL; // lista ficou vazia
    }

    free(temp);
}

// Mostrar do início ao fim
void mostrarInicioAoFim(struct No *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista do início ao fim: ");
    while (inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

// Mostrar do fim ao início
void mostrarFimAoInicio(struct No *fim) {
    if (fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista do fim ao início: ");
    while (fim != NULL) {
        printf("%d ", fim->valor);
        fim = fim->anterior;
    }
    printf("\n");
}

// Função principal com menu
int main() {
    struct No *inicio = NULL;
    struct No *fim = NULL;
    int opcao, valor;

    do {
        printf("\n===== MENU LISTA DUPLAMENTE ENCADEADA =====\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do início\n");
        printf("4. Remover do fim\n");
        printf("5. Mostrar do início ao fim\n");
        printf("6. Mostrar do fim ao início\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirInicio(&inicio, &fim, valor);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirFim(&inicio, &fim, valor);
                break;
            case 3:
                removerInicio(&inicio, &fim);
                break;
            case 4:
                removerFim(&inicio, &fim);
                break;
            case 5:
                mostrarInicioAoFim(inicio);
                break;
            case 6:
                mostrarFimAoInicio(fim);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    // Liberar memória restante
    while (inicio != NULL) {
        struct No *temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }

    return 0;
}
