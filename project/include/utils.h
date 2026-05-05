#ifndef UTILS_H
#define UTILS_H

void limparTela();
void exibirMenu();
void limparBuffer();
int validarEntradaInteira(const char *mensagem);
void entradaString(const char *mensagem, char *destino, int tamanho);
void converterMaiusculo(char *texto);
void converterMinusculo(char *texto);
int comparaString(const char *A, const char *B);
void copiaString(char *destino, char const *fonte);
int segmentoString(const char *A, const char *B);

#endif