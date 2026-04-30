#ifndef LIVROS_H
#define LIVROS_H

typedef struct {
    int id;
    char titulo[151];
    int qtd;
    int emprestimos;
} Livro;

int criarNovoId(int *ultimoId);
void cadastrarLivro(Livro **livros, int *qtd, int *capacidade, int *ultimoId);
void trocarLivros(Livro *livro1, Livro *livro2);
int particaoVetor(Livro **livros, int inicio, int fim);
void ordenarLivros(Livro **livros, int inicio, int fim);
void listarLivros(const char *mensagem, Livro **livros, int qtd);
int buscarLivroPorNome(Livro **livros, int qtd, const char *titulo);

#endif