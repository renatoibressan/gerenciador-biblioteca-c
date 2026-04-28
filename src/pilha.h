#ifndef PILHA_H
#define PILHA_H

#include "livros.h"

typedef struct NoPilha {
    Livro livro;
    struct NoPilha *prox;
} NoPilha;

void empilharDevolucao(NoPilha **topo, Livro livro);
int desempilharDevolucao(NoPilha **topo, Livro *livro);
void mostrarHistorico(const char *mensagem, NoPilha *topo);
int pilhaVazia(NoPilha *topo);
void liberarPilha(NoPilha **topo);

#endif