#pragma once
#define SIZE 200

typedef struct Matrix Matrix;

// creates matrix
Matrix* createMatrix(void);

// deletes matrix
void deleteMatrix(Matrix** matrix);

// reads console
void readConsole(Matrix* matrix);

// prints matrix
void printMatrix(Matrix* matrix);

// saddle points search, returns number of saddle points
int saddle(Matrix* matrix, int* coordinates[SIZE][2]);