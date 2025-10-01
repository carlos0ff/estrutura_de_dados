#ifndef ESTUDANTE_H
#define ESTUDANTE_H

typedef struct {
    char nome[50];
    int matricula;
    float notas[3];
} Estudante;

Estudante* criarEstudante(const char* nome, int matricula);
void atualizarNotas(Estudante* e, float n1, float n2, float n3);
void imprimirEstudante(const Estudante* e);
float calcularMedia(const Estudante* e);

#endif
