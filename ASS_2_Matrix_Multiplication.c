#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int rows, int cols) {
    int** mat = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        mat[i] = (int*) malloc(cols * sizeof(int));
    return mat;
}

void fillMatrix(int **mat, int rows, int cols) {
    printf("Input elements for a %d x %d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

int** matrixProduct(int **X, int **Y, int r1, int c1, int c2) {
    int **result = allocateMatrix(r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
    return result;
}

void printMatrix(int **mat, int rows, int cols) {
    printf("Matrix content (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int rA, cA, rB, cB;
    printf("Dimensions for first matrix (rows columns): ");
    scanf("%d %d", &rA, &cA);
    printf("Dimensions for second matrix (rows columns): ");
    scanf("%d %d", &rB, &cB);

    if (cA != rB) {
        printf("Cannot multiply. Number of columns in Matrix A must match number of rows in Matrix B.\n");
        return 1;
    }

    int **A = allocateMatrix(rA, cA);
    int **B = allocateMatrix(rB, cB);

    printf("\nFirst matrix:\n");
    fillMatrix(A, rA, cA);
    printf("\nSecond matrix:\n");
    fillMatrix(B, rB, cB);

    int **C = matrixProduct(A, B, rA, cA, cB);

    printf("\nProduct matrix:\n");
    printMatrix(C, rA, cB);

    for (int i = 0; i < rA; i++) free(A[i]);
    for (int i = 0; i < rB; i++) free(B[i]);
    for (int i = 0; i < rA; i++) free(C[i]);
    free(A); free(B); free(C);
    return 0;
}
