#include "Tests.h"
#include <assert.h>
#include "Controller.h"
#include "Repository.h"
#include "UserAdoptionList.h"
#include "Dog.h"
#include "Validator.h"


void Tests::testDog()
{
	Dog d{ "Samoyed","Lora",5,"www.google.com" };
	assert(d.getName() == "Lora");
	assert(d.getAge() == 5);
	assert(d.getBreed() == "Samoyed");
	assert(d.getSource() == "www.google.com");	
	int i = Dog::getInstances();
	d.showPhoto();
}

void Tests::testRepository()
{
	Repository repo{};
	Dog d1{ "Samoyed","Lora",5,"www.google.com" };
	Dog d2("Doberman", "Jack", 4, "www.google.com");
	repo.addDog(d1);
	repo.addDog(d2);
	assert(repo.getDogs().size() == 2);
	try 
	{
		repo.addDog(d1);
		assert(false); 
	} 
	catch(const std::invalid_argument& err) 
	{
		assert(true);
	}
	assert(repo.findDog(d1) != -1 && repo.findDog(d1) == 0);
	repo.deleteDog(d1);
	assert(repo.findDog(d1)==-1);
	try
	{
		repo.deleteDog(d1);
		assert(false);
	}
	catch (const std::invalid_argument& err)
	{
		assert(true);
	}

	assert(repo.getDogs().size() == 1);
	Dog d{ "Doberman","Jack",5,"www.google.com" };
	repo.updateDog(d);
	try
	{
		repo.updateDog(d1);
		assert(false);
	}
	catch (const std::invalid_argument& err)
	{
		assert(true);
	}
	assert(repo.getDogs().size() == 1);
}



void Tests::testUserAdoptionList()
{
	UserAdoptionList e{};
	e.next();
	std::vector<Dog> v;
	v.push_back(Dog("Berna", "Suty", 5, "www.google.com"));
	v.push_back(Dog("Berna", "Blacky", 4, "www.google.com"));
	UserAdoptionList user{v};
	Dog d = user.getCurrentDog();

	assert(d.getName() == "Suty");
	assert(d.getAge() == 5);
	assert(d.getBreed() == "Berna");
	assert(d.getSource() == "www.google.com");

	user.next();
	d = user.getCurrentDog();

	assert(d.getName() == "Blacky");
	assert(d.getAge() == 4);
	assert(d.getBreed() == "Berna");
	assert(d.getSource() == "www.google.com");

	user.next();
	assert(user.findDog(d) == -1);

	user.addAdoptionList(d);
	assert(user.findDog(d) != -1);

	std::vector<Dog> q = user.getDogs();
	assert(q.size() == 1);

	user.next();
	d = user.getCurrentDog();
	try
	{
		user.addAdoptionList(d);
		assert(false);
	}
	catch (const std::invalid_argument& err)
	{
		assert(true);
	}
}


void Tests::testController()
{
	/*
	Repository repo{};
	UserAdoptionList user{ repo };
	Controller ctrl{ repo,user };
	ctrl.addDogToRepository("Samoyed", "Lora", 6, "www.google.com");
	ctrl.addDogToRepository("Doberman", "Jack", 4, "www.google.com");
	try
	{
		ctrl.addDogToRepository("Samoyed", "Lora", 6, "www.google.com");
		assert(false);
	}
	catch (const std::invalid_argument& err)
	{
		assert(true);
	}
	//the repo should have 2 elements
	assert(ctrl.getRepo().getDogs().size() == 2);
	//the list of dogs from where the user can adopt was not initialized so is should be emplty
	assert(ctrl.getUserList().isEmpty() == true);
	std::vector<Dog> v = ctrl.filterController(5);
	//the filter should keep only the dogs with the age less than 5 years
	assert(v.size() == 1);
	ctrl.setDogs(v);
	//now the list of dogs from where the user can adopt was set, filtered by age
	assert(ctrl.getUserList().isEmpty() == false);
	//the user's adoption list should still be empty
	assert(user.getDogs().size() == 0);
	Dog d = user.getCurrentDog();
	ctrl.adoptCurrentDog();
	try
	{
		ctrl.adoptCurrentDog();
		assert(false);
	}
	catch (const std::invalid_argument& err)
	{
		assert(true);
	}
	ctrl.nextDog();
	//when a dog is adopted it is push_backed to the user's adoption wishlist
	assert(ctrl.getUserList().getDogs().size() == 1);
	ctrl.adoptDogs();
	//when dogs are adopted they should be deleted from the repo
	assert(ctrl.getRepo().getDogs().size() == 1);
	assert(ctrl.getRepo().findDog(d) == -1);
	ctrl.updateDogFromRepository("Samoyed", "Lora", 5, "www.google.com");
	assert(ctrl.getRepo().getDogs().size() == 1);
	ctrl.deleteDogFromRepository("Samoyed", "Lora", 5);
	Dog d1{ "Samoyed", "Lora", 6, "www.google.com" };
	assert(ctrl.getRepo().findDog(d1) == -1);
	try
	{
		ctrl.deleteDogFromRepository("Samoyed", "Lora", 5);
		assert(false);
	}
	catch (const std::invalid_argument& err)
	{
		assert(true);
	}
	try
	{
		ctrl.updateDogFromRepository("Samoyed", "Lora", 5, "www.google.com");
		assert(false);
	}
	catch (const std::invalid_argument& err)
	{
		assert(true);
	}
	ctrl.addDogToRepository("Samoyed", "Lora", 6, "www.google.com");
	ctrl.addDogToRepository("Doberman", "Jack", 4, "www.google.com");
	std::vector<Dog> q = ctrl.filterController("Doberman", 5);
	ctrl.getUserList().setDogs(q);
	assert(q.size() == 1);
	*/
}

void Tests::testFileRepo()
{
	Repository r{ "test.txt" };
	r.storeToFile();
}

void Tests::testValidator()
{
	Validator v{};
	assert(v.ValidAge(5) == true);
	assert(v.ValidAge(120) == false);
	assert(v.ValidIntegerNumber(-5) == true);
	assert(v.ValidIntegerNumber(5) == false);
	assert(v.ValidString("") == true);
	assert(v.ValidString("something") == false);
}

void Tests::testAll()
{
	testDog();
	testRepository();
	testController();
	testFileRepo();
	testUserAdoptionList();
	testValidator();
}
