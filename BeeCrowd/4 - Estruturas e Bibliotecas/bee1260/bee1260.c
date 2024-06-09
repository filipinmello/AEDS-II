#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 31
#define MAXTAM 1000000

int n;
char* array[MAXTAM];

void start(){
    n=0;
}

void inserir(char* string, int pos){
    if(pos<0 || pos>n || n>=MAXTAM){
        exit(0);
    }

    array[n+1] = malloc(MAXLEN * sizeof(char));

    for (int i = n; i > pos; i--)
    {
        strcpy(array[i], array[i-1]);   
    }
    array[pos] = malloc(MAXLEN * sizeof(char));
    strcpy(array[pos], string);
    n++;
}

void limpar(){
    n=0;
}

void readInput() {
    char avre[MAXLEN];

    while (fgets(avre, sizeof(avre), stdin) != NULL && avre[0] != '\n') {
        if (avre[strlen(avre) - 1] == '\n') {
            avre[strlen(avre) - 1] = '\0';
        }
        
        inserir(avre, n);
    }
}

void ocorrencias() {
    for (int i = 0; i < n; i++) {
        int speciesCount = 1;
        char currentTree[MAXLEN];
        strcpy(currentTree, array[i]); 
        
        while (i + 1 < n && strcmp(currentTree, array[i + 1]) == 0) {
            speciesCount++;
            i++;
        }
        
        float percent = ((float)speciesCount*100)/n;

        printf("%s %.4f\n", currentTree, percent);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void sort(){
    for(int i=0; i<n; i++){
        char tmp[MAXLEN];
        strcpy(tmp, array[i]);
        int j = i-1;
        while((j>=0) && (strcmp(array[j], tmp))>0){
            strcpy(array[j+1], array[j]);
            j--;
        }
        strcpy(array[j+1], tmp);
    }
}

int main() {
    start();

    int N;
    scanf(" %d", &N);
    getchar();

    clearBuffer();
    for (int i = 0; i < N; i++)
    {
        readInput();
        sort();
        ocorrencias();
        limpar();
        printf("\n");
    }
    
    return 0;
}