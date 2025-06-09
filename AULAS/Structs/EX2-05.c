#include <stdio.h>

struct Aluno {
    char nome[40];
    float nota;
};

int main() {
    struct Aluno a1;
    struct Aluno *ptr = &a1;

    printf("Digite o nome: ");
    scanf(" %[^\n]", ptr->nome);

    printf("Digite a nota: ");
    scanf("%f", &ptr->nota);

    printf("Nome: %s\n", ptr->nome);
    printf("Nota: %.2f\n", ptr->nota);
   return 0;
}
