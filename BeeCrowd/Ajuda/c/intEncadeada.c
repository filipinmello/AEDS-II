#include <stdio.h>
#include <stdlib.h>

// Definir a estrutura do Nó
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Definir a estrutura da Lista
typedef struct {
    No* cabeca;
    int tamanho;
} Lista;

// Função para inicializar a lista
void inicializarLista(Lista* lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

// Função para adicionar um nó à lista
void inserir(Lista* lista, int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->proximo = lista->cabeca;
    lista->cabeca = novoNo;
    lista->tamanho++;
}

// Função para remover um nó da lista
void remover(Lista* lista, int dado) {
    No* atual = lista->cabeca;
    No* anterior = NULL;

    while (atual != NULL && atual->dado != dado) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->proximo = atual->proximo;
        } else {
            lista->cabeca = atual->proximo;
        }
        free(atual);
        lista->tamanho--;
    }
}

// Função para imprimir a lista
void mostrar(Lista* lista) {
    No* atual = lista->cabeca;
    printf("[ ");
    while (atual != NULL) {
        if(atual->proximo == NULL){
            printf("%d", atual->dado);
            break;
        }
        printf("%d, ", atual->dado);
        atual = atual->proximo;
    }
    printf(" ]\n");
}

int main() {
    Lista lista1, lista2;
    
    inicializarLista(&lista1);
    inicializarLista(&lista2);

    inserir(&lista1, 1);
    inserir(&lista1, 2);
    inserir(&lista1, 3);

    inserir(&lista2, 4);
    inserir(&lista2, 5);
    inserir(&lista2, 6);

    printf("Lista 1: ");
    mostrar(&lista1);

    printf("Lista 2: ");
    mostrar(&lista2);

    remover(&lista1, 2);
    printf("Lista 1 apos remover 2: ");
    mostrar(&lista1);

    return 0;
}
