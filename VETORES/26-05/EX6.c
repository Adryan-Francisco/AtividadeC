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

// Inicializa a fila: tudo come�a vazio
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

// Teste do funcionamento
int main() {
    struct Fila f;
    inicializarFila(&f);

    // Simula��o de estado inicial: [30] [40] [50], inicio = 2
    enfileirar(&f, 10); // Ser� sobrescrito
    enfileirar(&f, 20); // Ser� sobrescrito
    enfileirar(&f, 30);
    enfileirar(&f, 40);
    enfileirar(&f, 50);

    f.inicio = 2;        // For�ando o in�cio em 2
    f.quantidade = 3;    // Temos 3 elementos: 30, 40, 50
    f.fim = 0;           // Posi��o de inser��o circular

    mostrarFila(&f);

    // Remover todos os elementos
    desenfileirar(&f);
    desenfileirar(&f);
    desenfileirar(&f);

    mostrarFila(&f);

    return 0;
}
