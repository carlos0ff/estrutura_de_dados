/**
 * Função : Imprimir o desenvolvimento de (x+1)^n usando coeficientes binomiais (Pascal).
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q15.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Função para calcular o coeficiente binomial C(n, k)
int coeficienteBinomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1; // Caso base
    }
    return coeficienteBinomial(n - 1, k - 1) + coeficienteBinomial(n - 1, k); // Passo recursivo
}

void imprimirDesenvolvimento(int n) {
    for (int k = 0; k <= n; k++) {
        int coef = coeficienteBinomial(n, k);
        if (k > 0) {
            printf(" + ");
        }
        printf("%d*x^%d", coef, n - k);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite um número inteiro não negativo (n): ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Por favor, insira um número não negativo.\n");
        return 1;
    }
    printf("O desenvolvimento de (x+1)^%d é:\n", n);
    imprimirDesenvolvimento(n);
    return 0;
}