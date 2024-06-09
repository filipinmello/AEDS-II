#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[101]; 
    int peso;
    int idade;
    float altura;
}Rena;

/*
Ordem
1- peso, decrescente
2- idade, ascentdente
3- altura, ascendente
4- nome, ascendente
*/

void sort(Rena array[], int N){
    for (int i = 1; i < N; i++)
    {
        Rena tmp = array[i];
        int j = i-1;
        while(j>0 && array[j].peso < tmp.peso || (array[j].peso == tmp.peso && array[j].idade > tmp.idade) || (array[j].peso == tmp.peso && array[j].idade == tmp.idade && array[j].altura > tmp.altura)){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1]=tmp;
    }
}

int main(){
    int T;
    scanf(" %d", &T);

    for (int j = 0; j < T; j++)
    {
        int N, M;
        scanf(" %d %d", &N, &M);
        Rena array[N];

        for (int i = 0; i < N; i++)
        {
            scanf(" %s %d %d %f", array[i].nome, &array[i].peso, &array[i].idade, &array[i].altura);
        }

        sort(array, N);

        printf("CENARIO {%d}\n", T);
        for (int i = 0; i < M; i++)
        {
            printf("%d - %s\n", i+1, array[i].nome);
        }
    }
    
    return 0;
}