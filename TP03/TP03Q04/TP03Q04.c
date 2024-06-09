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

//TIPO CELULA ===================================================================
typedef struct Celula {
	Personagem elemento; // Elemento inserido na celula.
	struct Celula* prox; // Aponta a celula prox.
} Celula;

Celula* novaCelula(Personagem elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;
   return nova;
}

//FILA PROPRIAMENTE DITA ========================================================
Celula* primeiro;
Celula* ultimo;
int tam;


/**
 * Cria uma fila sem elementos (somente no cabeca).
 */
void start() {
    Personagem valorPadrao;
    primeiro = novaCelula(valorPadrao);
    ultimo = primeiro;
    primeiro->prox = primeiro; // INICIO CIRCULAR
    ultimo->prox = primeiro;
    tam = 0;
}


/**
 * Insere elemento na fila (politica FIFO).
 * @param x int Elemento a inserir.
 */
void inserir(Personagem x) {
    Celula* nova = novaCelula(x);
    if (tam == 0) {
        primeiro->prox = nova;
    } else {
        ultimo->prox = nova;
    }
    ultimo = nova;
    if(primeiro->prox == NULL){
        ultimo->prox = primeiro; // MANTER CIRCULAR
    }
    tam++;
}


/**
 * Remove elemento da fila (politica FIFO).
 * @return Elemento removido.
 */
Personagem remover() {
    if (tam == 0) {
        printf("Queue is empty!\n");
        Personagem emptyElement;
        return emptyElement;
    }
    Celula* tmp = primeiro->prox;
    Personagem resp = tmp->elemento;
    primeiro->prox = tmp->prox;
    if (ultimo == tmp) {
        ultimo = primeiro;
        primeiro->prox = primeiro;
    }
    free(tmp);
    tam--;
    return resp;
}


/**
 * Mostra os elementos separados por espacos.
 */
void mostrar() {
   Celula* i;
   int count = 0;
   printf("[ Head ]\n");
   for (i = primeiro->prox; i != NULL; i = i->prox) {
        printf("[%d ## ", count);
        imprimir(i->elemento);
        count++;
   }
   printf("[ Tail ]\n");
}
//FIM FILA==================================================================================


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

int averageBirth(){
    int averageBirth = 0;
    Celula* i;

    for (i = primeiro->prox; i != NULL; i = i->prox) {
        averageBirth += i->elemento.yearOfBirth;
    }

    return averageBirth/tam;
}

int main(){
    start();
    char *tokens[MAX_TOKENS];
    const char *fileName = "/tmp/characters.csv";
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
                if(tam == 5){
                    remover();
                    inserir(personagens[i]);
                    printf(">> Year Birthday Average: %d\n", averageBirth());
                } else{
                    inserir(personagens[i]);
                    printf(">> Year Birthday Average: %d\n", averageBirth());
                }
            }
        }
        scanf(" %s", input);
    }
    
    int N;
    char input2[100];
    char **values = malloc(3 * sizeof(char*));

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %[^\r\n]", input2);
        values[0] = strtok(input2, " ");
        values[1] = strtok(NULL, " ");
        values[2] = strtok(NULL, " ");
        
        if(strcmp(values[0], "I") == 0) {
            if(tam == 5){
                remover();
                inserir(buscarPersonagem(personagens, values[1]));
                printf(">> Year Birthday Average: %d\n", averageBirth());
            }else{
                inserir(personagens[i]);
                printf(">> Year Birthday Average: %d\n", averageBirth());
            }
        }else if(strcmp(values[0], "R") == 0) {
            Personagem removido = remover(0);
            printf("(R) %s\n", removido.name);
        }
    }

    mostrar();
    return 0;
}
