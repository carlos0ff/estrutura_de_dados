

/**
 * Função : (STUB) Calcular uma série recursiva (fórmula original ilegível no PDF).
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Preencha a função 'serie' com a fórmula correta da Q1.
 */

#include <stdio.h>
#include <stdlib.h>

double serie(int n) {
    // STUB: Substitua o corpo desta função pela fórmula correta da série.
    if (n == 0) {
        return 1.0; // Exemplo base, ajuste conforme necessário.
    }
    return 1.0 / (n * n) + serie(n - 1); // Exemplo recursivo, ajuste conforme necessário.
}

int main() {
    int termos = 10; // Defina o número de termos conforme necessário.
    double resultado = serie(termos);
    printf("Resultado da série: %.10f\n", resultado);
    return 0;
}