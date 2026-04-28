#include <stdio.h>
#include <stdlib.h>

#include "livros.h"
#include "utils.h"

int criarNovoId(int *ultimoId) {
    *ultimoId = *ultimoId + 1;
    return *ultimoId;
}

void cadastrarLivro(Livro **livros, int *qtd, int *capacidade, int *ultimoId) {
    if (*qtd >= *capacidade) {
        *capacidade *= 2;
        Livro *temp = realloc(*livros, (*capacidade)*sizeof(Livro));
        if (!temp) {
            printf("Erro de realocacao!\n(Programa abortado)\n");
            return;
        }
        *livros = temp;
    }
    (*livros)[*qtd].id = criarNovoId(ultimoId);
    entradaString("Insira o titulo do livro: ", (*livros)[*qtd].titulo, 151);
    converterMinusculo((*livros)[*qtd].titulo);
    (*livros)[*qtd].qtd = validarEntradaInteira("Insira a quantidade de livros: ");
    while ((*livros)[*qtd].qtd < 1) {
        printf("Quantidade invalida!\n");
        (*livros)[*qtd].qtd = validarEntradaInteira("Insira a quantidade de livros: ");
    }
    printf("Livro '%s' adicionado com sucesso!\n", (*livros)[*qtd].titulo);
    (*qtd)++;
}

void trocarLivros(Livro *livro1, Livro *livro2) {
    Livro temp = *livro1;
    *livro1 = *livro2;
    *livro2 = temp;
}

void ordenarLivros(Livro **livros, int inicio, int fim) {
    if (inicio >= fim) return;
    Livro pivo = (*livros)[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (comparaString((*livros)[j].titulo, pivo.titulo) < 0) {
            i++;
            trocarLivros(&(*livros)[i], &(*livros)[j]);
        }
    }
    trocarLivros(&(*livros)[i + 1], &(*livros)[fim]);
    int posPivo = i + 1;
    ordenarLivros(livros, inicio, posPivo - 1);
    ordenarLivros(livros, posPivo + 1, fim);
}

void listarLivros(const char *mensagem, Livro **livros, int qtd) {
    if (!(*livros) || qtd == 0) {
        printf("Nao ha livros a serem listados!\n");
        return;
    }
    ordenarLivros(livros, 0, qtd - 1);
    printf("%s\n", mensagem);
    for (int i = 0; i < qtd; i++) {
        printf("Livro #%00d: %s (Restantes: %d)\n", (*livros)[i].id, (*livros)[i].titulo, (*livros)[i].qtd);
    }
}

int buscarLivro(Livro **livros, int qtd, const char *titulo, int *checkup) {
    if (!(*livros) || qtd == 0) {
        *checkup = 1;
        return -1;
    }
    ordenarLivros(livros, 0, qtd - 1);
    int esq = 0, dir = qtd - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        int res = comparaString((*livros)[meio].titulo, titulo);
        if (res == 0) return meio;
        if (res < 0) esq = meio + 1;
        if (res > 0) dir = meio - 1;
    }
    *checkup = 0;
    return -1;
}

int emprestarLivro(Livro **livros, int qtd, int id) {
}

int devolverLivro(Livro **livros, int qtd, int id) {
}