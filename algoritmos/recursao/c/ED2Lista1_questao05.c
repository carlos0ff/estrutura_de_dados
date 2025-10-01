/**
 * Função : Inverter uma string usando recursão.
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q5 - Recursão.
 */

#include <stdio.h>
#include <stdlib.h>

void inverter_string(char *str, int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    
    // Troca os caracteres nas posições 'inicio' e 'fim'
    char temp = str[inicio]

    str[inicio] = str[fim];
    str[fim] = temp;
    
    // Chama a função recursivamente para o próximo par de caracteres
    inverter_string(str, inicio + 1, fim - 1);
}

int main() {
    char str[] = "Estrutura de dados"; // Exemplo de string
    int len = 0;
    
    // Calcula o comprimento da string
    while (str[len] != '\0') {
        len++;
    }
    
    inverter_string(str, 0, len - 1);
    
    printf("String invertida: %s\n", str);
    
    return 0;
}