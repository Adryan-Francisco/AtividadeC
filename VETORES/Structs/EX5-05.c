#include <stdio.h>
#include <stdlib.h>

struct Livro {
    char titulo[50];
    int paginas;
};

int main() {
    struct Livro *livros;
    int i; // <- declara��o da vari�vel fora do for

    livros = malloc(2 * sizeof(struct Livro));
    if (livros == NULL) {
        printf("Erro na aloca��o de mem�ria!\n");
        return 1;
    }

    for (i = 0; i < 2; i++) {
        printf("Livro %d\n", i + 1);
        printf("T�tulo: ");
        scanf(" %[^\n]", livros[i].titulo);
        printf("P�ginas: ");
        scanf(" %d", &livros[i].paginas);
    }

    for (i = 0; i < 2; i++) {
        printf("Livro %d: %s - %d p�ginas\n", i + 1, livros[i].titulo, livros[i].paginas);
    }

    free(livros);
    return 0;
}
