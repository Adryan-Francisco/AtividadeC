#include <stdio.h>

struct Pessoa {
    char nome[40];
    float altura;
};

void atualizarAltura(struct Pessoa *p) {
    p->altura *= 1.10;
}

int main() {
    struct Pessoa pessoa = {"Carlos", 1.70};

    printf("Antes: %.2f m\n", pessoa.altura);
    atualizarAltura(&pessoa);
    printf("Depois: %.2f m\n", pessoa.altura);

    return 0;
}
