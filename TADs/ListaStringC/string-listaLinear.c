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

strtokSingle (char * str, char const * delims){
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
    printf("\n-------------------------\nfim insercao\n-------------------------\n");

    printf("Elemento removido: %s\n", remover(1));
    mostrar();

    return 0;
}