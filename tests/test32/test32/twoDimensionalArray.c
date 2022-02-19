#include "twoDimensionalArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Matrix
{
    int matrix[SIZE][SIZE];
    int realSize;
} Matrix;

Matrix* createMatrix(void)
{
    Matrix* matrix = calloc(1, sizeof(Matrix));
    if (matrix == NULL)
    {
        return NULL;
    }
    matrix->realSize = 0;
    return matrix;
}

void deleteMatrix(Matrix** matrix)
{
    free(*matrix);
    *matrix = NULL;
}

void readConsole(Matrix* matrix)
{

}

void printMatrix(Matrix* matrix)
{

}

int* searchMinInRaw(Matrix* matrix, int raw)
{
    int minimum = INT_MAX;
    int minIndex[SIZE] = { 0 };
    int counter = 0;
    int realSize = matrix->realSize;
    for (int col = 0; col < realSize; col++)
    {
        if (matrix->matrix[raw][col] < minimum)
        {
            minimum = matrix->matrix[raw][col];
            minIndex[counter] = col;
            counter++;
        }
    }
    return minIndex;
}

int searchMaxInColumn(Matrix* matrix, int col)
{
    int maximum = INT_MIN;
    int maxIndex[SIZE] = { 0 };
    int counter = 0;
    int realSize = matrix->realSize;
    for (int raw = 0; raw < realSize; raw++)
    {
        if (matrix->matrix[raw][col] > maximum)
        {
            maximum = matrix->matrix[raw][col];
            maxIndex[counter] = raw;
            counter++;
        }
    }
    return maxIndex;
}

bool isInArray()
{

}

int saddle(Matrix* matrix, int* coordinates[SIZE][2])
{
    int realSize = matrix->realSize;
    int counter = 0;
    for (int raw = 0; raw < realSize; raw++)
    {
        for (int col = 0; col < realSize; col++)
        {
            if (searchMinInRaw(matrix, raw) == raw && col == searchMaxInColumn(matrix, col))
            {
                ++counter;
            }
        }
    }
    return counter;
}