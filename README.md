# Gerenciador de Biblioteca em C

## Descrição

Este é um sistema de gerenciamento de biblioteca desenvolvido em linguagem C. O projeto permite o cadastro, listagem, busca e empréstimo de livros, utilizando estruturas de dados como filas e pilhas para gerenciar a fila de espera e o histórico de devoluções. É uma aplicação console-based que demonstra conceitos fundamentais de programação em C, incluindo alocação dinâmica de memória, algoritmos de ordenação e busca.

## Tecnologias Utilizadas

- **Linguagem**: C
- **Estruturas de Dados**: Arrays dinâmicos, Fila (para fila de espera), Pilha (para histórico de devoluções)
- **Algoritmos**: Ordenação por QuickSort, Busca Binária
- **Bibliotecas**: stdio.h, stdlib.h, time.h (padrão do C)

## Pré-requisitos

- Sistema operacional Linux
- Compilador C (recomendado: GCC)
- Terminal para execução

## Instalação

1. Clone ou baixe o repositório para o seu ambiente local.
2. Navegue até o diretório `src/` do projeto:
   ```
   cd gerenciador-biblioteca-c/project
   ```
3. Compile o programa usando o GCC:
   ```
   gcc -I include src/*.c -o bin/main
   ```
4. Execute o programa:
   ```
   ./bin/main
   ```

## Como Usar

Após a compilação e execução, o sistema apresentará um menu interativo com as seguintes opções:

1. **Cadastro de Livros**: Permite adicionar novos livros ao sistema, informando título e quantidade inicial.
2. **Listagem de Livros**: Exibe todos os livros cadastrados, ordenados alfabeticamente.
3. **Busca de Livros**: Realiza busca binária por título para localizar um livro específico.
4. **Acréscimo ao Estoque**: Adiciona exemplares a um livro existente.
5. **Empréstimo**: Registra empréstimo de livros, gerenciando fila de espera quando não há exemplares disponíveis.
6. **Devolução**: Processa devoluções e empresta automaticamente para pessoas na fila de espera.
7. **Histórico de Devoluções**: Visualiza o histórico de devoluções usando uma pilha.
8. **Relatório de Empréstimos**: Exibe estatísticas de empréstimos por livro.

Siga as instruções no console para navegar pelas opções. O sistema valida entradas e fornece feedback para operações bem-sucedidas ou erros.

## Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo LICENSE para mais detalhes.