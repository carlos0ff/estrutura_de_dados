/**
 * Função: Cadastro de aeroportos com alocação dinâmica, leitura, exibição e exclusão
 * Autor : José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data : 04/06/2025
 * Observações: Sistema permite adicionar, listar e excluir aeroportos armazenados dinamicamente
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definição da estrutura
 */
typedef struct {
  char sigla[4];       
  char cidade[51];     
  char pais[31];        
  float taxa;
  int capacidade;
} Aeroporto;

/**
 * Função para ler um aeroporto
 */
Aeroporto* lerAeroporto() {
  Aeroporto* novo = (Aeroporto*)malloc(sizeof(Aeroporto));
  if (!novo) {
    printf("Erro ao alocar memória.\n");
    return NULL;
  }

  printf("Digite a sigla do aeroporto (3 letras): ");
  scanf(" %3s", novo->sigla);

  printf("Digite a cidade: ");
  scanf(" %50[^\n]", novo->cidade);

  printf("Digite o país: ");
  scanf(" %30[^\n]", novo->pais);

  printf("Digite a taxa do aeroporto: ");
  scanf("%f", &novo->taxa);

  printf("Digite a capacidade do aeroporto: ");
  scanf("%d", &novo->capacidade);

  return novo;
}

/**
 * Função para exibir um aeroporto
 */
void exibirAeroporto(Aeroporto* a) {
  if (a != NULL) {
    printf("\nSigla: %s\n", a->sigla);
    printf("Cidade: %s\n", a->cidade);
    printf("País: %s\n", a->pais);
    printf("Taxa: %.2f\n", a->taxa);
    printf("Capacidade: %d\n", a->capacidade);
  }
}

/**
 * Função para excluir um aeroporto
 */
void excluirAeroporto(Aeroporto** lista, int* tamanho, int indice) {
  if (indice < 0 || indice >= *tamanho) {
    printf("Índice inválido.\n");
    return;
  }

  free(lista[indice]);

  for (int i = indice; i < *tamanho - 1; i++) {
    lista[i] = lista[i + 1];
  }

  (*tamanho)--;
  lista = realloc(lista, (*tamanho) * sizeof(Aeroporto*));
}

/**
 * Função principal para teste
 */
int main() {
  int n = 0;
  Aeroporto** aeroportos = NULL;
  int opcao;

  do {
    printf("\n1 - Adicionar aeroporto\n2 - Listar aeroportos\n3 - Excluir aeroporto\n0 - Sair\nEscolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1: {
        aeroportos = realloc(aeroportos, (n + 1) * sizeof(Aeroporto*));
        aeroportos[n] = lerAeroporto();

        if (aeroportos[n] != NULL){
          n++;
        }
            
        break;
      }
      case 2:
        for (int i = 0; i < n; i++) {
          printf("\n[Aeroporto %d]", i + 1);
          exibirAeroporto(aeroportos[i]);
        }
        break;
      case 3: {
        int indice;

        printf("Digite o índice do aeroporto a excluir (1 a %d): ", n);
        scanf("%d", &indice);
        excluirAeroporto(aeroportos, &n, indice - 1);

        break;
      }
      case 0:
        break;
      default:
        printf("Opção inválida.\n");
    }
  } while (opcao != 0);

  for (int i = 0; i < n; i++) {
      free(aeroportos[i]);
  }
  free(aeroportos);

  return 0;
}
