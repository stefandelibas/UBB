#include "UI.h"
#include <Windows.h>
#include <crtdbg.h>
#include "Tests.h"
#include "FileUserAdoptionList.h"
#include "csvUserAdoptionList.h"
#include "HTMLUserAdoptionList.h"


using namespace std;

int main()
{
	{
		//Tests::testAll();
	
		Repository repo{ "dogs.txt" };
		FileUserAdoptionList* a{};
		int t;
		cout << "1 - for csv\n";
		cout << "2 - for html\n";
		cin >> t;
		cin.ignore();
		if (t == 1)
		{
			a = new csvUserAdoptionList{};
		}
		else
		{
			a = new HTMLUserAdoptionList{};
		}
		Controller ctrl{ repo , a };
		UI ui{ ctrl };
		int instances = 10;
		ui.run(instances);
		cout << instances << endl;
		
		int nimic;
		cin >> nimic; 
	}
	_CrtDumpMemoryLeaks();
	
}