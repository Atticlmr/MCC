#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

Matrix *createMatrix(int rows, int cols);
void freeMatrix(Matrix *matrix);
void printMatrix(const Matrix *matrix);
Matrix *addMatrices(const Matrix *A, const Matrix *B);
Matrix *multiplyMatrices(const Matrix *A, const Matrix *B);
Matrix *transposeMatrix(const Matrix *A);

#endif // MATRIX_H