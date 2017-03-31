#pragma once
#include "domain.h"
#include "dynamicArray.h"
#include <string.h>

typedef struct Operation_s
{
	medicine* med1;
	medicine* med2; 
	char * operationType;
}Operation;


Operation* createOperation(medicine* m1, medicine* m2, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);
char* getOperationType(Operation* o);
medicine* getMedicine2(Operation* o);
medicine* getMedicine1(Operation* o);

typedef struct OperationsStack_s
{
	Operation* operations[100];
	int length;
}OperationsStack;

OperationsStack* createStack();
void destroyStack(OperationsStack* s);
void push(OperationsStack* s, Operation* o);
Operation* pop(OperationsStack* s);
int isEmpty(OperationsStack* s);
int isFull(OperationsStack* s);
