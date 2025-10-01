/**
 * Função : Soma dos quadrados dos n primeiros inteiros positivos (recursivo).
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q13.
 */
#include <stdio.h>
#include <stdlib.h>

int somaQuadrados(int n) {
    if (n <= 0) {
        return 0; // Caso base
    }
    return n * n + somaQuadrados(n - 1); // Passo recursivo
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Por favor, insira um número positivo.\n");
        return 1;
    }
    int resultado = somaQuadrados(n);
    printf("A soma dos quadrados dos %d primeiros inteiros positivos é: %d\n", n, resultado);
    return 0;
}