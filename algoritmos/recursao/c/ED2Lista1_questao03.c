/**
 * Função : Contar ocorrências de um dígito d em um número natural n (recursivo).
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q3 - Recursão.
 */

#include <stdio.h>
#include <stdlib.h>

int contar_digito(int n, int d) {
    
    if (n == 0) {
        return 0;
    }

    int ultimo_digito = n % 10;
    int conta = (ultimo_digito == d) ? 1 : 0;

    return conta + contar_digito(n / 10, d);
}
