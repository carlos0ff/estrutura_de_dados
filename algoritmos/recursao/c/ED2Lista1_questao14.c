/**
 * Função : Testar recursivamente se uma string é palíndromo (ignorando caso e espaços).
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q14.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// Função auxiliar para verificar se uma string é palíndromo
int ehPalindromoRec(const char *str, int inicio, int fim) {
    // Ignorar espaços e considerar apenas letras
    while (inicio < fim && str[inicio] == ' ') {
        inicio++;
    }
    while (fim > inicio && str[fim] == ' ') {
        fim--;
    }
    // Caso base: se os índices se cruzarem ou forem iguais
    if (inicio >= fim) {
        return 1; // É palíndromo
    }
    // Comparar caracteres ignorando maiúsculas/minúsculas
    if (tolower(str[inicio]) != tolower(str[fim])) {
        return 0; // Não é palíndromo
    }
    // Chamada recursiva para os próximos caracteres
    return ehPalindromoRec(str, inicio + 1, fim - 1);
}

int ehPalindromo(const char *str) {
    int len = strlen(str);
    return ehPalindromoRec(str, 0, len - 1);
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    // Remover o caractere de nova linha, se presente
    str[strcspn(str, "\n")] = 0;

    if (ehPalindromo(str)) {
        printf("A string é um palíndromo.\n");
    } else {
        printf("A string não é um palíndromo.\n");
    }
    return 0;
}