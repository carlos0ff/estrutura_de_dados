/**
 * Função : Cifra de César (criptografar/descriptografar) preservando maiúsculas/minúsculas.
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q9 - Caracteres acentuados e símbolos são mantidos sem mudança.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cifra_cesar(char *texto, int deslocamento) {
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        
        // Verifica se é letra maiúscula
        if (c >= 'A' && c <= 'Z') {
            texto[i] = (c - 'A' + deslocamento + 26) % 26 + 'A';
        }
        // Verifica se é letra minúscula
        else if (c >= 'a' && c <= 'z') {
            texto[i] = (c - 'a' + deslocamento + 26) % 26 + 'a';
        }
        // Caracteres não alfabéticos permanecem inalterados
    }
}

int main() {
    char texto[] = "sogrinho favorito"; 
    int deslocamento = 3; // Deslocamento para a cifra de César

    printf("Texto original: %s\n", texto);
    
    cifra_cesar(texto, deslocamento);
    printf("Texto cifrado: %s\n", texto);
    
    cifra_cesar(texto, -deslocamento);
    printf("Texto decifrado: %s\n", texto);
    
    return 0;
}