#include "repository.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

/*
creates a repository object, allocating memory and initializing the repo length
input:	-
output:	v - a repository object
*/
MedRepo* createRepo()
{
	MedRepo* v = (MedRepo*)malloc(sizeof(MedRepo));
	v->length = 0;
	
	return v;
}

/*
destroy a repository object, by destroying the medicines and
deallocating  memory occupied by the repository object until now.
*/
void destroyRepo(MedRepo* v)
{
	int i;
	for (i = 0; i < v->length; i++)
	{
		destroyMedicine(v->meds[i]);
	}
	free(v);
}

/*
finds a medicine in the repository by its unique keys(name and concentration)
input:	v - a repository object
		name and concentration - the unique keys of a medicine
output:	the medicine object with the unique keys, if it was found in the repository
		pointer NULL, if it was not found in the repository any medicine with the given unique keys
*/
medicine* find(MedRepo* v, char* name,float concentration)
{
	int i;
	for (i = 0; i < v->length; i++)
	{
		if (strcmp(name, v->meds[i]->name) == 0 && concentration == v->meds[i]->concentration)
			return v->meds[i];
	}
	return NULL;
}

/*
increases the quantity of a given medicine. 
*/
void add_quantity(MedRepo* v, medicine* m)
{
	int i;
	for (i = 0; i < v->length; i++)
	{
		if (strcmp(m->name, v->meds[i]->name) == 0 && m->concentration == v->meds[i]->concentration);
		{
			v->meds[i]->quantity += m->quantity;
		}
	}
}

/*
recives a medicine from the contoller and adds it to the repository
input: the repository structure, and a medicine
output: 1 - the medicine was not in the repositry => it was added successfully
		0 - if the medicine was already in the repository => the quantity was increased
*/
int add(MedRepo* v, medicine* m)
{
	if (find(v, m->name, m->concentration) != NULL)
	{
		add_quantity(v, m);
		return 0;
	}

	v->meds[v->length] = m;
	v->length++;

	return 1;
}

/*
recives the data from the controller, deletes the medicine with the given name and concentration(unique keys)
input:	v - a repository object
		name and concentration - the unique keys of a medicine
output:	-
*/
void delete(MedRepo* v, char* name, float concentration)
{
	int i;
	for (i = 0; i < v->length; i++)
	{
		if (strcmp(name, v->meds[i]->name) == 0 && concentration == v->meds[i]->concentration)
			break;
	}
	while (i < v->length)
	{
		v->meds[i] = v->meds[ i + 1];
		i++;
	}
	//realloc(v->meds, sizeof(medicine*)*(v->length - 1));
	//destroyMedicine(v->meds[v->length-1]);
	v->length--;	
}

/*
recives the data from the controller and updates the medicine 
input: v - a repository object
		new - the medicine object meant to be updated
output: 0 - the medicine was not in the repositry => error, cannot update an
			object which is not in the repository.
		1 - if the medicine was already in the repository => the object was updated successfully.
*/
int update(MedRepo* v, medicine* new)
{

	medicine* m = find(v, new->name, new->concentration);
	if (m == NULL)
		return 0;
	m->quantity = new->quantity;
	m->price = new->price;
	return 1;
}

/*
returns the repository length
input:	r - a repository object
output:	the length of the repository object
*/
int getLength(MedRepo* v)
{
	return v->length;
}

/*
returns the medicine at the position x in the repository
input:	r - a repository object
		x - integer, the position
output:	the medicine that is on the position x in the repository 
*/
medicine* getMedicineAtX(MedRepo* v, int x)
{
	if (x < 0 || x >= v->length)
		return NULL;
	return v->meds[x];
}

int cmpfctPriceAscendent(medicine* i, medicine* j)
{
	return i->price > j->price;
}

int cmpfctPriceDescending(medicine* i, medicine* j)
{
	return i->price < j->price;
}

int cmpfctNameAscending(medicine* i, medicine* j)
{
	return strcmp(i->name, j->name) > 0;
}
int cmpfctNameDescending(medicine* i, medicine* j)
{
	return strcmp(i->name, j->name) < 0;
}

void sort(MedRepo* v, int(*f)(medicine*, medicine*))
{
	qsort(v->meds, getLength(v), sizeof(medicine*), f);
}

void sortAscendingByName(MedRepo* v)
{
	int i,j;
	for (i = 0; i < getLength(v); i++)
		for (j = i + 1; j < getLength(v); j++)
			if ( strcmp(v->meds[i]->name, v->meds[j]->name) >  0 )
			{
				medicine* aux = v->meds[i];
				v->meds[i] = v->meds[j];
				v->meds[j] = aux;
			}
}
void sortDescendingByName(MedRepo* v)
{
	int i,j;
	for (i = 0; i < getLength(v); i++)
		for (j = i + 1; j < getLength(v); j++)
			if ( strcmp(v->meds[i]->name, v->meds[j]->name) < 0)
			{
				medicine* aux = v->meds[i];
				v->meds[i] = v->meds[j];
				v->meds[j] = aux;
			}
}

void sortAscendingByPrice(MedRepo* v)
{
	int i, j;
	for (i = 0; i < getLength(v); i++)
		for (j = i + 1; j < getLength(v); j++)
			if (v->meds[i]->price > v->meds[j]->price)
			{
				medicine* aux = v->meds[i];
				v->meds[i] = v->meds[j];
				v->meds[j] = aux;
			}
}

void sortDescendingByPrice(MedRepo* v)
{
	int i, j;
	for (i = 0; i < getLength(v); i++)
		for (j = i + 1; j < getLength(v); j++)
			if (v->meds[i]->price < v->meds[j]->price)
			{
				medicine* aux = v->meds[i];
				v->meds[i] = v->meds[j];
				v->meds[j] = aux;
			}
}

void sortByQuantityAscendent(MedRepo* v)
{
	int i, j;
	for (i = 0; i < getLength(v); i++)
		for (j = i + 1; j < getLength(v); j++)
			if (v->meds[i]->quantity > v->meds[j]->quantity)
			{
				medicine* aux = v->meds[i];
				v->meds[i] = v->meds[j];
				v->meds[j] = aux;
			}
}

void sortByQuantityDescendent(MedRepo* v)
{
	int i, j;
	for (i = 0; i < getLength(v); i++)
		for (j = i + 1; j < getLength(v); j++)
			if (v->meds[i]->quantity < v->meds[j]->quantity)
			{
				medicine* aux = v->meds[i];
				v->meds[i] = v->meds[j];
				v->meds[j] = aux;
			}
}


void initMedRepoForTests(MedRepo* v)
{
	medicine* m = createMedicine("nurofen", 5, 80, 15);
	add(v, m);
}

void testAdd()
{
	MedRepo* v = createRepo();
	initMedRepoForTests(v);
	assert(getLength(v) == 1);

	medicine* m = createMedicine("bixtonim", 10, 75, 24);
	assert(add(v,m) == 1);
	assert(getLength(v) == 2);
	// take the medicine from the repo and then do some checks on it.
	m = find(v, "bixtonim", 75);
	// check if the medicine was added successfully.
	assert(m->quantity == 10);
	assert(m->price == 24);
	assert(m->concentration == 75);
	assert(strcmp(m->name, "bixtonim") == 0);

	//destroyMedicine(m);
	//destroyMedicine(newMed);

	assert(add(v, m) == 0);
	destroyRepo(v);
}

void testUpdate()
{
	MedRepo* v = createRepo();
	initMedRepoForTests(v);
	assert(getLength(v) == 1);

	//updates a medicine 
	medicine* newMed = createMedicine("nurofen", 10, 80, 20);
	assert(update(v, newMed) == 1); // returns 1 which means the update was done successfully.
	// take the medicine from the repo and then do some checks on it.
	medicine* m = find(v, "nurofen", 80);
	// check if the medicine was updated(its quantity and its price only)
	assert(m->quantity == 10); 
	assert(m->price == 20);
	// no change on the concentration and name
	assert(m->concentration == 80);
	assert(strcmp(m->name,"nurofen") == 0);

	//destroyMedicine(m);
	//destroyMedicine(newMed);

	//update a medicine which is not in the list. it shouldn't do any change on the repo.
	newMed = createMedicine("nothing", 10, 80, 20);
	//even if newMed has the same concentration as a medince in the repo it shouldn't match
	//any medicine because its unique keys are the name and the concentration
	assert(update(v, newMed) == 0);

	//destroyMedicine(newMed);

	//update a medicine which is not in the list. it shouldn't do any change on the repo.
	newMed = createMedicine("nurofen", 10, 70, 20);
	//even if the name matches a medicine in the repo, the concentration is diffrent it shouldn't match
	//any medicine because its unique keys are the name and the concentration
	assert(update(v, newMed) == 0);
	// take the medicine from the repo and then do some checks on it.
	m = find(v, "nurofen", 80);
	// check if the medicine was not modified at all
	assert(m->quantity == 10);
	assert(m->price == 20);
	assert(m->concentration == 80);
	assert(strcmp(m->name, "nurofen") == 0);

	//destroyMedicine(m);
	//destroyMedicine(newMed);

	destroyRepo(v);
}

void testDelete()
{
	MedRepo* v = createRepo();
	initMedRepoForTests(v);
	assert(getLength(v) == 1);

	medicine* m = createMedicine("bixtonim", 10, 75, 24);
	assert(add(v, m) == 1);
	assert(getLength(v) == 2);
	assert(find(v, "bixtonim", 75) != NULL);
	delete(v, "bixtonim", 75);
	assert(find(v, "bixtonim", 75) == NULL);
	assert(getLength(v) == 1);

	//destroyMedicine(m);
	destroyRepo(v);
}
void testsMedRepo()
{
	testAdd();
	testUpdate();
	testDelete();
}