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
    printf("Livro incrementado a pilha com sucesso!\n");
}

void desempilharDevolucao(NoPilha **topo) {
    if (pilhaVazia(*topo)) {
        printf("Pilha vazia!\n(Operacao abortada)\n");
        return;
    }
    NoPilha *temp = *topo;
    *topo = (*topo)->prox;
    free(temp);
    printf("Livro removido da pilha com sucesso!\n");
}

void mostrarHistorico(const char *mensagem, NoPilha *topo) {
    if (pilhaVazia(topo)) {
        printf("Pilha vazia!\n(Operacao abortada)\n");
        return;
    }
    printf("%s\n", mensagem);
    while (topo) {
        printf("[Livro #%04d: %s (Exemplares restantes: %d)]\n", topo->livro.id, topo->livro.titulo, topo->livro.qtd);
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