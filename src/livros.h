typedef struct {
    int id;
    char titulo[100];
    int qtd;
} Livro;

void cadastrarLivro(Livro livros[], int *qtd);
void listarLivros(Livro livros[], int qtd);
int buscarLivro(Livro livros[], int qtd, int id);
void ordenarLivrosTitulo(Livro livros[], int qtd);
void ordenarLivrosQuantidade(Livro livros[], int qtd);
int emprestarLivro(Livro livros[], int qtd, int id);
int devolverLivro(Livro livros[], int qtd, int id);