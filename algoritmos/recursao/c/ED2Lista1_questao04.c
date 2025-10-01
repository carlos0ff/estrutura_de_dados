/**
 * Função : Implementar mod(x,y) usando recursão por subtrações.
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q4 - Recursão. x,y > 0.
 */

#include <stdio.h>
#include <stdlib.h>

int mod(int x, int y) {

    if (x < y) {
        return x;
    }

    return mod(x - y, y);
}

int main() {

    int x = 29; // Exemplo de valor para x
    int y = 5;  // Exemplo de valor para y

    int resultado = mod(x, y);

    printf("mod(%d, %d) = %d\n", x, y, resultado);
    
    return 0;
}