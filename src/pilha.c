#include <stdio.h>
#include <stdlib.h>

#include "livros.h"
#include "pilha.h"

void empilharDevolucao(NoPilha **topo, Livro livro) {
    NoPilha *novo = malloc(sizeof(NoPilha));
    if (!novo) {
        printf("Memoria cheia!\n(Operacao abortada)\n");
        return;
    }
    novo->livro = livro;
    novo->prox = *topo;
    *topo = novo;
}

int desempilharDevolucao(NoPilha **topo, Livro *livroRemovido) {
    if (pilhaVazia(*topo)) return 0;
    NoPilha *temp = *topo;
    *livroRemovido = temp->livro;
    *topo = (*topo)->prox;
    free(temp);
    return 1;
}

void mostrarHistorico(const char *mensagem, NoPilha *topo) {
    printf("%s\n", mensagem);
    while (topo) {
        printf("[Livro #%d: %s (Restantes: %d)]\n");
        topo = topo->prox;
    }
}

int pilhaVazia(NoPilha *topo) {
    return (topo == NULL);
}