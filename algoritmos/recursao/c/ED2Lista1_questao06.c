/**
 * Função : Contar número de nós de uma lista encadeada (sem Collections).
 * Autor  : José Carlos da Silva Júnior (UNIPÊ)
 * Data   : 01/10/2025
 * Observações: Q6 - Recursão.
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

int contar_nos(Node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + contar_nos(head->next);
}

Node* criar_no(int data) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    novo_no->data = data;
    novo_no->next = NULL;
    return novo_no;
}

int main() {
    Node* head = criar_no(1);
    head->next = criar_no(2);
    head->next->next = criar_no(3);
    
    int total_nos = contar_nos(head);
    printf("Número de nós na lista: %d\n", total_nos);
    
    // Liberar memória
    Node* atual = head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->next;
        free(temp);
    }
    
    return 0;
}