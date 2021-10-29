#pragma once

// finds correct position for new value to keep list sorted, returns false if there is an error, true if value was added to the list
bool findPosition(List* list, int value);

// removes list item by its index, returns true if it is deleted, false if it is not
bool deleteItemByIndex(List* list, int itemIndex);

// prints all values in list
bool printList(List* list);