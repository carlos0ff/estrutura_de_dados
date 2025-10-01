/**
 * Função : Inverter um array de inteiros usando recursão (in-place).
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q2 - Recursão.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverterArrayRec(int *arr, int inicio, int fim) {
    if (inicio >= fim) {
        return; // Caso base: índices se cruzaram ou são iguais
    }
    // Trocar os elementos nas posições inicio e fim
    int temp = arr[inicio];
    arr[inicio] = arr[fim];
    arr[fim] = temp;
    // Chamada recursiva para os próximos elementos
    inverterArrayRec(arr, inicio + 1, fim - 1);
}

void inverterArray(int *arr, int tamanho) {
    inverterArrayRec(arr, 0, tamanho - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    inverterArray(arr, tamanho);

    printf("Array invertido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}