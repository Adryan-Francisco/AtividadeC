#include <stdio.h>
#include <stdlib.h>

struct Livro {
    char titulo[50];
    int paginas;
};

int main() {
    struct Livro *livros;
    int i; // <- declaração da variável fora do for

    livros = malloc(2 * sizeof(struct Livro));
    if (livros == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for (i = 0; i < 2; i++) {
        printf("Livro %d\n", i + 1);
        printf("Título: ");
        scanf(" %[^\n]", livros[i].titulo);
        printf("Páginas: ");
        scanf(" %d", &livros[i].paginas);
    }

    for (i = 0; i < 2; i++) {
        printf("Livro %d: %s - %d páginas\n", i + 1, livros[i].titulo, livros[i].paginas);
    }

    free(livros);
    return 0;
}
