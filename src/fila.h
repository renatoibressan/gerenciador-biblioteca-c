typedef struct NoFila {
    char nome[100];
    struct NoFila *prox;
} NoFila;

void adicionarFila(NoFila **inicio, NoFila **fim, char nome[]);
int removerFila(NoFila **inicio, NoFila **fim, char nomeRemovido[]);
void mostrarFila(NoFila *inicio);
int filaVazia(NoFila *inicio);