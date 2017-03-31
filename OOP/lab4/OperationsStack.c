#include "OperationsStack.h"
#include <string.h>
#include <stdlib.h>

Operation* createOperation(medicine* m1, medicine* m2, char* operationType)
{
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->med1 = copyMedicine(m1);
	o->med2 = copyMedicine(m2);

	if (operationType != NULL)
	{
		o->operationType = (char*)malloc(sizeof(operationType+1));
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;
	return o;
}
void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;
	destroyMedicine(o->med1);
	destroyMedicine(o->med2);
	free(o->operationType);
	free(o);
}


Operation* copyOperation(Operation* o)
{
	if (o == NULL)
		return NULL;

	Operation* newOp = createOperation(o->med1,o->med2, o->operationType);
	return newOp;
}

char* getOperationType(Operation* o)
{
	return o->operationType;
}

medicine* getMedicine1(Operation* o)
{
	return o->med1;
}
medicine* getMedicine2(Operation* o)
{
	return o->med2;
}
OperationsStack* createStack()
{
	OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
	s->length = 0;

	return s;
}

void destroyStack(OperationsStack* s)
{
	if (s == NULL)
		return;

	for (int i = 0; i < s->length; i++)
		destroyOperation(s->operations[i]);

	free(s);
}

void push(OperationsStack* s, Operation* o)
{
	if (isFull(s))
		return;

	s->operations[s->length++] = o;	
}

Operation* pop(OperationsStack* s)
{
	if (isEmpty(s))
		return NULL;
	s->length--;
	return s->operations[s->length];
}

int isEmpty(OperationsStack* s)
{
	return (s->length == 0);
}

int isFull(OperationsStack* s)
{
	return s->length == 100;
}
