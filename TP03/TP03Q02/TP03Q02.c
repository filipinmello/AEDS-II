#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM 405
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

void imprimir();

int n;
Personagem lista[MAXTAM];

void start(){
    int n = 0;
}

void inserir(Personagem elem, int pos){
    if(pos>n || pos<0 || n>=MAXTAM){
        exit(1);
    }

    for(int i=n; i>pos; i--){
        lista[i] = lista[i-1];
    }
    lista[pos] = elem;
    n++;
}

Personagem remover(int pos){
    if(n==0){
        exit(1);
    }

    Personagem resp = lista[pos];
    n--;

    for (int i = pos; i < n; i++)
    {
        lista[i] = lista[i+1];
    }
    return resp;
}

void mostrar(){
    for(int i=0; i<n-1; i++){
        printf("[%d ## ", i);
        imprimir(lista[i]);
    }
}


char * strtokSingle (char * str, char const * delims){
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

Personagem buscarPersonagem(Personagem *array, char *targetId) {
    Personagem resp;
    int i = 0;
    while (array[i].id != NULL) {
        if (strcmp(array[i].id, targetId) == 0) {
            resp = array[i];
            return resp;
        }
        i++;
    }
    printf("Personagem nao encontrado!\n");
    return (Personagem){0}; 
}

int main(){
    start();
    char *tokens[MAX_TOKENS];
    const char *fileName = "characters.csv";
    Personagem *personagens;
    personagens = (Personagem *)malloc(405 * sizeof(Personagem));

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
    }

    char line[1024];
    int i = 0;
    while (fscanf(file, "%[^\n]%*c", line) != EOF) { //preencher personagens[] com todos os itens do arquivo csv
        if(i>0){
            parseString(line, tokens);
            personagens[i] = createPersonagem(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], 
                                            tokens[11], tokens[12], tokens[13], tokens[14], tokens[15], tokens[16], tokens[17]);
            //imprimir(personagens[i]);
        }
        i++;
    }
    fclose(file);
    
    char input[100];
    scanf(" %s", input);

    while(strcmp(input, "FIM") != 0){ //preencher a lista com todos os personagens do input até FIM
        for(int i = 1;i<405;i++){
            if(strcmp(personagens[i].id,input) == 0){
                inserir(personagens[i], n);
            }
        }
        scanf(" %s", input);
    }
    
    int N;
    char input2[100];
    char **values = malloc(3 * sizeof(char*));

    scanf("%d", &N);
    //funfa ate aq

    for (int i = 0; i < N; i++) {
        scanf(" %[^\r\n]", input2);
        values[0] = strtok(input2, " ");
        values[1] = strtok(NULL, " ");
        values[2] = strtok(NULL, " ");
        
        if(strcmp(values[0], "II") == 0) {
            inserir(buscarPersonagem(personagens, values[1]), 0); //inserirInicio
        } else if(strcmp(values[0], "IF") == 0) {
            inserir(buscarPersonagem(personagens, values[1]), n-1); //inserirFim
        } else if(strcmp(values[0], "I*") == 0) {
            int index = atoi(values[1]);
            inserir(buscarPersonagem(personagens, values[2]), index);
        } else if(strcmp(values[0], "RI") == 0) {
            Personagem removido = remover(0); //removerInicio
            printf("(R) %s\n", removido.name, n);
        } else if(strcmp(values[0], "RF") == 0) {
            Personagem removido = remover(n-1); //removerFim
            printf("(R) %s\n", removido.name, n);
        } else if(strcmp(values[0], "R*") == 0) {
            int index = atoi(values[1]);
            Personagem removido = remover(index);
            printf("(R) %s\n", removido.name, n);
        }
    }

    mostrar();
    return 0;
}
