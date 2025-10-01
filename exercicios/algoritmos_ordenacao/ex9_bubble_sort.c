/**
 * Função: Ordenação de um vetor usando o método Bubble Sort.
 *         Conta o número de comparações (ifs) e trocas realizadas.
 * Autor : José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data : 04/06/2025
 * Observações: O vetor é preenchido com valores aleatórios entre 0 e 99.
 * Referenciã: https://www.youtube.com/watch?v=rQTQF46o16k&ab_channel=GurudaCi%C3%AAncia
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Função para trocar dois elementos
 */
void trocar(int *a, int *b) 
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

/**
 * Função BubbleSort com contagem de comparações e trocas
 */
void bubbleSort(int vetor[], int tamanho, int *comparacoes, int *trocas) 
{
    *comparacoes = 0;
    *trocas = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            (*comparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
                (*trocas)++;
            }
        }
    }
}

/**
 * Função para imprimir o vetor
 */
void imprimirVetor(int vetor[], int tamanho) 
{
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

/**
 * Função principal
 */
int main() 
{
    int n, comparacoes, trocas;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100; 
    }

    printf("\nVetor original:\n");
    imprimirVetor(vetor, n);

    bubbleSort(vetor, n, &comparacoes, &trocas);

    printf("\nVetor ordenado:\n");
    imprimirVetor(vetor, n);

    printf("\nTotal de comparações (ifs): %d\n", comparacoes);
    printf("Total de trocas realizadas: %d\n", trocas);

    return 0;
}
