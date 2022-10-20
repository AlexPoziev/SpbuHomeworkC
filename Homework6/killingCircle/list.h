#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct List List;

// add an element to the list
int insert(List *list, int value);

// print full list
void print(List *list);

// delete element with index position. Count starts by 0
int delete(List *list, int position);

// change value of list in position
int changeNode(List *list, int position, int value);

// checks is list empty
bool isEmpty(List *list);

// delete list and clear memory
int clear(List *list);

// find value by position in list, errorCode == -1 if position below zero or more than real size of list
int findNode(List *list, int position, int *errorCode);