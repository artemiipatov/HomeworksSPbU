#pragma once

// reads all data from file
int readDataFromFile(const char fileName[], int* array[]);

// writes data from array to the file
void writeDataToFile(const char fileName[], int array[], int length);

// finds numbers less then number from file and then calls function writesDataToFile to write received array of less numbers
void findLessNumbers(const char filename[], int array[], int length, int number);