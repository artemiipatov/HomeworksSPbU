#pragma once
#include <stdbool.h>
#include "phonebookFunctions.h"

// tests function readDataFromFile()
bool testReadDataFromFile(PhoneBookEntry* testArray);

// tests function addNote()
bool testAddNote(PhoneBookEntry* testArray);

// tests functions findPhoneNumberUsingName() and findNameUsingPhoneNumber()
bool testSearchFunctions(PhoneBookEntry* testArray);

// tests function saveData()
bool testSaveDataToFile(PhoneBookEntry* testArray);

// unites all testing functions
bool uniteTestingFuctions();