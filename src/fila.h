typedef struct NoFila {
    char nome[151];
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
    int tam;
} Fila;

void adicionarFila(Fila *fila, char *nome);
int removerFila(Fila *fila, char *nomeRemovido);
void mostrarFila(const char *mensagem, Fila *fila);
int filaVazia(Fila *fila);