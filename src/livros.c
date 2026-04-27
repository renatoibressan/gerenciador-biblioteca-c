#include <stdio.h>
#include <stdlib.h>

#include "livros.h"
#include "utils.h"

void criarNovoId(int *ultimoId) {
    *ultimoId = *ultimoId + 1;
}

void cadastrarLivro(Livro **livros, int *qtd, int *capacidade, int *ultimoId) {
    if (*qtd >= *capacidade) {
        *capacidade += 1;
        Livro *temp = realloc(*livros, (*capacidade)*sizeof(Livro));
        if (!temp) {
            printf("Erro de realocacao!\n(Programa abortado)\n");
            return;
        }
        *livros = temp;
    }
    criarNovoId(ultimoId);
    copiaString((*livros)[*qtd].titulo, entradaString("Insira o titulo do livro: "));
    converterMinusculo((*livros)[*qtd].titulo);
    (*livros)[*qtd].qtd = validarEntradaInteira("Insira a quantidade de livros: ");
    while ((*livros)[*qtd].qtd < 1) {
        printf("Quantidade invalida!\n");
        (*livros)[*qtd].qtd = validarEntradaInteira("Insira a quantidade de livros: ");
    }
    (*qtd)++;
    printf("Livro '%s' adicionado com sucesso!\n", (*livros)[*qtd].qtd);
}

void listarLivros(Livro **livros, int qtd) {
}

int buscarLivro(Livro **livros, int qtd, int id) {
}

void ordenarLivrosTitulo(Livro **livros, int qtd) {
}

void ordenarLivrosQuantidade(Livro **livros, int qtd) {
}

int emprestarLivro(Livro **livros, int qtd, int id) {
}

int devolverLivro(Livro **livros, int qtd, int id) {
}