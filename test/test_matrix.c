#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix *A = createMatrix(2, 2);
    A->data[0][0] = 1.0; A->data[0][1] = 2.0;
    A->data[1][0] = 3.0; A->data[1][1] = 4.0;

    Matrix *B = createMatrix(2, 2);
    B->data[0][0] = 5.0; B->data[0][1] = 6.0;
    B->data[1][0] = 7.0; B->data[1][1] = 8.0;

    Matrix *C = multiplyMatrices(A, B);
    printMatrix(C);

    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);

    return 0;
}