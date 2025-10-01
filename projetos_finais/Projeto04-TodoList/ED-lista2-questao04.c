/*
** Função : Sistema de gerenciamento de tarefas com prioridade e vencimento, utilizando listas, pilhas, filas e deques.
** Autor : José Carlos - 3º Período - Turma F - Ciência da Computação
** Data : 15/06/2025
** Observações: Usa TAD Tarefa, com manipulação dinâmica, gerenciamento de tarefas concluídas, agendamento e função recursiva.
*/

#include <stdio.h>
#include "tarefa.h"

int main() {
    Tarefa* lista = NULL;
    TarefaConcluida* pilha = NULL;

    adicionarTarefa(&lista, "Estudar C", 2, 17062025);
    adicionarTarefa(&lista, "Enviar trabalho", 3, 18062025);

    printf("Total de tarefas: %d\n", contarTarefas(lista));

    concluirTarefa(&lista, &pilha);
    printf("Tarefa concluída. Tarefas restantes: %d\n", contarTarefas(lista));

    return 0;
}