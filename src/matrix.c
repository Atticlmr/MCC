#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double **)malloc(rows * sizeof(double *));
    if (matrix->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < rows; ++i) {
        matrix->data[i] = (double *)malloc(cols * sizeof(double));
        if (matrix->data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    return matrix;
}

void freeMatrix(Matrix *matrix) {
    if (matrix != NULL) {
        for (int i = 0; i < matrix->rows; ++i) {
            free(matrix->data[i]);
        }
        free(matrix->data);
        free(matrix);
    }
}

void printMatrix(const Matrix *matrix) {
    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            printf("%f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *addMatrices(const Matrix *A, const Matrix *B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        fprintf(stderr, "Matrices dimensions do not match\n");
        return NULL;
    }

    Matrix *result = createMatrix(A->rows, A->cols);
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->cols; ++j) {
            result->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
    return result;
}

Matrix *multiplyMatrices(const Matrix *A, const Matrix *B) {
    if (A->cols != B->rows) {
        fprintf(stderr, "Incompatible matrices for multiplication\n");
        return NULL;
    }

    Matrix *result = createMatrix(A->rows, B->cols);
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < B->cols; ++j) {
            result->data[i][j] = 0;
            for (int k = 0; k < A->cols; ++k) {
                result->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
    return result;
}

Matrix *transposeMatrix(const Matrix *A) {
    Matrix *result = createMatrix(A->cols, A->rows);
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->cols; ++j) {
            result->data[j][i] = A->data[i][j];
        }
    }
    return result;
}