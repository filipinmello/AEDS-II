/*
  Passos
  1- Definir tamanho maximo das strings e da lista
  2- Declarar globalmente n(tamanho atual da string) e um array com o tamanho máximo
  3- Inicializar a lista com método start
  4- Popular com métodos inserir, remover e mostrar necessários
    4.1- Inserir
      4.1.1- checar se a posição de inserção é maior que o tamanho atual, máximo, ou menor que 0
      4.1.2- alocar dinamicamente 1 posição a mais para o elemento sendo inserido
      4.1.3- for, começando do ultimo elemento, copiando todos os elementos uma posição para frente até chegar na posição
  5- Se necessário, implementar strtok(lembrar do scanf com multiplas entradas)

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 6
#define MAXLENGTH 51

int n;
char* array[MAXTAM];

void start(){
    n=0;
}

void inserir(char* string, int pos){
    if(pos>n || pos<0 || n>=MAXTAM){
        exit(1);
    }

    array[n+1] = malloc((strlen(string) + 1) * sizeof(char));

    for (int i = n; i > pos; i--)
    {
        strcpy(array[i], array[i-1]);   
    }
    array[pos] = malloc((strlen(string) + 1) * sizeof(char));
    strcpy(array[pos], string);
    n++;
}

char* remover(int pos){
    if(n == 0){
        exit(1);
    }

    char *resp = malloc(51 * sizeof(char));
    strcpy(resp, array[pos]);
    n--;

    for(int i=pos; i<n; i++){
        strcpy(array[i], array[i+1]);
    }
    return resp;
}

void mostrar(){
    printf("[ ");
    for(int i=0; i<n; i++){
        printf("%s ", array[i]);
    }
    printf("]\n");
}

char* strtokSingle (char * str, char const * delims){
  static char  * src = NULL;
  char  *  p,  * ret = 0;

  if (str != NULL)
    src = str;

  if (src == NULL)
    return NULL;

  if ((p = strpbrk (src, delims)) != NULL) {
    *p  = 0;
    ret = src;
    src = ++p;

  } else if (*src) {
    ret = src;
    src = NULL;
  }

  return ret;
}

int main(){
    start();
    
    inserir("miguel", 0);
    mostrar();
    inserir("clara", 1);
    mostrar();
    inserir("felipe", 0);
    mostrar();
    inserir("paulo", 1);
    mostrar();
    inserir("jaime", n);
    mostrar();
    printf("\n-------------------------\nfim insercao\n-------------------------\n");

    printf("Elemento removido: %s\n", remover(n/2));
    mostrar();
    printf("Elemento removido: %s\n", remover(0));
    mostrar();
    printf("Elemento removido: %s\n", remover(n));
    mostrar();

    return 0;
}