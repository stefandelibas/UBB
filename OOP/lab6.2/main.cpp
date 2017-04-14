#include "UI.h"
#include <Windows.h>
#include <crtdbg.h>
#include "Tests.h"


using namespace std;

int main()
{
	{
		//Tests::testAll();

		Repository repo{};

		Dog d1{ "Samoyed","Lora",5,"https://www.google.ro/imgres?imgurl=http://cdn.akc.org/akcdoglovers/Samoyed_hero1.jpg&imgrefurl=http://www.akc.org/dog-breeds/samoyed/&h=669&w=1216&tbnid=-8ctsZrSHOxRSM:&tbnh=110&tbnw=200&usg=__3iyAnWVRwE2ojHjqi7RhJkIuSCw=&vet=10ahUKEwi02rvB4PjSAhWCBiwKHY7MCGUQ_B0IeTAK..i&docid=0KyAQNZLrrApFM&itg=1&client=firefox-b-ab&sa=X&ved=0ahUKEwi02rvB4PjSAhWCBiwKHY7MCGUQ_B0IeTAK&ei=HBvaWLTcG4KNsAGOmaOoBg#h=669&imgrc=-8ctsZrSHOxRSM:&tbnh=110&tbnw=200&vet=10ahUKEwi02rvB4PjSAhWCBiwKHY7MCGUQ_B0IeTAK..i&w=1216" };
		Dog d2{ "West-Highland-White-Terrier","Cory",2,"https://www.google.ro/search?q=west+highland+white+terrier&client=firefox-b-ab&tbm=isch&imgil=Z17wIFCEVKeSXM%253A%253BcYf47QT9gzkPrM%253Bhttp%25253A%25252F%25252Fwww.dogbreedslist.info%25252Fall-dog-breeds%25252FWest-Highland-White-Terrier.html&source=iu&pf=m&fir=Z17wIFCEVKeSXM%253A%252CcYf47QT9gzkPrM%252C_&usg=__e93nfdYq3umKzHnGzqkfb2zvrOU%3D&biw=1366&bih=635&ved=0ahUKEwiW2NjY4PjSAhVHdCwKHWWlAsgQyjcIhwE&ei=TRvaWNb9CcfosQHlyorADA#imgrc=Z17wIFCEVKeSXM:" };
		Dog d3{ "Retriever","Goldie",3,"https://www.google.ro/search?client=firefox-b-ab&tbm=isch&q=retriever&spell=1&sa=X&ved=0ahUKEwinqfSc4fjSAhWFBywKHX_fC_YQBQgsKAA&biw=1366&bih=635&dpr=1#imgrc=neenpdhv6jcJGM:" };
		Dog d4{ "Akita","Bicuitel",3,"https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQiulhjXniMyVkwtoYG_4FOxpDlg2WlT30mLIVzFtCR7CIMB2v4TQDN-7U" };
		Dog d5{ "Berna","Jack",1,"http://www.rasedecaini.com/wp-content/uploads/2009/11/ciobanesc-de-berna-09.jpg" };
		Dog d6{ "Berna","Suty",4,"https://animax.ro/images/companies/1/animale/CiobanescBerna19.jpg?1426846972488" };
		Dog d7{ "Berna","Lucky",6,"http://www.zooland.ro/data/articles/39/666/2005610172631ciobanesc_Berna-0n.jpg" };
		Dog d8{ "Beagle","Ducky",2,"http://www.pawculture.com/uploads/Beagle-main.jpg" };
		Dog d9{ "Beagle","Ron",3,"http://static.ddmcdn.com/en-us/apl/breedselector/images/breed-selector/dogs/breeds/beagle_04_lg.jpg" };
		Dog d10{ "Doberman","BadBoy",5,"https://s-media-cache-ak0.pinimg.com/736x/f5/23/ac/f523acccd59ce28b8743158194b3487d.jpg" };

		repo.addDog(d1);
		repo.addDog(d2);
		repo.addDog(d3);
		repo.addDog(d4);
		repo.addDog(d5);
		repo.addDog(d6);
		repo.addDog(d7);
		repo.addDog(d8);
		repo.addDog(d9);
		repo.addDog(d10);


		UserAdoptionList user{ repo };

		Controller ctrl{ repo , user };
		UI ui{ ctrl };
		int instances = 10;
		ui.run(instances);
		cout << instances << endl;
		
		int nimic;
		cin >> nimic; 
	}
	_CrtDumpMemoryLeaks();
}