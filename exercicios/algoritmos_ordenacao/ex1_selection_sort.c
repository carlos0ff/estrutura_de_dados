#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

/**
 * Troca os valores entre duas posições de um vetor
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Função: Classifica os elementos de um vetor de inteiros em ordem crescente usando o algoritmo de seleção (Selection Sort).
 * Autor : José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data  : 04/06/2025
 * Observações: O algoritmo seleciona o menor elemento restante do vetor e o posiciona corretamente a cada iteração.
 * Referencia: https://www.youtube.com/watch?v=DkzNKFn5wOw&ab_channel=Programeseufuturo
 */
void selectionSort(int vetor[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) 
    {
        min_idx = i;

        for (j = i + 1; j < n; j++) 
        {
            if (vetor[j] < vetor[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap(&vetor[i], &vetor[min_idx]);
    }
}

/**
 * Gera um vetor com valores aleatórios entre 0 e 99
 */
void gerarAleatorios(int vetor[], int n) 
{

    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
    }
}

/**
 * Exibe os elementos do vetor
 */
void exibirVetor(int vetor[], int n) 
{

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

/**
 * 
 */
int main() 
{
    int vetor[TAM];

    srand(time(NULL)); 

    printf("Vetor original:\n");
    gerarAleatorios(vetor, TAM);
    exibirVetor(vetor, TAM);

    selectionSort(vetor, TAM);

    printf("\nVetor ordenado:\n");
    exibirVetor(vetor, TAM);

    return 0;
}
