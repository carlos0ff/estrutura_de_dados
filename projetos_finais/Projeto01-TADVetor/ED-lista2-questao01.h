/*
**    Função : Interface do TAD Vetor de Inteiros
**    Autor : José Carlos, 3P Turma F
**    Data  : 15/06/2025
**    Observações: Define funções e estrutura do vetor dinâmico.
*/

#ifndef TAD_VETOR_H
#define TAD_VETOR_H

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Vetor;

Vetor* criarVetor(int quantidade);
void inserirElemento(Vetor* v, int elemento);
void removerElemento(Vetor* v, int elemento);
int consultarElemento(Vetor* v, int posicao);
void imprimirVetor(Vetor* v);
void liberarVetor(Vetor* v);

#endif
