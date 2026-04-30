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
    (*livros)[*qtd].qtd = validarEntradaInteira("Insira a quantidade de exemplares: ");
    while ((*livros)[*qtd].qtd < 1) {
        printf("Quantidade invalida!\n");
        (*livros)[*qtd].qtd = validarEntradaInteira("Insira a quantidade de livros: ");
    }
    (*livros)[*qtd].emprestimos = 0;
    printf("Livro '%s' adicionado com sucesso!\n", (*livros)[*qtd].titulo);
    (*qtd)++;
}

void trocarLivros(Livro *livro1, Livro *livro2) {
    Livro temp = *livro1;
    *livro1 = *livro2;
    *livro2 = temp;
}

int particaoVetor(Livro **livros, int inicio, int fim) {
    int posPivo = inicio + rand() % (fim - inicio + 1);
    trocarLivros(&(*livros)[posPivo], &(*livros)[fim]);
    Livro pivo = (*livros)[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (comparaString((*livros)[j].titulo, pivo.titulo) < 0) {
            i++;
            trocarLivros(&(*livros)[i], &(*livros)[j]);
        }
    }
    trocarLivros(&(*livros)[i + 1], &(*livros)[fim]);
    return i + 1;
}

void ordenarLivros(Livro **livros, int inicio, int fim) {
    if (inicio < fim) {
        int p = particaoVetor(livros, inicio, fim);
        ordenarLivros(livros, inicio, p - 1);
        ordenarLivros(livros, p + 1, fim);
    }
    return;
}

void listarLivros(const char *mensagem, Livro **livros, int qtd) {
    if (!(*livros) || qtd == 0) {
        printf("Nao ha livros a serem listados!\n");
        return;
    }
    printf("%s\n", mensagem);
    for (int i = 0; i < qtd; i++) {
        printf("Livro #%04d: %s (Exemplares restantes: %d)\n", (*livros)[i].id, (*livros)[i].titulo, (*livros)[i].qtd);
    }
}

int buscarLivroPorNome(Livro **livros, int qtd, const char *titulo) {
    if (!(*livros) || qtd == 0) {
        printf("A lista de livros esta vazia!\n");
        return -1;
    }
    int esq = 0, dir = qtd - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        int res = comparaString((*livros)[meio].titulo, titulo);
        if (res == 0) return meio;
        if (res < 0) esq = meio + 1;
        if (res > 0) dir = meio - 1;
    }
    printf("O livro nao foi encontrado!\n");
    return -1;
}