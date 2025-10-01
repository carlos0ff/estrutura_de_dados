/**
 * Função : Imprimir todas as permutações de uma string e ao final a quantidade.
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q7 - Backtracking/recursão. Duplicatas simples não filtradas.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permutar(char *str, int inicio, int fim, int *contador) {
    if (inicio == fim) {
        printf("%s\n", str);
        (*contador)++;
    } else {
        for (int i = inicio; i <= fim; i++) {
            trocar((str + inicio), (str + i));
            permutar(str, inicio + 1, fim, contador);
            trocar((str + inicio), (str + i)); // backtrack
        }
    }
}

int main() {
    char str[] = "ABC"; // Exemplo de string
    int n = strlen(str);
    int contador = 0;

    permutar(str, 0, n - 1, &contador);
    printf("Total de permutações: %d\n", contador);

    return 0;
}
