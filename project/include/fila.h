#ifndef FILA_H
#define FILA_H

typedef struct NoFila {
    char nome[151];
    int idLivro;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
    int tam;
} Fila;

void inicializarFila(Fila *fila);
void adicionarFila(Fila *fila, char *nome, int idLivro);
void removerFila(Fila *fila, char *nome);
void mostrarFila(const char *mensagem, Fila *fila);
int filaVazia(NoFila *inicio);
void liberarFila(Fila *fila);

#endif