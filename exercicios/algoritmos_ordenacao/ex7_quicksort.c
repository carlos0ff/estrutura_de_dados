#include <stdio.h>
#include <stdlib.h>


/**
 * Função: Ordena os elementos de um vetor de inteiros em ordem crescente
 *         utilizando o algoritmo Quicksort.
 * Autor : José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data : 07/06/2025
 * Observações: O pivô escolhido é o elemento central do vetor. A ordenação é feita
 *              recursivamente dividindo o vetor em subvetores.
 * Referenciâ: https://www.youtube.com/watch?v=DT7TVYHhepY&ab_channel=GurudaCi%C3%AAncia
 */


/**
 * Função para trocar dois elementos
 */
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Função quicksort
 */
void quicksort(int vetor[], int inicio, int fim) {
    int i = inicio;
    int j = fim;

    int pivo = vetor[(inicio + fim) / 2];

    while (i <= j) {
        while (vetor[i] < pivo) i++;
        while (vetor[j] > pivo) j--;

        if (i <= j) {
            trocar(&vetor[i], &vetor[j]);
            i++;
            j--;
        }
    }

    if (inicio < j)
        quicksort(vetor, inicio, j);
    if (i < fim)
        quicksort(vetor, i, fim);
}

/**
 * Função para imprimir o vetor
 */
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

/**
 * 
 */
int main() {
    int vetor[] = {23, 12, 4, 56, 78, 1, 90, 34};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    quicksort(vetor, 0, tamanho - 1);

    printf("\nVetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
