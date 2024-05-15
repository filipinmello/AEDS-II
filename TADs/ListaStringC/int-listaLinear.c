#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 6

int n;
int array[MAXTAM];

void start(){
    int n = 0;
}

void inserir(int elem, int pos){
    if(pos>n || pos<0 || n>=MAXTAM){
        exit(1);
    }

    for(int i=n; i>pos; i--){
        array[i] = array[i-1];
    }
    array[pos]=elem;
    n++;
}

int remover(int pos){
    if(n==0){
        exit(1);
    }

    int resp = array[pos];
    n--;

    for (int i = pos; i < n; i++)
    {
        array[i] = array[i+1];
    }
    return resp;
}

void mostrar(){
    printf("[ ");
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");
}


int main(){
    strcpy("testearray", array[0]);
    printf("\n%s\n", array[0]);
    inserir(12, 0);
    inserir(4, n);
    inserir(8, 2);
    inserir(5, 0);

    mostrar();

    printf("Elemento removido: %d\n", remover(2));
    mostrar();

    return 0;
}