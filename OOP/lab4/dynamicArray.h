#pragma once
#include "domain.h"
#define CAPACITY 20

typedef medicine* TElement;

typedef struct dynamicArrat_s
{
	TElement* elements;
	int length;
	int capacity;
}dynamicArray;

dynamicArray* create_da(int capacity);

void destroy_da(dynamicArray* arr);

void add_da(dynamicArray* arr, TElement* t);

void delete_da(dynamicArray* arr, int pos);

int getLength_da(dynamicArray* arr);

TElement get_element(dynamicArray* arr, int pos);
TElement* set_element(dynamicArray* arr, int pos, TElement *t);

