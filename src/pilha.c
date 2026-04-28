#include <stdio.h>
#include <stdlib.h>

#include "livros.h"
#include "pilha.h"

void empilharDevolucao(NoPilha **topo, Livro livro) {
    NoPilha *novo = malloc(sizeof(NoPilha));
    if (!novo) {
        printf("Erro de alocacao!\n(Operacao abortada)\n");
        return;
    }
    novo->livro = livro;
    novo->prox = *topo;
    *topo = novo;
}

int desempilharDevolucao(NoPilha **topo, Livro *livro) {
    if (pilhaVazia(*topo)) return 0;
    NoPilha *temp = *topo;
    *livro = temp->livro;
    *topo = (*topo)->prox;
    free(temp);
    return 1;
}

void mostrarHistorico(const char *mensagem, NoPilha *topo) {
    if (pilhaVazia(topo)) {
        printf("Pilha vazia!\n(Operacao abortada)\n");
        return;
    }
    printf("%s\n", mensagem);
    while (topo) {
        printf("[Livro #%00d: %s (Restantes: %d)]\n", topo->livro.id, topo->livro.titulo, topo->livro.qtd);
        topo = topo->prox;
    }
}

int pilhaVazia(NoPilha *topo) {
    return (topo == NULL);
}

void liberarPilha(NoPilha **topo) {
    NoPilha *atual = *topo;
    while (atual) {
        NoPilha *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *topo = NULL;
}