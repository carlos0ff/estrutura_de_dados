#ifndef TAREFA_H
#define TAREFA_H

typedef struct Tarefa {
    char descricao[100];
    int prioridade;
    int dataVencimento;
    struct Tarefa* prox;
} Tarefa;

typedef struct TarefaConcluida {
    char descricao[100];
    struct TarefaConcluida* prox;
} TarefaConcluida;

void adicionarTarefa(Tarefa** lista, const char* desc, int prioridade, int data);
void concluirTarefa(Tarefa** lista, TarefaConcluida** pilha);
int contarTarefas(Tarefa* lista);
#endif