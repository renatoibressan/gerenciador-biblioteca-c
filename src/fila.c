#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "utils.h"

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void adicionarFila(Fila *fila, char *nome) {
    NoFila *novo = malloc(sizeof(NoFila));
    if (!novo) {
        printf("Erro de alocacao!\n(Operacao abortada)\n");
        return;
    }
    copiaString(novo->nome, nome);
    novo->prox = NULL;
    if (filaVazia(fila->inicio)) fila->inicio = novo;
    else fila->fim->prox = novo;
    fila->fim = novo;
    fila->tam++;
}

void removerFila(Fila *fila, char *nome) {
    if (filaVazia(fila->inicio)) {
        printf("Fila vazia!\n(Operacao abortada)\n");
        return;
    }
    NoFila *temp = fila->inicio;
    copiaString(nome, temp->nome);
    fila->inicio = fila->inicio->prox;
    if (filaVazia(fila->inicio)) fila->fim = NULL;
    free(temp);
    fila->tam--;
}

void mostrarFila(const char *mensagem, Fila *fila) {
    if (filaVazia(fila->inicio)) {
        printf("Fila vazia!\n(Operacao abortada)\n");
        return;
    }
    int i = 1;
    NoFila *atual = fila->inicio;
    printf("%s\n", mensagem);
    while (atual) {
        printf("Posicao #%00d: %s\n", atual->nome);
        atual = atual->prox;
        i++;
    }
}

int filaVazia(NoFila *inicio) {
    return (inicio == NULL);
}

void liberarFila(Fila *fila) {
    NoFila *atual = fila->inicio;
    while (atual) {
        NoFila *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}