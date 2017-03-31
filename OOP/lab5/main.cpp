#include "Dog.h"
#include "UI.h"
#include <Windows.h>

using namespace std;

int main()
{
	Repository repo{};
	Dog d1{ "Samoyed","Lora",5,"https://www.google.ro/imgres?imgurl=http://cdn.akc.org/akcdoglovers/Samoyed_hero1.jpg&imgrefurl=http://www.akc.org/dog-breeds/samoyed/&h=669&w=1216&tbnid=-8ctsZrSHOxRSM:&tbnh=110&tbnw=200&usg=__3iyAnWVRwE2ojHjqi7RhJkIuSCw=&vet=10ahUKEwi02rvB4PjSAhWCBiwKHY7MCGUQ_B0IeTAK..i&docid=0KyAQNZLrrApFM&itg=1&client=firefox-b-ab&sa=X&ved=0ahUKEwi02rvB4PjSAhWCBiwKHY7MCGUQ_B0IeTAK&ei=HBvaWLTcG4KNsAGOmaOoBg#h=669&imgrc=-8ctsZrSHOxRSM:&tbnh=110&tbnw=200&vet=10ahUKEwi02rvB4PjSAhWCBiwKHY7MCGUQ_B0IeTAK..i&w=1216" };
	Dog d2{ "West-Highland-White-Terrier","Cory",2,"https://www.google.ro/search?q=west+highland+white+terrier&client=firefox-b-ab&tbm=isch&imgil=Z17wIFCEVKeSXM%253A%253BcYf47QT9gzkPrM%253Bhttp%25253A%25252F%25252Fwww.dogbreedslist.info%25252Fall-dog-breeds%25252FWest-Highland-White-Terrier.html&source=iu&pf=m&fir=Z17wIFCEVKeSXM%253A%252CcYf47QT9gzkPrM%252C_&usg=__e93nfdYq3umKzHnGzqkfb2zvrOU%3D&biw=1366&bih=635&ved=0ahUKEwiW2NjY4PjSAhVHdCwKHWWlAsgQyjcIhwE&ei=TRvaWNb9CcfosQHlyorADA#imgrc=Z17wIFCEVKeSXM:" };
	Dog d3{ "Retriever","Goldie",3,"https://www.google.ro/search?client=firefox-b-ab&tbm=isch&q=retriever&spell=1&sa=X&ved=0ahUKEwinqfSc4fjSAhWFBywKHX_fC_YQBQgsKAA&biw=1366&bih=635&dpr=1#imgrc=neenpdhv6jcJGM:" };
	
	repo.addDog(d1);
	repo.addDog(d2);
	repo.addDog(d3);

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
}