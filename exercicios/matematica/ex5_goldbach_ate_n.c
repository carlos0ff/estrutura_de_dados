/**
 * Função      : Verifica a Conjectura de Goldbach para todos os números pares de 4 até N (informado pelo usuário),
 *               imprimindo cada número como a soma de dois primos.
 * Autor       : José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data        : 07/06/2025
 * Observações : O programa solicita ao usuário um número inteiro N >= 4 e usa uma função auxiliar para identificar primos.
 * Referência  : Conjectura de Goldbach (https://pt.wikipedia.org/wiki/Conjectura_de_Goldbach)
 * https://www.youtube.com/watch?v=qKU-YEY_ne8&ab_channel=AprendeconmigoInform%C3%A1tica
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * 
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
 * 
 */
int main() 
{
    int N;

    printf("Informe um número inteiro N >= 4: ");
    scanf("%d", &N);

    if (N < 4) {
        printf("N deve ser maior ou igual a 4.\n");
        return 1;
    }

    printf("Verificando a Conjectura de Goldbach de 4 até %d:\n", N);

    for (int num = 4; num <= N; num += 2) {
        for (int i = 2; i <= num / 2; i++) {
            if (ehPrimo(i) && ehPrimo(num - i)) {
                printf("%d = %d + %d\n", num, i, num - i);
                break;
            }
        }
    }

    return 0;
}
