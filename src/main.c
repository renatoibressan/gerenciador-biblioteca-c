#include <stdio.h>
#include <stdlib.h>

#include "livros.h"
#include "fila.h"
#include "pilha.h"
#include "utils.h"

int main() {
    Livro *livros = NULL;
    int capacidade = 10;
    livros = malloc(capacidade*sizeof(Livro));
    if (!livros) {
        printf("Erro de alocacao!\n(Programa abortado)\n");
        return 1;
    }
    int qtdLivros = 0;
    int ultimoId = 0;
    Fila filaEspera;
    NoPilha *topoHistorico = NULL;
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
            case 2:
                listarLivros("Livros listados:", &livros, qtdLivros);
                break;
            case 3:
                int checkup = 0;
                char tituloBusca[151];
                entradaString("Insira o titulo do livro desejado: ", tituloBusca, 151);
                int idxLivro = buscarLivro(&livros, qtdLivros, tituloBusca, &checkup);
                if (idxLivro == -1) {
                    (checkup) ? printf("A lista de livros esta vazia!\n\n") : printf("O livro '%s' nao foi encontrado!\n", tituloBusca);
                } else {
                    Livro livroBusca = livros[idxLivro];
                    printf("Livro #%00d: %s (Restantes: %d)\n", livroBusca.id, livroBusca.titulo, livroBusca.qtd);
                }
                break;
            case 4:
                // Empréstimo
                break;
            case 5:
                // Devolução
                break;
            case 6:
                mostrarFila("Fila de espera:", &filaEspera);
                break;
            case 7:
                mostrarHistorico("Historico completo:", topoHistorico);
                break;
            case 0:
                printf("Encerrando programa\n");
                flag = 1;
                break;
            default: printf("Opcao invalida!\n");
        }
        if (flag) break;
    }
    liberarPilha(&topoHistorico);
    liberarFila(&filaEspera);
    free(livros);
    return 0;
}