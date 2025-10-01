/*
** Função : Simula um sistema de agendamento com médico (fila estática) e enfermagem (fila dinâmica).
** Autor : José Carlos - 3º Período - Turma F - Ciência da Computação
** Data : 15/06/2025
** Observações: Utiliza fila estática com limite de 5 para médicos e fila dinâmica sem limite para enfermagem.
** KÉSSIA É MUITO É UMA DEUSA SELOKO TIO

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICO 5

typedef struct {
    char nome[50];
} Paciente;

typedef struct {
    Paciente fila[MAX_MEDICO];
    int frente, tras;
} FilaEstatica;


typedef struct No {
    Paciente paciente;
    struct No* prox;
} No;

typedef struct {
    No* frente;
    No* tras;
} FilaDinamica;

void inicializarFilaEstatica(FilaEstatica* f) {
    f->frente = 0;
    f->tras = 0;
}

int estaCheia(FilaEstatica* f) {
    return f->tras == MAX_MEDICO;
}

void agendarMedico(FilaEstatica* f, char* nome) {
    if (!estaCheia(f)) {
        strcpy(f->fila[f->tras++].nome, nome);
    } else {
        printf("Fila de médico cheia.\n");
    }
}

void inicializarFilaDinamica(FilaDinamica* f) {
    f->frente = NULL;
    f->tras = NULL;
}

void agendarEnfermagem(FilaDinamica* f, char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->paciente.nome, nome);
    novo->prox = NULL;
    if (f->tras) f->tras->prox = novo;
    else f->frente = novo;
    f->tras = novo;
}

int main() {
    FilaEstatica filaMedico;
    FilaDinamica filaEnfermagem;

    inicializarFilaEstatica(&filaMedico);
    inicializarFilaDinamica(&filaEnfermagem);

    agendarMedico(&filaMedico, "Maria");
    agendarMedico(&filaMedico, "João");

    agendarEnfermagem(&filaEnfermagem, "Carlos");
    agendarEnfermagem(&filaEnfermagem, "Ana");

    printf("Agendamentos realizados com sucesso.\n");
    return 0;
}