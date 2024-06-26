#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lerUmChar(){
    char resp;
    printf("Digite uma letra: ");
    scanf(" %c", &resp);
    return resp;
}

char* lerUmaPalavra(){
    char* resp = (char*)malloc(100 * sizeof(char));
    printf("Digite uma palavra: ");
    scanf(" %s", resp);
    return resp;
}

char* lerUmaLinha(){
    char* resp = (char*)malloc(100 * sizeof(char));
    printf("Digite uma linha: ");
    scanf(" %[^\n]", resp);
    return resp;
}

int lerUmInt(){
    int resp;
    printf("Digite um numero: ");
    scanf(" %d", &resp);
    return resp;
}

int main(){
    char letra;
    int num;
    char palavra[100] = "";
    char linha[100] = "";

    //Ler um inteiro
    // num = lerUmInt();

    //Ler N chars
    // for(int i = 0; i < N; i++){
    //     letra = lerUmChar();
    //     printf("Letra: %c\n", letra);
    // }

    //Ler N palavras
    // for(int i = 0; i < N; i++){
    //     strcpy(palavra, lerUmaPalavra());
    //     printf("Palavra: %s\n", palavra);
    // }

    //Ler palavras até FIM
    // do{
    //     strcpy(palavra, lerUmaPalavra()); 
    //     if(strcmp(palavra, "FIM") != 0){
    //         printf("Palavra: %s\n", palavra);
    //     }
    // }while(strcmp(palavra, "FIM") != 0);

    //Ler linhas até FIM
    do{
        strcpy(linha, lerUmaLinha());
        if(strcmp(linha, "FIM") != 0){
            printf("Linha: %s\n", linha);
        }
    }while(strcmp(linha, "FIM") != 0);

    return 0;
}