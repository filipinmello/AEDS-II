#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

    //char*[] alternateNames
    strcpy(p.alternateNames, alternateNames);

    strcpy(p.house, house);
    strcpy(p.ancestry, ancestry);
    strcpy(p.species, species);
    strcpy(p.patronus, patronus);
    //bool hogwartsStaff
    p.hogwartsStaff = (strcmp(hogwartsStaff, "VERDADEIRO") == 0);
    //bool hogwartsStudent
    p.hogwartsStudent = (strcmp(hogwartsStudent, "VERDADEIRO") == 0);

    strcpy(p.actorName, actorName);
    //bool alive
    p.alive = (strcmp(alive, "VERDADEIRO") == 0);

    strcpy(p.alternateActors, alternateActors);
    strcpy(p.dateOfBirth, dateOfBirth);
    //int yearOfBirth
    p.yearOfBirth = atoi(yearOfBirth);

    strcpy(p.eyeColour, eyeColour);
    strcpy(p.gender, gender);
    strcpy(p.hairColour, hairColour);
    //bool wizard
    p.wizard = (strcmp(wizard, "VERDADEIRO") == 0);
    
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

    printf("%s", e.dateOfBirth);
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

int main(){
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
    while (fgets(line, sizeof(line), file) != NULL) {
        if(i>0){
            parseString(line, tokens);
            personagens[i] = createPersonagem(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9], tokens[10], 
                                            tokens[11], tokens[12], tokens[13], tokens[14], tokens[15], tokens[16], tokens[17]);
            //imprimir(personagens[i]);
        }
        i++;
    }
    fclose(file);
    
    char input[200][200];
    char inputLine[200];
    int index = 0;

    do {
        fgets(inputLine, 200, stdin);
        inputLine[strcspn(inputLine, "\n")] = '\0';

        if (strcmp(inputLine, "FIM") != 0) {
            strcpy(input[index], inputLine);
            index++;
        }
    } while (strcmp(inputLine, "FIM") != 0);

    // for (int i = 0; i < index; i++) {
    //     printf("%s\n", input[i]);
    // }

    for (int i=0; i<index; i++) {
            for(int j=0; j<405; j++){
                //printf("%d\n %s\n %s\n", strcmp(personagens[j].id, input[i]), personagens[j].id, input[i]);
                if(personagens[j].id != NULL && (strcmp(personagens[j].id, input[i])) == 0){
                    imprimir(personagens[j]);
                }
            }
        }



    // scanf("%[^\n]", input);
    // parseString(input, tokens);

    // printf("-------------------------\n");
    //  for (int i = 0; i < MAX_TOKENS; i++) { //teste tokenizacao
    //      printf("Token %d: %s\n", i, tokens[i]);
    //  }
    // printf("-------------------------\n");

    return 0;
}
