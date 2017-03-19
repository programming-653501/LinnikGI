//3.2 (15). Тени. В трехмерном массиве k(l, m, n), состоящем из нулей и единиц, хранится сеточное изображение
//некоторого трехмерного тела. Получить в двумерных массивах три проекции (тени) этого тела.

#include <stdio.h>
#include <stdlib.h>

void printLayers(int ***, int);
void printMatrix(int **, int);
int ***alloc3DArrayOfSize(int);
int **alloc2DArrayOfSize(int);

typedef enum scanOptions {FrontScan, UpperScan, SideScan} scanOptions;
int **shadowFrom3DArray(int ***, int, scanOptions);

int main() {
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);

    int ***_3DArray = alloc3DArrayOfSize(size);

    //Initializing pyramid
    for (int i = 0, sidesShift = 0; i < size; ++i, ++sidesShift) { //3-rd dimension
        for (int j = 0; j < size - sidesShift; ++j) { //2-nd dimension
            for (int k = sidesShift; k < size - sidesShift; ++k) { //1-st dimension
                //Yeah, fireball bitch!
                _3DArray[i][j][k] = 1;
            }
        }
    }

    //printLayers(_3DArray, size);

    int **frontShadow = shadowFrom3DArray(_3DArray, size, FrontScan);
    int **upperShadow = shadowFrom3DArray(_3DArray, size, UpperScan);
    int **sideShadow = shadowFrom3DArray(_3DArray, size, SideScan);

    printf("Front:\n");
    printMatrix(frontShadow, size);

    printf("\nUpper:\n");
    printMatrix(upperShadow, size);

    printf("\nSide:\n");
    printMatrix(sideShadow, size);
    //Here should be memory deallocation of all arrays, but I'm too lazy
    return 0;
}

void printLayers(int ***array, int size) {
    for (int i = 0; i < size; ++i) { //3-rd dimension
        printf("\nLayer %d:\n", i);
        for (int j = 0; j < size; ++j) { //2-nd dimension
            for (int k = 0; k < size; ++k) { //1-st dimension
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
    }
}

int ***alloc3DArrayOfSize(int size) {
    int ***temp = (int ***)calloc(size, sizeof(int **));
    for (int i = 0; i < size; ++i) {
        temp[i] = (int **)calloc(size, sizeof(int *));
        for (int j = 0; j < size; ++j) {
            temp[i][j] = (int *)calloc(size, sizeof(int));
        }
    }
    return temp;
}

int **alloc2DArrayOfSize(int size) {
    int **temp = (int **)calloc(size, sizeof(int *));
    for (int i = 0; i < size; ++i) {
        temp[i] = (int *)calloc(size, sizeof(int));
    }
    return temp;
}

void printMatrix(int **array, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int **shadowFrom3DArray(int ***array, int size, scanOptions option) {
    int **tempMatrix = alloc2DArrayOfSize(size);
    for (int i = 0; i < size; ++i) {
        for (int j = size - 1; j >= 0; --j) {
            for (int k = 0; k < size; ++k) {
                if (!tempMatrix[abs(j - (size - 1))][k]) {
                    switch (option) {
                        case FrontScan:
                            tempMatrix[abs(j - (size - 1))][k] = array[j][i][k];
                            break;
                        case SideScan:
                            tempMatrix[abs(j - (size - 1))][k] = array[j][k][i];
                            break;
                        case UpperScan:
                            tempMatrix[abs(j - (size - 1))][k] = array[i][j][k];
                            break;
                    }
                }
            }
        }
    }
    return tempMatrix;
}
