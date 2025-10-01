/**
 * Função : Verificar recursivamente se uma string tem mais vogais que consoantes.
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q11 - Ignora dígitos/espacos/pontuação.
 */
#include <stdio.h>
#include <stdlib.h>

int contar_vogais_consoantes(const char *str, int index, int *vogais, int *consoantes) {
    if (str == NULL || vogais == NULL || consoantes == NULL) {
        return 0; // Validação de entrada
    }

    if (str[index] == '\0') {
        return 0; // Fim da string
    }

    char c = tolower(str[index]);
    if (c >= 'a' && c <= 'z') { 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            (*vogais)++;
        } else {
            (*consoantes)++;
        }
    }

    return contar_vogais_consoantes(str, index + 1, vogais, consoantes);
}

int tem_mais_vogais(const char *str) {
    int vogais = 0;
    int consoantes = 0;

    contar_vogais_consoantes(str, 0, &vogais, &consoantes);

    return vogais > consoantes;
}

int main() {

    const char *texto = "Exemplo de String com mais vogais!";

    if (tem_mais_vogais(texto)) {
        printf("A string tem mais vogais que consoantes.\n");
    } else {
        printf("A string não tem mais vogais que consoantes.\n");
    }

    return 0;
}