typedef struct NoFila {
    char nome[151];
    struct NoFila *prox;
} NoFila;

void adicionarFila(NoFila **inicio, NoFila **fim, char *nome);
int removerFila(NoFila **inicio, NoFila **fim, char *nomeRemovido);
void mostrarFila(const char *mensagem, NoFila *inicio);
int filaVazia(NoFila *inicio);