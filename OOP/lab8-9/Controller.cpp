#include "Controller.h"

Controller::~Controller()
{
}
void Controller::addDogToRepository(const std::string& breed, const std::string& name, const int age, const std::string& source)
{
	try
	{
		Dog d{ breed,name,age,source };
		this->repo.addDog(d);
	}
	catch (const std::invalid_argument& err){throw err;}
}

void Controller::deleteDogFromRepository(const std::string& breed, const std::string& name, const int age)
{

	try
	{
		Dog d{ breed,name,age,"" };
		this->repo.deleteDog(d);
	}
	catch (const std::invalid_argument& err){throw err;}
}
void Controller::updateDogFromRepository(const std::string& breed, const std::string& name, const int age, const std::string& source)
{
	try
	{
		Dog d{ breed,name,age,source };
		this->repo.updateDog(d);
	}
	catch (const std::invalid_argument& err){throw err;}
}


void Controller::nextDog()
{
	this->user->next();
}
void Controller::adoptCurrentDog()
{
	Dog d = this->user->getCurrentDog();
	try
	{
		this->user->addAdoptionList(d);
	}
	catch (const std::invalid_argument& err){throw err;}
}
void Controller::adoptDogs()
{
	std::vector<Dog> v = this->user->adopt();
	for(int i=0;i<v.size();i++)
		this->repo.deleteDog(v[i]);
}
std::vector<Dog> Controller::filterController(const std::string&breed, const int age)
{
	std::vector<Dog> v = this->repo.getDogs();
	auto no = std::count_if(v.begin(), v.end(), [age,breed](Dog d) {return (d.getAge() < age && d.getBreed() == breed); });
	std::vector<Dog> q;
	q.resize(no);
	auto it = std::copy_if(v.begin(), v.end(), q.begin(), [age,breed](Dog d) {return (d.getAge() < age && d.getBreed() == breed); });
	return q;
}
std::vector<Dog> Controller::filterController(const int age)
{
	std::vector<Dog> v = this->repo.getDogs();
	auto no = std::count_if(v.begin(), v.end(), [age](Dog d) {return (d.getAge() < age); });
	std::vector<Dog> q;
	q.resize(no);
	auto it = std::copy_if(v.begin(), v.end(), q.begin(), [age](Dog d) {return (d.getAge() < age); });
	
	return q;
}
void Controller::saveUserAdoiptionList(const std::string & filename)
{
	if (this->user == nullptr)
		return;

	this->user->setFilename(filename);
	this->user->writeToFile();
}
void Controller::openUserAdoptionList() const
{
	if (this->user == nullptr)
		return;
	this->user->displayUserAdoptionList();
}
void Controller::setDogs(std::vector<Dog>& v)
{
	this->user->setDogs(v);
}

