#include <stdio.h>

struct Aluno {
    char nome[40];
    float nota;
};

int main() {
    struct Aluno aluno;
    struct Aluno *pAluno = &aluno;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", pAluno->nome);

    printf("Digite a nota do aluno: ");
    scanf("%f", &pAluno->nota);

    printf("Aluno: %s\n", pAluno->nome);
    printf("Nota: %.2f\n", pAluno->nota);

    return 0;
}
