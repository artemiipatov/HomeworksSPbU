#pragma once
#include <stdbool.h>

// phonebook struct
typedef struct {
    char name[30];
    char phone[30];
} PhoneBookEntry;

// function for reading data from file at the beginning of the program
int readDataFromFile(PhoneBookEntry* notesArray, int currentIndex, const char fileName[]);

// function for adding note (name and phone number) to an array with all notes
void addNote(PhoneBookEntry* notesArray, const char name[], const char phone[], const int currentIndex);

// function for printing all notes in console
void printAllNotes(const PhoneBookEntry* notesArray, int currentIndex);

// function for searching phone number using name
int findPhoneNumberUsingName(const PhoneBookEntry* notesArray, const char toSearchName[], const int currentIndex);

// function for searching name using phone number
int findNameUsingPhoneNumber(const PhoneBookEntry* notesArray, const char toSearchPhoneNumber[], const int currentIndex);

// function for saving data to file
void saveData(const PhoneBookEntry* notesArray, const int currentIndex, const char fileName[]);