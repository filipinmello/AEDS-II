#include "selecao.h"
//=============================================================================
void selectionSort(int *array, int n, int index) {
    if (index >= n - 1) 
        return;

    int minIndex = index;
    for (int j = index + 1; j < n; j++) {
        if (array[j] < array[minIndex]) {
            minIndex = j;
        }
    }
    swap(&array[minIndex], &array[index]);

    selectionSort(array, n, index + 1);
}

void selecao(int *array, int n) {
    selectionSort(array, n, 0); 
}
//=============================================================================