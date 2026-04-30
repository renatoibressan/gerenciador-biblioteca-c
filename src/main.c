#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int qtdLivros = 0, ultimoId = 0, option = -1;
    int temFila = 0, teveEmpilhacao = 0, teveEmprestimo = 0;
    Fila filaEspera;
    inicializarFila(&filaEspera);
    NoPilha *topoHistorico = NULL;
    srand(time(NULL));
    limparTela();
    printf("\n========== SISTEMA GERENCIADOR DE BIBLIOTECA ==========\n");
    printf("Desenvolvido por: Renato Ikeda Bressan\n");
    do {
        exibirMenu();
        option = validarEntradaInteira("Insira uma das opcoes acima: ");
        switch (option) {
            case 1:
                // Cadastro
                cadastrarLivro(&livros, &qtdLivros, &capacidade, &ultimoId);
                int ordenado = 0;
                break;
            case 2:
                // Listagem
                if (!ordenado) {
                    ordenarLivros(&livros, 0, qtdLivros - 1);
                    ordenado = 1;
                }
                listarLivros("Livros listados:", &livros, qtdLivros);
                break;
            case 3:
                // Busca binária
                if (!ordenado) {
                    ordenarLivros(&livros, 0, qtdLivros - 1);
                    ordenado = 1;
                }
                char tituloBusca[151];
                entradaString("Insira o titulo do livro desejado: ", tituloBusca, 151);
                converterMinusculo(tituloBusca);
                int idxLivro = buscarLivroPorNome(&livros, qtdLivros, tituloBusca);
                if (idxLivro == -1) break;
                Livro livroBusca = livros[idxLivro];
                printf("Livro #%04d: %s (Exemplares restantes: %d)\n", livroBusca.id, livroBusca.titulo, livroBusca.qtd);
                break;
            case 4:
                // Acréscimo ao estoque
                if (!ordenado) {
                    ordenarLivros(&livros, 0, qtdLivros - 1);
                    ordenado = 1;
                }
                entradaString("Insira o titulo do livro desejado: ", tituloBusca, 151);
                converterMinusculo(tituloBusca);
                idxLivro = buscarLivroPorNome(&livros, qtdLivros, tituloBusca);
                if (idxLivro == -1) break;
                int aumentoEstoque = validarEntradaInteira("Insira a quantidade de novos livros: ");
                while (aumentoEstoque < 1) {
                    printf("Quantidade invalida!\n");
                    aumentoEstoque = validarEntradaInteira("Insira a quantidade de novos livros: ");
                }
                int qtdAnterior = livros[idxLivro].qtd;
                livros[idxLivro].qtd += aumentoEstoque;
                printf("%d novos exemplares adicionados ao estoque do livro '%s' com sucesso!\n", aumentoEstoque, livros[idxLivro].titulo);
                char nomeFila[151];
                if (qtdAnterior == 0 && temFila && livros[idxLivro].id == filaEspera.inicio->idLivro) {
                    while (!filaVazia(filaEspera.inicio)) {
                        if (teveEmpilhacao && livros[idxLivro].id == topoHistorico->livro.id) desempilharDevolucao(&topoHistorico);
                        removerFila(&filaEspera, nomeFila);
                        if (filaEspera.tam == 0) temFila = 0;
                        livros[idxLivro].qtd--;
                        livros[idxLivro].emprestimos++;
                        teveEmprestimo = 1;
                        printf("Livro '%s' emprestado a %s com sucesso!\n", livros[idxLivro].titulo, nomeFila);
                    }
                }
                break;
            case 5:
                // Empréstimo
                if (!ordenado) {
                    ordenarLivros(&livros, 0, qtdLivros - 1);
                    ordenado = 1;
                }
                entradaString("Insira o nome da pessoa na fila: ", nomeFila, 151);
                converterMaiusculo(nomeFila);
                entradaString("Insira o titulo do livro desejado: ", tituloBusca, 151);
                converterMinusculo(tituloBusca);
                idxLivro = buscarLivroPorNome(&livros, qtdLivros, tituloBusca);
                if (idxLivro == -1) break;
                if (livros[idxLivro].qtd == 0) {
                    printf("Livro '%s' nao disponivel no estoque!\n", livros[idxLivro].titulo);
                    adicionarFila(&filaEspera, nomeFila, livros[idxLivro].id);
                    temFila = 1;
                    break;
                }
                if (teveEmpilhacao && livros[idxLivro].id == topoHistorico->livro.id) desempilharDevolucao(&topoHistorico);
                if (temFila && livros[idxLivro].id == filaEspera.inicio->idLivro) removerFila(&filaEspera, nomeFila);
                if (filaEspera.tam == 0) temFila = 0;
                livros[idxLivro].qtd--;
                livros[idxLivro].emprestimos++;
                teveEmprestimo = 1;
                printf("Livro '%s' emprestado a %s com sucesso!\n", livros[idxLivro].titulo, nomeFila);
                break;
            case 6:
                // Devolução
                if (!teveEmprestimo) {
                    printf("Nao ha livros a serem devolvidos!\n");
                    break;
                }
                if (!ordenado) {
                    ordenarLivros(&livros, 0, qtdLivros - 1);
                    ordenado = 1;
                }
                entradaString("Insira o titulo do livro desejado: ", tituloBusca, 151);
                converterMinusculo(tituloBusca);
                idxLivro = buscarLivroPorNome(&livros, qtdLivros, tituloBusca);
                if (idxLivro == -1) break;
                if (livros[idxLivro].emprestimos == 0) {
                    printf("Nao ha exemplares de '%s' a serem devolvidos!\n", livros[idxLivro].titulo);
                    break;
                }
                empilharDevolucao(&topoHistorico, livros[idxLivro]);
                teveEmpilhacao = 1;
                livros[idxLivro].qtd++;
                livros[idxLivro].emprestimos--;
                printf("Livro '%s' devolvido com sucesso!\n", livros[idxLivro].titulo);
                break;
            case 7:
                // Fila completa
                mostrarFila("Fila de espera:", &filaEspera);
                break;
            case 8:
                // Histórico total
                mostrarHistorico("Historico completo:", topoHistorico);
                break;
            case 0:
                printf("Encerrando programa\n\n");
                break;
            default: printf("Opcao invalida!\n");
        }
    } while (option != 0);
    liberarPilha(&topoHistorico);
    liberarFila(&filaEspera);
    free(livros);
    return 0;
}