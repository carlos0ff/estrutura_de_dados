#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudante.h"

Estudante* criarEstudante(const char* nome, int matricula) {
    Estudante* e = (Estudante*)malloc(sizeof(Estudante));
    strcpy(e->nome, nome);
    e->matricula = matricula;
    e->notas[0] = e->notas[1] = e->notas[2] = 0;
    return e;
}

void atualizarNotas(Estudante* e, float n1, float n2, float n3) {
    e->notas[0] = n1;
    e->notas[1] = n2;
    e->notas[2] = n3;
}

void imprimirEstudante(const Estudante* e) {
    printf("Nome: %s\n", e->nome);
    printf("Matrícula: %d\n", e->matricula);
    printf("Notas: %.1f, %.1f, %.1f\n", e->notas[0], e->notas[1], e->notas[2]);
    printf("Média: %.2f\n", calcularMedia(e));
}

float calcularMedia(const Estudante* e) {
    return (e->notas[0] + e->notas[1] + e->notas[2]) / 3.0f;
}
