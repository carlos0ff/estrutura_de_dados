/**
 * Defina um registro (estrutura - struct) empregado para armazenar os dados (nome, data de
 * nascimento, RG, data de admissão e salário)de um empregado de uma empresa. Criar um
 * novo tipo de dados chamado Empregado usando a estrutura empregado. Defina um vetor
 * de empregados (usando alocação dinâmica) para armazenar todos os empregados de sua
 * empresa. Implementar rotinas para ler, escrever e excluir registros deste tipo
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Função: Gerenciamento de registros de empregados
 * Autor : José Carlos da Silva Junior - Turma: Ciência da Computação - 3º período
 * Data  : 04/06/2025
 * Observações: 
 * - Utiliza alocação dinâmica de memória para manipular a lista de empregados.
 * - Permite inserção, exibição e exclusão de registros.
 */
typedef struct {
    char nome[100];
    char dataNascimento[11]; 
    char rg[15];
    char dataAdmissao[11];
    float salario;
} Empregado;

/**
 * Função para ler os dados de um empregado
 */
void lerEmpregado(Empregado *emp) 
{
    printf("Nome: ");
    fgets(emp->nome, sizeof(emp->nome), stdin);
    emp->nome[strcspn(emp->nome, "\n")] = 0; 

    printf("Data de nascimento (DD/MM/AAAA): ");
    fgets(emp->dataNascimento, sizeof(emp->dataNascimento), stdin);
    emp->dataNascimento[strcspn(emp->dataNascimento, "\n")] = 0;

    printf("RG: ");
    fgets(emp->rg, sizeof(emp->rg), stdin);
    emp->rg[strcspn(emp->rg, "\n")] = 0;

    printf("Data de admissão (DD/MM/AAAA): ");
    fgets(emp->dataAdmissao, sizeof(emp->dataAdmissao), stdin);
    emp->dataAdmissao[strcspn(emp->dataAdmissao, "\n")] = 0;

    printf("Salário: ");
    scanf("%f", &emp->salario);
    getchar();
}

/**
 * 
 */
void exibirEmpregado(Empregado *emp)
{
    printf("Nome: %s\n", emp->nome);
    printf("RG: %s\n", emp->rg);
    printf("Data de nascimento: %s\n", emp->dataNascimento);
    printf("Data de admissão: %s\n", emp->dataAdmissao);
    printf("Salário: %.2f\n", emp->salario);
}

/**
 * Função para excluir um empregado (por índice)
 */
void excluirEmpregado(Empregado **empregados, int *n, int indice) {
    if (indice < 0 || indice >= *n) {
        printf("Índice inválido.\n");
        return;
    }

    for (int i = indice; i < *n - 1; i++) {
        (*empregados)[i] = (*empregados)[i + 1];
    }

    *empregados = realloc(*empregados, (*n - 1) * sizeof(Empregado));
    (*n)--;

    printf("Empregado excluído com sucesso.\n");
}

/**
 * FUNÇÃO PRINCIPAL
 */
int main() {
    Empregado *empregados = NULL;
    int total = 0;
    int opcao;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar empregado\n");
        printf("2. Exibir empregados\n");
        printf("3. Excluir empregado\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        getchar(); 

        switch (opcao) {
            case 1:
                empregados = realloc(empregados, (total + 1) * sizeof(Empregado));
                if (empregados == NULL) {
                    printf("Erro de alocação de memória.\n");
                    exit(1);
                }

                lerEmpregado(&empregados[total]);
                total++;
                
                break;

            case 2:
                for (int i = 0; i < total; i++) {
                    printf("\nEmpregado #%d:\n", i);
                    exibirEmpregado(&empregados[i]);
                }

                break;

            case 3:
                printf("Digite o índice do empregado para excluir (0 a %d): ", total - 1);

                int indice;
                scanf("%d", &indice);

                getchar();

                excluirEmpregado(&empregados, &total, indice);
                break;

            case 0:
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    free(empregados);

    return 0;
}
