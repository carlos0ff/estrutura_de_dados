/*
** Função : Implementa um TAD para manipulação dinâmica de vetor de inteiros, com inserção, remoção, consulta e impressão.
** Autor : José Carlos - 3º Período - Turma F - Ciência da Computação
** Data : 15/06/2025
** Observações: Usa 3 arquivos: interface (.h), implementação (.c) e arquivo de teste (.c).
*/

#include <stdio.h>
#include "ED-lista2-questao01.h"

int main() {
    Vetor* v = criarVetor(10);

    inserirElemento(v, 5);
    inserirElemento(v, 10);
    inserirElemento(v, 15);

    imprimirVetor(v);

    removerElemento(v, 10);

    imprimirVetor(v);

    printf("Elemento na posição 1: %d\n", consultarElemento(v, 1));

    liberarVetor(v);

    return 0;
}
