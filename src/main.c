#include <stdio.h>
#include <stdlib.h>

#include "livros.h"
#include "fila.h"
#include "pilha.h"
#include "utils.h"

int main() {
    Livro *livros = NULL;
    int qtdLivros = 0;
    int capacidade = 1;
    int ultimoId = 0;
    livros = malloc(capacidade*sizeof(Livro));
    if (!livros) {
        printf("Erro de alocacao!\n(Programa abortado)\n");
        return 1;
    }
    NoPilha *topoHistorico;
    Fila filaEspera;
    while (1) {
        exibirMenu();
        int flag = 0;
        int option = validarEntradaInteira("Insira uma das opcoes acima: ");
        while (option < 0 || option > 8) {
            printf("Opcao invalida!\n");
            option = validarEntradaInteira("Insira uma das opcoes acima: ");
        }
        switch (option) {
            case 1:
                cadastrarLivro(&livros, &qtdLivros, &capacidade, &ultimoId);
                break;
            case 0:
                printf("Encerrando programa\n");
                flag = 1;
                break;
            default: printf("Opcao invalida!\n");
        }
        if (flag) break;
    }
    free(livros);
    return 0;
}