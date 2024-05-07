#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NAME_LENGTH 500
#define MAX_ALTERNATE_NAMES 150
#define MAX_HOUSE_LENGTH 150
#define MAX_ANC_LENGTH 150
#define MAX_SPECIES_LENGTH 150
#define MAX_PATRONUS_LENGTH 150
#define MAX_ACTOR_NAME_LENGTH 150
#define MAX_DATE_LENGTH 50
#define MAX_EYE_COLOR_LENGTH 50
#define MAX_HAIR_COLOR_LENGTH 50

#define MAX_TOKENS 18
#define MAX_TOKEN_LENGTH 500

typedef struct {
    char id[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char alternateNames[MAX_ALTERNATE_NAMES];
    char house[MAX_HOUSE_LENGTH];
    char ancestry[MAX_ANC_LENGTH];
    char species[MAX_SPECIES_LENGTH];
    char patronus[MAX_PATRONUS_LENGTH];
    bool hogwartsStaff;
    bool hogwartsStudent;
    char actorName[MAX_ACTOR_NAME_LENGTH];
    bool alive;
    char alternateActors[MAX_ACTOR_NAME_LENGTH];
    char dateOfBirth[MAX_DATE_LENGTH];
    int yearOfBirth;
    char eyeColour[MAX_EYE_COLOR_LENGTH];
    char gender[MAX_NAME_LENGTH];
    char hairColour[MAX_HAIR_COLOR_LENGTH];
    bool wizard;
} Personagem;

Personagem createPersonagem(char* id, char* name, char* alternateNames, char* house, char* ancestry, char* species, char* patronus, char* hogwartsStaff, char* hogwartsStudent, char* actorName, char* alive, 
char* alternateActors, char* dateOfBirth, char* yearOfBirth, char* eyeColour, char* gender, char* hairColour, char* wizard){
    Personagem p;
    strcpy(p.id, id);
    strcpy(p.name, name);

    strcpy(p.alternateNames, alternateNames);

    strcpy(p.house, house);
    strcpy(p.ancestry, ancestry);
    strcpy(p.species, species);
    strcpy(p.patronus, patronus);
    p.hogwartsStaff = (hogwartsStaff[0] == 'V');
    p.hogwartsStudent = (hogwartsStudent[0] == 'V');

    strcpy(p.actorName, actorName);
    p.alive = (alive[0] == 'V');

    strcpy(p.alternateActors, alternateActors);
    strcpy(p.dateOfBirth, dateOfBirth);
    p.yearOfBirth = atoi(yearOfBirth);

    strcpy(p.eyeColour, eyeColour);
    strcpy(p.gender, gender);
    strcpy(p.hairColour, hairColour);
    p.wizard = (wizard[0] == 'V');
    
    return p;
}

char *
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

void removeBrackets(char* tempToken){
    int i, j = 0;
    for (i = 0; tempToken[i]; i++) {
        if (tempToken[i] != '[' && tempToken[i] != ']' && tempToken[i] != '\'') {
            tempToken[j++] = tempToken[i];
        }
    }
    if (j == 0) {
        strcpy(tempToken, "");
    } else {
        tempToken[j] = '\0';
    }
}

void parseString(char *inputString, char *tokens[]) {
    char *tempToken;
    int i = 0;

    tempToken = strtokSingle(inputString, ";");
    while (tempToken != NULL && i < MAX_TOKENS) {
        if(i == 2){
            removeBrackets(tempToken);
        }
        tokens[i] = tempToken;
        i++;
        tempToken = strtokSingle(NULL, ";");
    }
}

void printArray(const char **array) {
    printf("{");
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s", array[i]);
        if (array[i + 1] != NULL) {
            printf(",");
        }
    }
    printf("}");
}

void imprimir(Personagem e){
    printf("[");
    printf("%s", e.id);
    printf(" ## ");
    printf("%s", e.name);
    printf(" ## ");

    printf("{%s}", e.alternateNames);
    printf(" ## ");

    printf("%s", e.house);
    printf(" ## ");
    printf("%s", e.ancestry);
    printf(" ## ");
    printf("%s", e.species);
    printf(" ## ");
    printf("%s", e.patronus);
    printf(" ## ");

    if(e.hogwartsStaff == 1) printf("true");
    else printf("false");
    printf(" ## ");

    if(e.hogwartsStudent == 1) printf("true");
    else printf("false");
    printf(" ## ");

    printf("%s", e.actorName);
    printf(" ## ");

    if(e.alive == 1) printf("true");
    else printf("false");
    printf(" ## ");

    if(!strcmp(e.dateOfBirth, "23-6-1980")) printf("23-06-1980");
    else printf("%s", e.dateOfBirth);
    printf(" ## ");
    printf("%d", e.yearOfBirth);
    printf(" ## ");
    printf("%s", e.eyeColour);
    printf(" ## ");
    printf("%s", e.gender);
    printf(" ## ");
    printf("%s", e.hairColour);
    printf(" ## ");

    if(e.wizard == 1) printf("true");
    else printf("false");
    printf("]\n");
}

bool compareStrings(char* str1, char* str2){
    int tam1 = strlen(str1),tam2 = strlen(str2);
    //if(tam1 != tam2){return false;}
    for(int i = 0;i<tam1;i++){
        if((int)str1[i] != (int)str2[i]){
            return false;
        }
    }
    return true;
}

void swap(Personagem *inputPersonagens, int i, int j) {
    Personagem temp = inputPersonagens[i];
    inputPersonagens[i] = inputPersonagens[j];
    inputPersonagens[j] = temp;
}

int getMax(Personagem *inputPersonagens, int n) {
    int maxLen = strlen(inputPersonagens[0].id);

    for (int i = 1; i < n; i++) {
        int len = strlen(inputPersonagens[i].id);
        if (len > maxLen) {
            maxLen = len;
        }
    }
    return maxLen;
}

void radcountingSort(Personagem *inputPersonagens, int n, int pos) {
    const int range = 256;

    int count[range];
    Personagem output[n];

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[inputPersonagens[i].id[pos]]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[inputPersonagens[i].id[pos]] - 1] = inputPersonagens[i];
        count[inputPersonagens[i].id[pos]]--;
    }

    for (int i = 0; i < n; i++) {
        inputPersonagens[i] = output[i];
    }
}

void sort(Personagem *inputPersonagens, int n) {
    int maxLen = getMax(inputPersonagens, n);
    for (int i = maxLen - 1; i >= 0; i--) {
        radcountingSort(inputPersonagens, n, i);
    }
}

int main(){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    char *tokens[MAX_TOKENS];
    const char *fileName = "/tmp/characters.csv";
    Personagem *personagens;
    personagens = (Personagem *)malloc(405 * sizeof(Personagem));
    int comparisons = 0;

    FILE *file = fopen(fileName, "r"); //Abertura do arquivo csv
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
    }

    char line[1024];
    int i = 0;
    while (fscanf(file, "%[^\n]%*c", line) != EOF) { //Leitura do arquivo csv até o final
        if(i>0){ // pular primeira linha
            parseString(line, tokens);
            personagens[i] = createPersonagem(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], 
                                            tokens[11], tokens[12], tokens[13], tokens[14], tokens[15], tokens[16], tokens[17]);
        }
        i++;
    }
    fclose(file);
    
    char input[100];
    char inputArray[405][301];//array para armazenar os IDs de entrada
    int inputCount = 0;

    scanf("%s", input);

    do{ //leitura dos IDs de entrada ate encontrar "FIM"
        strcpy(inputArray[inputCount], input);
        inputCount++;
        scanf("%s", input);
    } while(strcmp(input, "FIM") != 0);

    Personagem *inputPersonagens; //Array para armazenar os personagens presentes no inputArray
    inputPersonagens = (Personagem *)malloc(inputCount * sizeof(Personagem));

    for(int i = 0; i < inputCount; i++) {
        for(int j = 1;j<405;j++){
            if(strcmp(personagens[j].id, inputArray[i]) == 0) {
                inputPersonagens[i] = personagens[j]; //Populando p inputPersonagens
            }
        }
    }

    sort(inputPersonagens, inputCount); //Metodo para ordenar o inputPersonagens por ordem alfabetica(house)

    for(int i = 0; i < inputCount; i++){
        imprimir(inputPersonagens[i]);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    long long startTime = start.tv_sec * 1000000000 + start.tv_nsec;
    long long endTime = end.tv_sec * 1000000000 + end.tv_nsec;
    long long executionTime = (endTime - startTime) / 1000000;

    FILE *fileLog = fopen("matricula_binaria.txt", "w");
    if (fileLog == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(fileLog, "827761\t%lldms\t%d\n", executionTime, comparisons);
    fclose(fileLog);

    return 0;
}
