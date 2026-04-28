#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void exibirMenu() {
    printf("\n===== BIBLIOTECA =====\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Listar livros\n");
    printf("3 - Buscar livro\n");
    printf("4 - Emprestar livro\n");
    printf("5 - Devolver livro\n");
    printf("6 - Ver fila\n");
    printf("7 - Ver historico\n");
    printf("0 - Sair\n\n");
}

void limparBuffer() {
    while (getchar() != '\n');
}

int validarEntradaInteira(const char *mensagem) {
    printf("%s", mensagem);
    int valor;
    while (scanf("%d", &valor) != 1) {
        printf("Entrada inválida!\n%s", mensagem);
        limparBuffer();
    }
    limparBuffer();
    return valor;
}

void entradaString(const char *mensagem, char *destino, int tamanho) {
    printf("%s", mensagem);
    fgets(destino, tamanho, stdin);
    destino[segmentoString(destino, "\n")] = '\0';
}

void converterMinusculo(char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') texto[i] += 32;
    }
}

int comparaString(const char *A, const char *B) {
    int i = 0;
    while (A[i] == B[i] && A[i] != '\0' && B[i] != '\0') i++;
    return A[i] - B[i];
}

void copiaString(char *destino, char const *fonte) {
    int i = 0;
    while(fonte[i] != '\0') {
        destino[i] = fonte[i];
        i++;
    }
    destino[i] = '\0';
}

int segmentoString(const char *A, const char *B) {
    for (int i = 0; A[i] != '\0'; i++) {
        for (int j = 0; B[j] != '\0'; j++) {
            if (B[j] == A[i]) return i;
        }
    }
    return -1;
}