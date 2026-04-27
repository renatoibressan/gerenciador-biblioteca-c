#include "livros.h"

typedef struct NoPilha {
    Livro livro;
    struct NoPilha *prox;
} NoPilha;

void empilharDevolucao(NoPilha **topo, Livro livro);
int desempilharDevolucao(NoPilha **topo, Livro *livroRemovido);
void mostrarHistorico(NoPilha *topo);
int pilhaVazia(NoPilha *topo);