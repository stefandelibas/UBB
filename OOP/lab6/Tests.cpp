#include "Tests.h"
#include <assert.h>
#include "Controller.h"
#include "DynamicVector.h"
#include "Repository.h"
#include "UserAdoptionList.h"
#include "Dog.h"


void Tests::testDynamicVector()
{
	DynamicVector<int> v1{ 2 };
	v1.add(10);
	v1.add(20);
	assert(v1.getSize() == 2);
	assert(v1[1] == 20);
	v1.add(30);
	assert(v1.getSize() == 3);

	DynamicVector<int> v2 = v1;
	assert(v2.getSize() == 3);

	DynamicVector<int> v3;
	v3 = v1;
	assert(v3[0] == 10);	
}

void Tests::testDog()
{
	Dog d{ "Samoyed","Lora",5,"www.google.com" };
	assert(d.getName() == "Lora");
	assert(d.getAge() == 5);
	assert(d.getBreed() == "Samoyed");
	assert(d.getSource() == "www.google.com");	
}

void Tests::testRepository()
{
	Repository repo{};
	Dog d1{ "Samoyed","Lora",5,"www.google.com" };
	Dog d2("Doberman", "Jack", 4, "www.google.com");
	repo.addDog(d1);
	repo.addDog(d2);

	DynamicVector<Dog> dogs = repo.getDogs();
	assert(dogs.getSize() == 2);
	assert(dogs.find(d1) != -1 && dogs.find(d1) == 0);
	int i= repo.deleteDog(d1);
	assert(i == 1);
}

void Tests::testController()
{
	Repository repo{};
	UserAdoptionList user{ repo };
	Controller ctrl{ repo,user };
	ctrl.addDogToRepository("Samoyed", "Lora", 6, "www.google.com");
	ctrl.addDogToRepository("Doberman", "Jack", 4, "www.google.com");
	//the repo should have 2 elements
	assert(ctrl.getRepo().getDogs().getSize() == 2);
	//the list of dogs from where the user can adopt was not initialized so is should be emplty
	assert(ctrl.getUserList().isEmpty() == true);
	DynamicVector<Dog> v = ctrl.filterController(5);
	//the filter should keep only the dogs with the age less than 5 years
	assert(v.getSize() == 1);
	ctrl.setDogs(v);
	//now the list of dogs from where the user can adopt was set, filtered by age
	assert(ctrl.getUserList().isEmpty() == false);
	//the user's adoption list should still be empty
	assert(user.getDogs().getSize() == 0);
	Dog d = user.getCurrentDog();
	ctrl.adoptCurrentDog();
	//when a dog is adopted it is added to the user's adoption wishlist
	assert(ctrl.getUserList().getDogs().getSize() == 1);
	ctrl.adoptDogs();
	//when dogs are adopted they should be deleted from the repo
	assert(ctrl.getRepo().getDogs().getSize() == 1);
}

void Tests::testAll()
{
	testDynamicVector();
	testDog();
	testRepository();
	testController();
}
