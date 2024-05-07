#include "heapsort.h"
//=============================================================================
void construir(int *array, int tamHeap){
    for(int i = tamHeap; i > 1 && array[i] > array[i/2]; i /= 2){
        swap(array + i, array + i/2);
    }
}
//=============================================================================
int getMaiorFilho(int *array, int i, int tamHeap){
    int filho;
    if (2*i == tamHeap || array[2*i] > array[2*i+1]){
        filho = 2*i;
    } else {
        filho = 2*i + 1;
    }
    return filho;
}
//=============================================================================
void reconstruir(int *array, int tamHeap){
    int i = 1;
    while(i <= (tamHeap/2)){
        int filho = getMaiorFilho(array, i, tamHeap);
        if(array[i] < array[filho]){
            swap(array + i, array + filho);
            i = filho;
        }else{
            i = tamHeap;
        }
    }
}
//=============================================================================
void heapsort(int *array, int n) {
    //Alterar o vetor ignorando a posicao zero
    int arrayTmp[n+1];
    for(int i = 0; i < n; i++){
        arrayTmp[i+1] = array[i];
    }

    //Contrucao do heap
    for(int tamHeap = 2; tamHeap <= n; tamHeap++){
        construir(arrayTmp, tamHeap);
    }

    //Ordenacao propriamente dita
    int tamHeap = n;
    while(tamHeap > 1){
        swap(arrayTmp + 1, arrayTmp + tamHeap--);
        reconstruir(arrayTmp, tamHeap);
    }

    //Alterar o vetor para voltar a posicao zero
    for(int i = 0; i < n; i++){
        array[i] = arrayTmp[i+1];
    }
}
//=============================================================================


// Function to construct the heap
void construir(struct Personagem *array, int tamHeap) {
    for(int i = tamHeap; i > 1 && strcmp(array[i].hairColour, array[i/2].hairColour) > 0; i /= 2) {
        swap(array, i, i/2);
    }
}

// Function to get the index of the largest child
int getMaiorFilho(struct Personagem *array, int i, int tamHeap) {
    int filho;
    if (2*i == tamHeap || strcmp(array[2*i].hairColour, array[2*i+1].hairColour) > 0) {
        filho = 2*i;
    } else {
        filho = 2*i + 1;
    }
    return filho;
}

// Function to rebuild the heap
void reconstruir(struct Personagem *array, int tamHeap) {
    int i = 1;
    while(i <= (tamHeap/2)) {
        int filho = getMaiorFilho(array, i, tamHeap);
        if(strcmp(array[i].hairColour, array[filho].hairColour) < 0) {
            swap(array, i, filho);
            i = filho;
        } else {
            i = tamHeap;
        }
    }
}

// Heapsort function
void heapsort(struct Personagem *array, int n) {
    struct Personagem arrayTmp[n+1];
    memcpy(arrayTmp + 1, array, n * sizeof(struct Personagem));

    for(int tamHeap = 2; tamHeap <= n; tamHeap++) {
        construir(arrayTmp, tamHeap);
    }

    int tamHeap = n;
    while(tamHeap > 1) {
        swap(arrayTmp, 1, tamHeap--);
        reconstruir(arrayTmp, tamHeap);
    }

    memcpy(array, arrayTmp + 1, n * sizeof(struct Personagem));
}

