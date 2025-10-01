/**
 * Função      : Calcula a raiz quadrada de um número usando o método de Newton-Raphson
 * Autor       : José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data        : 07/06/2025
 * Observações : Usa f(x) = x^2 - n e f'(x) = 2x para calcular sqrt(n) com precisão de 0.0001
 * Referência  : https://pt.wikipedia.org/wiki/Método_de_Newton
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PRECISAO 0.0001

/**
 * 
 */
double raiz_quadrada_newton(double n) 
{
    if (n < 0) 
        printf("Erro: número negativo.\n");
        // exit(1);
    

    double x = n / 2.0;  
    double erro;

    do {
        double fx = x * x - n;
        double fpx = 2 * x;
        double x_proximo = x - fx / fpx;

        erro = fabs(x_proximo - x);
        x = x_proximo;

    } while (erro > PRECISAO);

    return x;
}

/**
 * 
 */
int main() 
{
    double numero;

    printf("Digite um número para calcular a raiz quadrada: ");
    scanf("%lf", &numero);

    double resultado = raiz_quadrada_newton(numero);

    printf("A raiz quadrada aproximada de %.4lf é %.5lf\n", numero, resultado);

    return 0;
}
