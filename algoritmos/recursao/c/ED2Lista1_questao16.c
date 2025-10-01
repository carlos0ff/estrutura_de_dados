/**
 * Função : Aproximar e = sum 1/n! até termo < 1e-8.
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Questão 16.
 */

#include <stdio.h>
#include <stdlib.h>

double fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    }
    return n * fatorial(n - 1);
}

double aproximar_e(int n) {
    double termo = 1.0 / fatorial(n);
    if (termo < 1e-8) {
        return 0.0;
    }
    return termo + aproximar_e(n + 1);
}

int main() {
    double e = aproximar_e(0);
    printf("Aproximação de e: %.10f\n", e);
    return 0;
}