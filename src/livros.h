#ifndef LIVROS_H
#define LIVROS_H

typedef struct {
    int id;
    char titulo[151];
    int qtd;
} Livro;

int criarNovoId(int *ultimoId);
void cadastrarLivro(Livro **livros, int *qtd, int *capacidade, int *ultimoId);
void trocarLivros(Livro *livro1, Livro *livro2);
int particaoVetor(Livro **livros, int inicio, int fim);
void ordenarLivros(Livro **livros, int inicio, int fim);
void listarLivros(const char *mensagem, Livro **livros, int qtd);
int buscarLivro(Livro **livros, int qtd, const char *titulo, int *checkup);
int emprestarLivro(Livro **livros, int qtd, int id);
int devolverLivro(Livro **livros, int qtd, int id);

#endif