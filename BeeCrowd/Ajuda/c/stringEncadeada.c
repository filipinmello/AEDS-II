#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir a estrutura do Nó
typedef struct No {
    char* dado;
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
void inserir(Lista* lista, const char* dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = (char*)malloc((strlen(dado) + 1) * sizeof(char));
    strcpy(novoNo->dado, dado);
    novoNo->proximo = lista->cabeca;
    lista->cabeca = novoNo;
    lista->tamanho++;
}

// Função para remover um nó da lista
void remover(Lista* lista, const char* dado) {
    No* atual = lista->cabeca;
    No* anterior = NULL;

    while (atual != NULL && strcmp(atual->dado, dado) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->proximo = atual->proximo;
        } else {
            lista->cabeca = atual->proximo;
        }
        free(atual->dado);
        free(atual);
        lista->tamanho--;
    }
}

// Função para imprimir a lista
void mostrar(Lista* lista) {
    No* atual = lista->cabeca;
    printf("[ ");
    while (atual != NULL) {
        if (atual->proximo == NULL) {
            printf("\"%s\"", atual->dado);
            break;
        }
        printf("\"%s\", ", atual->dado);
        atual = atual->proximo;
    }
    printf(" ]\n");
}

// Função para liberar a memória da lista
void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    No* proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual->dado);
        free(atual);
        atual = proximo;
    }
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

int main() {
    Lista lista1, lista2;
    
    inicializarLista(&lista1);
    inicializarLista(&lista2);

    inserir(&lista1, "um");
    inserir(&lista1, "dois");
    inserir(&lista1, "tres");

    inserir(&lista2, "quatro");
    inserir(&lista2, "cinco");
    inserir(&lista2, "seis");

    printf("Lista 1: ");
    mostrar(&lista1);

    printf("Lista 2: ");
    mostrar(&lista2);

    remover(&lista1, "dois");
    printf("Lista 1 após remover 'dois': ");
    mostrar(&lista1);

    liberarLista(&lista1);
    liberarLista(&lista2);

    return 0;
}
