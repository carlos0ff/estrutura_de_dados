/**
 * Função : Esqueleto de TADs para Lista de Voos com passageiros e fila (prioridade 1..5).
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q12 - Estruturas compostas; operações básicas de inserção/remoção/busca.
 *              Implementação minimalista sem Collections.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSAGEIROS 100
#define MAX_NOME 50
#define MAX_VOOS 50
#define MAX_CODIGO_VOO 10
#define MAX_PRIORIDADE 5
#define MIN_PRIORIDADE 1
#define MIN_PRIORIDADE_FILA 1
#define MAX_PRIORIDADE_FILA 5

typedef struct {
    char nome[MAX_NOME];
    int prioridade; // 1 (mais alta) a 5 (mais baixa)
} Passageiro;

typedef struct {
    char codigoVoo[MAX_CODIGO_VOO];
    Passageiro passageiros[MAX_PASSAGEIROS];
    int numPassageiros;
} Voo;

typedef struct {
    Voo voos[MAX_VOOS];
    int numVoos;
} ListaVoos;

// Função para inicializar a lista de voos
void inicializarListaVoos(ListaVoos *lista) {
    lista->numVoos = 0;
}

// Função para adicionar um voo à lista
bool adicionarVoo(ListaVoos *lista, const char *codigoVoo) {
    if (lista->numVoos >= MAX_VOOS) {
        return false; // Lista cheia
    }
    strcpy(lista->voos[lista->numVoos].codigoVoo, codigoVoo);
    lista->voos[lista->numVoos].numPassageiros = 0;
    lista->numVoos++;
    return true;
}

// Função para encontrar um voo na lista
Voo* encontrarVoo(ListaVoos *lista, const char *codigoVoo
) {
    for (int i = 0; i < lista->numVoos; i++) {
        if (strcmp(lista->voos[i].codigoVoo, codigoVoo) == 0) {
            return &lista->voos[i];
        }
    }
    return NULL; // Voo não encontrado
}

// Função para adicionar um passageiro a um voo com prioridade
bool adicionarPassageiro(Voo *voo, const char *nome, int prioridade) {
    if (voo->numPassageiros >= MAX_PASSAGEIROS || prioridade < MIN_PRIORIDADE || prioridade > MAX_PRIORIDADE) {
        return false; // Voo cheio ou prioridade inválida
    }
    Passageiro novoPassageiro;
    strcpy(novoPassageiro.nome, nome);
    novoPassageiro.prioridade = prioridade;

    // Inserir passageiro na posição correta com base na prioridade
    int i;
    for (i = voo->numPassageiros - 1; (i >= 0 && voo->passageiros[i].prioridade > prioridade); i--) {
        voo->passageiros[i + 1] = voo->passageiros[i];
    }
    voo->passageiros[i + 1] = novoPassageiro;
    voo->numPassageiros++;
    return true;
}
// Função para remover um passageiro de um voo
bool removerPassageiro(Voo *voo, const char *nome) {
    for (int i = 0; i < voo->numPassageiros; i++) {
        if (strcmp(voo->passageiros[i].nome, nome) == 0) {
            // Deslocar os passageiros restantes para preencher o espaço
            for (int j = i; j < voo->numPassageiros - 1; j++) {
                voo->passageiros[j] = voo->passageiros[j + 1];
            }
            voo->numPassageiros--;
            return true; // Passageiro removido
        }
    }
    return false; // Passageiro não encontrado
}

// Função para exibir os passageiros de um voo
void exibirPassageiros(Voo *voo) {
    printf("Passageiros do voo %s:\n", voo->codigoVoo);
    for (int i = 0; i < voo->numPassageiros; i++) {
        printf("Nome: %s, Prioridade: %d\n", voo->passageiros[i].nome, voo->passageiros[i].prioridade);
    }
}

int main() {
    ListaVoos listaVoos;
    inicializarListaVoos(&listaVoos);

    adicionarVoo(&listaVoos, "AA123");
    adicionarVoo(&listaVoos, "BB456");

    Voo *vooAA123 = encontrarVoo(&listaVoos, "AA123");
    if (vooAA123) {
        adicionarPassageiro(vooAA123, "Alice", 2);
        adicionarPassageiro(vooAA123, "Bob", 1);
        adicionarPassageiro(vooAA123, "Charlie", 3);
        exibirPassageiros(vooAA123);

        removerPassageiro(vooAA123, "Bob");
        printf("\nApós remover Bob:\n");
        exibirPassageiros(vooAA123);
    } else {
        printf("Voo AA123 não encontrado.\n");
    }

    return 0;
}