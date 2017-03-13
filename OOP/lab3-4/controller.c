#include "controller.h"
#include <string.h>

/*
creates a controller object, allocating memory and initializing the repo
input:	r - a repository object
*/
Controller* createController(MedRepo* r)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
}

/*
destroy a controller object, by destroying the repository and
deallocating  memory occupied by the controller object until now.
*/
void destroyController(Controller* c)
{
	// first destroy the repository inside
	destroyRepo(c->repo);
	// then free the memory
	free(c);
}
/*
recives the data from the ui, creates a new medicine object and passes to th repository
input: the controller structure, containing the repository, and data for a medicine
		(name, concentration, quantity, price)
output: 1 - the medicine was not in the repositry => it was added successfully
		0 - if the medicine was already in the repository => the quantity was increased
*/

int addMedicine(Controller* c, char *name, float concentration, int quantity, float price)
{
	medicine* m = createMedicine(name, quantity, concentration, price);
	int res = add(c->repo, m);
	return res;
}
/*
recives the data from the ui, creats a new medicine object and passes to th repository
input: the controller structure, containing the repository, and data for a medicine
	   (name, concentration, quantity, price).
output: 1 - the medicine was not in the repositry => error, cannot update an
			object which is not in the repository. 
		0 - if the medicine was already in the repository => the object was updated successfully.
*/
int updateMedicine(Controller* c, char* name, int quantity, float concentration, float price)
{
	medicine* m = createMedicine(name, quantity, concentration, price);
	int res = update(c->repo, m);
	if (res == 0)
		return 0;
	return 1;
}

/*
recives the data from the ui, finds the medicine with the given name and concentration(unique keys)
input: the controller structure, containing the repository, and data for identifying a medicine
		(name and concentration)
output: 1 - the medicine was not in the repositry => cannot delete an 
			object which is not in the repository. 
		0 - if the medicine was already in the repository =>  the object was deleted successfully
*/
int deleteMedicine(Controller* c, char* name, float concentration)
{
	medicine* m = find(c->repo, name, concentration);
	if (m == NULL)
		return 0;
	delete(c->repo, name, concentration);
	return 1;
}

/*
returns the repository of the controller
input:	c - a controller object
output:	r - a repository object
*/
MedRepo* getRepo(Controller* c)
{
	return c->repo;
}

/*
recives a string from the ui, creates a new repository with the medicines containing the given string.
input:	c - a controller object 
		string - a string that will be be used for searching the medicines contining it as a substring.
output:	a repository object containing the medicines after filtering them
		or the whole repository if the string was 'null'	
*/
MedRepo* filter(Controller* c, char string[], int way, int record)
{
	MedRepo* res = createRepo();
	if (strcmp(string, "null") == 0)
	{
		return c->repo;
	}

	int i;
	for (i = 0; i < getLength(c->repo); i++)
	{
		medicine* m = getMedicineAtX(c->repo, i);
		if (strstr(getName(m), string) != NULL)
		{
			medicine* newMedicine = createMedicine(m->name, m->quantity, m->concentration, m->price);
			add(res, newMedicine);
		}
	}
	//printf("\n%d", way);
	if (record == 1)//1 is for name filter
		sortRepoByName(res, way);
	else
		if (record == 2)//2 is for price filter
			sortRepoByPrice(res, way);
		else
			return NULL;
	return res;
}

void sortRepoByName(MedRepo* res, int aORd)
{
	if (aORd == 1)//1 is for ascending
		//sort(res, cmpfctNameAscending);
		sortAscendingByName(res);
	else
		if (aORd == 2)//2 is for descending
			//sort(res, cmpfctNameDescending);
			sortDescendingByName(res);
}

void sortRepoByPrice(MedRepo* res, int aORd)
{
	if (aORd == 1)//1 is for ascending
		//sort(res, cmpfctPriceAscendent);
		sortAscendingByPrice(res);
	else
		if (aORd == 2)//2 is for descending
			//sort(res, cmpfctPriceDescending);
			sortDescendingByPrice(res);
}

// filters by quantity ascending or descending depending on the value of way 
// all the medicines objects that have the quantity less than q 
MedRepo* filterByQuantity(Controller* c, int way, int q)
{
	MedRepo* res = createRepo();

	int i;
	for (i = 0; i < getLength(c->repo); i++)
	{
		medicine* m = getMedicineAtX(c->repo, i);
		if (getQuantity(m) < q)
		{
			medicine* newMedicine = createMedicine(m->name, m->quantity, m->concentration, m->price);
			add(res, newMedicine);
		}
	}
	if (getLength(res) == 0)
	{
		return NULL;
	}
	if (way == 1)//1 is for ascending
		sortByQuantityAscendent(res);
	else
		if (way == 2)//2 is for descending
			sortByQuantityDescendent(res);
		else
			return NULL;

	return res;
}
