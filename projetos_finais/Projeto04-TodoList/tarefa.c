#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefa.h"

void adicionarTarefa(Tarefa** lista, const char* desc, int prioridade, int data) {
    Tarefa* nova = (Tarefa*)malloc(sizeof(Tarefa));
    strcpy(nova->descricao, desc);
    nova->prioridade = prioridade;
    nova->dataVencimento = data;
    nova->prox = *lista;
    *lista = nova;
}

void concluirTarefa(Tarefa** lista, TarefaConcluida** pilha) {
    if (*lista) {
        Tarefa* t = *lista;
        *lista = t->prox;
        TarefaConcluida* nova = (TarefaConcluida*)malloc(sizeof(TarefaConcluida));
        strcpy(nova->descricao, t->descricao);
        nova->prox = *pilha;
        *pilha = nova;
        free(t);
    }
}

int contarTarefas(Tarefa* lista) {
    if (lista == NULL) return 0;
    return 1 + contarTarefas(lista->prox);
}