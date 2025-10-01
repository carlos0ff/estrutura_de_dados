/**
 * Função      : Verifica a Conjectura de Goldbach para todos os números pares entre 700 e 1100,
 *               mostrando para cada número a soma de dois números primos correspondente.
 * Autor       : José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data        : 07/06/2025
 * Observações : O programa utiliza uma função auxiliar para verificar se um número é primo.
 * Referência  : Conjectura de Goldbach (https://pt.wikipedia.org/wiki/Conjectura_de_Goldbach)
 */


#include <stdio.h>
#include <stdbool.h>

/**
 * Função para verificar se um número é primo
 */
bool ehPrimo(int n) 
{
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
            
    return true;
}

/**
 * Função principal
 */
int main() {
    // printf("Verificando a Conjectura de Goldbach para pares entre 700 e 1100:\n");

    for (int num = 700; num <= 1100; num += 2) 
    {
        for (int i = 2; i <= num / 2; i++) 
        {
            if (ehPrimo(i) && ehPrimo(num - i)) 
            {
                printf("%d = %d + %d\n", num, i, num - i);

                break;
            }
        }
    }

    return 0;
}
