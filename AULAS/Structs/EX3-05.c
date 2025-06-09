#include <stdio.h>

struct Produto {
    char nome[40];
    float preco;
};

int main() {
    struct Produto produtos[3];
    struct Produto *p = produtos;
    int i;

    for (i = 0; i < 3; i++) {
        printf("Produto %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", (p + i)->nome);
        printf("Preço: ");
        scanf(" %f", &(p + i)->preco); 
    }

    printf("\nProduto 3: %s - R$ %.2f\n", (p + 2)->nome, (p + 2)->preco);

    return 0;
}
