typedef struct {
    int id;
    char titulo[151];
    int qtd;
} Livro;

void criarNovoId(int *ultimoId);
void cadastrarLivro(Livro **livros, int *qtd, int *capacidade, int *ultimoId);
void listarLivros(Livro **livros, int qtd);
int buscarLivro(Livro **livros, int qtd, int id);
void ordenarLivrosTitulo(Livro **livros, int qtd);
void ordenarLivrosQuantidade(Livro **livros, int qtd);
int emprestarLivro(Livro **livros, int qtd, int id);
int devolverLivro(Livro **livros, int qtd, int id);