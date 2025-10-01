#include <stdio.h>
#include <stdlib.h>
#include "ED-lista2-questao01.h"

Vetor* criarVetor(int capacidade) {
    Vetor* v = (Vetor*)malloc(sizeof(Vetor));
    v->dados = (int*)malloc(capacidade * sizeof(int));
    v->tamanho = 0;
    v->capacidade = capacidade;
    return v;
}

void inserirElemento(Vetor* v, int elemento) {
    if (v->tamanho < v->capacidade) {
        v->dados[v->tamanho++] = elemento;
    } else {
        printf("Capacidade máxima atingida.\n");
    }
}

void removerElemento(Vetor* v, int elemento) {
    for (int i = 0; i < v->tamanho; i++) {
        if (v->dados[i] == elemento) {
            for (int j = i; j < v->tamanho - 1; j++) {
                v->dados[j] = v->dados[j + 1];
            }
            v->tamanho--;
            return;
        }
    }
    printf("Elemento não encontrado.\n");
}

int consultarElemento(Vetor* v, int posicao) {
    if (posicao >= 0 && posicao < v->tamanho) {
        return v->dados[posicao];
    }
    printf("Posição inválida.\n");
    return -1;
}

void imprimirVetor(Vetor* v) {
    printf("Vetor: ");
    for (int i = 0; i < v->tamanho; i++) {
        printf("%d ", v->dados[i]);
    }
    printf("\n");
}

void liberarVetor(Vetor* v) {
    free(v->dados);
    free(v);
}
