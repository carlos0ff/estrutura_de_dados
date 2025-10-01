
/*
** Função : Gerencia dados de estudantes usando listas, pilhas, filas e deques para registros, históricos e atendimentos.
** Autor : José Carlos - 3º Período - Turma F - Ciência da Computação
** Data : 15/06/2025
** Observações: Utiliza TAD Estudante, histórico de notas em pilha, fila de matrícula e deque para atendimento.
*/

#include <stdlib.h>
#include "estudante.h"

int main() {
    Estudante* e1 = criarEstudante("Carlos", 123);
    atualizarNotas(e1, 7.5, 8.0, 9.0);
    imprimirEstudante(e1);
    free(e1);
    return 0;
}
