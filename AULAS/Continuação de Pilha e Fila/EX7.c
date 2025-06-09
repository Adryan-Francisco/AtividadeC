#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Tamanho m�ximo da fila

// Estrutura da fila circular
struct Fila {
    int dados[TAM];   // Vetor que armazena os elementos
    int inicio;       // �ndice do primeiro elemento (onde remove)
    int fim;          // �ndice do pr�ximo espa�o livre (onde insere)
    int quantidade;   // N�mero de elementos atualmente na fila
};

// Inicializa a fila
void inicializarFila(struct Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

// Verifica se a fila est� cheia
int filaCheia(struct Fila *f) {
    return f->quantidade == TAM;
}

// Verifica se a fila est� vazia
int filaVazia(struct Fila *f) {
    return f->quantidade == 0;
}

// Inserir elemento no fim da fila
void enfileirar(struct Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia! N�o � poss�vel inserir.\n");
        return;
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM;
    f->quantidade++;
    printf("Elemento %d inserido com sucesso.\n", valor);
}

// Remover elemento do in�cio da fila
void desenfileirar(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nada para remover.\n");
        return;
    }

    int removido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->quantidade--;
    printf("Elemento %d removido da fila.\n", removido);
}

// Mostrar a fila do in�cio ao fim
void mostrarFila(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila atual: ");
    int i = f->inicio;
    int count = 0;

    while (count < f->quantidade) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % TAM;
        count++;
    }

    printf("\n");
}

// Fun��o principal com menu
int main() {
    struct Fila fila;
    inicializarFila(&fila); // Inicializa a fila

    int opcao, valor;

    do {
        printf("\n===== MENU FILA CIRCULAR COM VETOR =====\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                break;

            case 2:
                desenfileirar(&fila);
                break;

            case 3:
                mostrarFila(&fila);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
