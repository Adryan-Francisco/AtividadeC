#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma p�gina
struct Pagina {
    char url[100];       // URL da p�gina
    struct Pagina* prox; // Ponteiro para a pr�xima p�gina (lista encadeada)
};

// Fun��o para acessar uma nova p�gina (push)
void acessarPagina(struct Pagina** topo, const char* endereco) {
    struct Pagina* nova = (struct Pagina*)malloc(sizeof(struct Pagina)); // Aloca mem�ria para a nova p�gina
    if (nova == NULL) {
        printf("Falha na aloca��o de mem�ria!\n");
        return;
    }

    strcpy(nova->url, endereco); // Copia o endere�o da URL para a nova p�gina
    nova->prox = *topo;          // Aponta para a p�gina anterior (topo da pilha)
    *topo = nova;                // Atualiza o topo da pilha para a nova p�gina
}

// Fun��o para voltar � p�gina anterior (pop)
void voltarPagina(struct Pagina** topo) {
    if (*topo == NULL) {
        printf("N�o h� p�gina para voltar.\n");
        return;
    }

    struct Pagina* temp = *topo; // Armazena o topo atual
    printf("Voltando da p�gina: %s\n", temp->url);

    *topo = temp->prox; // Atualiza o topo para a p�gina anterior
    free(temp);         // Libera a mem�ria da p�gina removida
}

// Fun��o para mostrar a p�gina atual
void mostrarPaginaAtual(struct Pagina* topo) {
    if (topo == NULL) {
        printf("Nenhuma p�gina aberta.\n");
    } else {
        printf("P�gina atual: %s\n", topo->url);
    }
}

// Fun��o para mostrar o hist�rico (todas as p�ginas na pilha)
void mostrarHistorico(struct Pagina* topo) {
    if (topo == NULL) {
        printf("Hist�rico vazio.\n");
        return;
    }

    printf("Hist�rico das p�ginas visitadas:\n");
    while (topo != NULL) {
        printf("%s\n", topo->url);
        topo = topo->prox; // Move para a pr�xima p�gina no hist�rico
    }
}

int main() {
    struct Pagina* pilha = NULL; // Pilha de p�ginas (inicializa com NULL)
    int opcao;
    char url[100];

    do {
        printf("\n==== MENU DO NAVEGADOR ====\n");
        printf("1. Acessar nova p�gina\n");
        printf("2. Voltar � p�gina anterior\n");
        printf("3. Ver p�gina atual\n");
        printf("4. Mostrar hist�rico\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                printf("Digite a URL da nova p�gina: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = '\0'; // Remove o caractere '\n' do final
                acessarPagina(&pilha, url);
                break;

            case 2:
                voltarPagina(&pilha);
                break;

            case 3:
                mostrarPaginaAtual(pilha);
                break;

            case 4:
                mostrarHistorico(pilha);
                break;

            case 0:
                printf("Saindo do navegador...\n");
                break;

            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }

    } while (opcao != 0);

    // Libera a mem�ria restante (pilha inteira)
    while (pilha != NULL) {
        voltarPagina(&pilha);
    }

    return 0;
}
