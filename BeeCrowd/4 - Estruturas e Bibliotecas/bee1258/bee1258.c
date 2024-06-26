/*
A entrada contém vários casos de teste. Cada caso de teste inicia com um valor N, (1 ≤ N ≤ 60) inteiro e positivo, que indica a quantidade de camisetas a serem feitas para aquela turma. 
As próximas N*2 linhas contém informações de cada uma das camisetas (serão duas linhas de informação para cada camiseta). 
A primeira linha irá conter o nome do estudante e a segunda linha irá conter a cor do logo da camiseta ("branco" ou "vermelho") seguido por um espaço e pelo tamanho da camiseta "P" "M" ou "G". 
A entrada termina quando o valor de N for igual a zero (0) e esta valor não deverá ser processado.

Para cada caso de entrada deverão ser impressas as informações ordenadas pela cor dos detalhes em ordem ascendente, 
seguido pelos tamanhos em ordem descendente e por último por ordem ascendente de nome, conforme o exemplo do pub.in.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    char cor[50];
    char tamanho;
}Camisa;

char* lerUmaLinha(){
    char* resp = (char*)malloc(100 * sizeof(char));
    scanf(" %[^\n]", resp);
    return resp;
}

void mostrar(Camisa array[], int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("%s %c %s\n", array[i].cor, array[i].tamanho, array[i].nome);
    }
}

void ordenar(Camisa array[], int tam){
    Camisa tmp;
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if(strcmp(array[j].cor, array[i].cor) > 0){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }else if(strcmp(array[j].cor, array[i].cor) == 0 && array[j].tamanho < array[i].tamanho){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }else if(strcmp(array[j].cor, array[i].cor) == 0 && array[j].tamanho == array[i].tamanho && strcmp(array[j].nome, array[i].nome) > 0){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int main(){
    int N;
    scanf(" %d", &N);
    Camisa alunos[N];

    while (N !=0)
    {
        for (int i = 0; i < N; i++)
        {
            strcpy(alunos[i].nome, lerUmaLinha());
            scanf(" %s %c", alunos[i].cor, &alunos[i].tamanho);
        }

        ordenar(alunos, N);
        mostrar(alunos, N);
        
        scanf(" %d", &N);
        printf("\n");
    }

   return 0; 
}