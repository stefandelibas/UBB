#pragma once
#include "domain.h"

typedef struct repo_s
{
	medicine* meds[100];
	int length;
}MedRepo;

MedRepo* createRepo();

void destroyRepo(MedRepo* v);

medicine* find(MedRepo* v, char* name,float concentration);

void add_quantity(MedRepo* v, medicine* m);

int add(MedRepo* v, medicine* m);

int update(MedRepo* v, medicine* m);

void delete(MedRepo* v, char* name, float concentration);

int getLength(MedRepo* v);

medicine* getMedicineAtX(MedRepo* v, int x);

void sortAscendingByName(MedRepo* v);
void sortDescendingByName(MedRepo* v);
void sortDescendingByPrice(MedRepo* v);
void sortAscendingByPrice(MedRepo* v);

void sort(MedRepo* v, int(*f)(medicine*, medicine*));
int cmpfctPriceAscendent(medicine* i, medicine* j);
int cmpfctPriceDescending(medicine* i, medicine* j);
int cmpfctNameAscending(medicine* i, medicine* j);
int cmpfctNameDescending(medicine* i, medicine* j);

void sortByQuantityAscendent(MedRepo* v);
void sortByQuantityDescendent(MedRepo* v);




