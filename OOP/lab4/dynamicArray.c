#include "dynamicArray.h"
#include <stdio.h>

dynamicArray* create_da(int capacity)
{
	dynamicArray* da = (dynamicArray*)malloc(sizeof(dynamicArray));
	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;
	da->elements = (TElement*)malloc(sizeof(TElement));

	if (da->elements == NULL)
		return NULL;

	return da;
}


void destroy_da(dynamicArray* arr)
{
	if (arr == NULL)
		return;
	free(arr->elements);
	arr->elements = NULL;

	free(arr);
	arr = NULL;
}
void resize(dynamicArray* arr)
{
	if (arr == NULL)
		arr->capacity *= 2;
	arr->elements = (TElement*)realloc(arr->elements, arr->capacity * sizeof(TElement));
}
void add_da(dynamicArray* arr, TElement* t)
{
	if (arr == NULL)
		return;
	if (arr->elements == NULL)
		return;
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elements[arr->length] = t;
	arr->length++;
}

void delete_da(dynamicArray* arr,int pos)
{
	if (arr == NULL)
		return;
	if (arr->elements == NULL)
		return;
	int i;
	for (i = pos; i < arr->length; i++)
	{
		arr->elements[i] = arr->elements[i + 1];
	}
	arr->length--;
}

int getLength_da(dynamicArray* arr)
{
	if (arr == NULL)
		return -1;
	return arr->length;
}

TElement get_element(dynamicArray* arr, int pos)
{
	return arr->elements[pos];
}
TElement* set_element(dynamicArray* arr, int pos,TElement *t)
{
	TElement* t1 = get_element(arr, pos);
	t1 = t;
}