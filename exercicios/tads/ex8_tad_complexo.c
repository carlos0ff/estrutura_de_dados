/**
 * TAD: Complexo
 * Autor: José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data: 04/06/2025
 * Observações: Implementa operações básicas com números complexos.
 * Referencia: https://www.youtube.com/watch?v=NvNSFsFHmmA&ab_channel=FelipeLouza-UFU
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Definição do tipo Complexo
 */
typedef struct {
    double real;
    double imag;
} Complexo;

/**
 * Função para criar um número complexo
 */
Complexo* criarComplexo(double real, double imag) {
    Complexo *c = (Complexo*) malloc(sizeof(Complexo));

    if (c != NULL) {
        c->real = real;
        c->imag = imag;
    }

    return c;
}

/**
 * Função para destruir (liberar) um número complexo
 */
void destruirComplexo(Complexo *c) 
{
    if (c != NULL) 
        free(c);
    
}

/**
 * Função para ler um número complexo
 */
Complexo* lerComplexo() 
{
    double real, imag;
    printf("Digite a parte real: ");
    scanf("%lf", &real);
    printf("Digite a parte imaginária: ");
    scanf("%lf", &imag);
    return criarComplexo(real, imag);
}

/**
 * Função para somar dois números complexos
 */
Complexo* somarComplexo(Complexo *a, Complexo *b) 
{
    return criarComplexo(a->real + b->real, a->imag + b->imag);
}

/**
 * Função para subtrair dois números complexos
 */
Complexo* subtrairComplexo(Complexo *a, Complexo *b) 
{
    return criarComplexo(a->real - b->real, a->imag - b->imag);
}

/**
 * Função para multiplicar dois números complexos
 */
Complexo* multiplicarComplexo(Complexo *a, Complexo *b) 
{
    double real = a->real * b->real - a->imag * b->imag;
    double imag = a->real * b->imag + a->imag * b->real;
    return criarComplexo(real, imag);
}

/** 
 * Função para dividir dois números complexos
 */ 
Complexo* dividirComplexo(Complexo *a, Complexo *b) 
{
    double denominador = b->real * b->real + b->imag * b->imag;

    if (denominador == 0) {
        printf("Erro: Divisão por zero.\n");
        return NULL;
    }

    double real = (a->real * b->real + a->imag * b->imag) / denominador;
    double imag = (a->imag * b->real - a->real * b->imag) / denominador;
    return criarComplexo(real, imag);
}

/**
 * Função para exibir um número complexo na forma (a,b)
 */
void mostrarComplexo(Complexo *c) 
{
    if (c != NULL)
        printf("(%.2lf, %.2lf)\n", c->real, c->imag);
    else
        printf("(null)\n");
}

/**
 * Função principal 
 */
int main() {
    Complexo *c1 = lerComplexo();
    Complexo *c2 = lerComplexo();

    Complexo *soma = somarComplexo(c1, c2);
    Complexo *sub  = subtrairComplexo(c1, c2);
    Complexo *mult = multiplicarComplexo(c1, c2);
    Complexo *div  = dividirComplexo(c1, c2);

    printf("\nNúmero 1: "); mostrarComplexo(c1);
    printf("Número 2: "); mostrarComplexo(c2);
    printf("\nSoma: "); mostrarComplexo(soma);
    printf("Subtração: "); mostrarComplexo(sub);
    printf("Multiplicação: "); mostrarComplexo(mult);
    printf("Divisão: "); mostrarComplexo(div);

    destruirComplexo(c1);
    destruirComplexo(c2);
    destruirComplexo(soma);
    destruirComplexo(sub);
    destruirComplexo(mult);
    destruirComplexo(div);

    return 0;
}
