#include<iostream>
#include "playerbase.h"
#include "version.h"

using namespace std;

int main()
{
	Version.interm = 1.5;

	Player player;
	vector<Perk> perklist;
	vector<Perk>::const_iterator it;
	string io[2];
	int numIO;
	int num = 1;
	int Ppoints = player.getPoints();
	char ioC;

	perklist.push_back(armorUp);
	perklist.push_back(helpingHand);
	perklist.push_back(speedBoost);
	perklist.push_back(fastMag);

	cout << "Welcome to Zombies" <<endl;
	cout << "Whats your first name? ";
	cin >> io[0];
	cout << "Whats your last name? ";
	cin >> io[1];
	cout << "Ok " << io[0] << " " << io[1] << " now lets get you some perks.\n" << endl;

	for(it = perklist.begin(); it != perklist.end(); ++it)
	{
		cout << num << ". " << *it << endl;
		num += 1;
	}

	cout << "\nEnter the number next to the perks name: ";
	cin >> numIO;

	while(Ppoints > 0)
	{
		switch(numIO)
		{
			case 1:
			player.addPerk(armorUp);
			player.subtractPoints(armorUp.cost);
			Ppoints = player.getPoints();
			break;

			case 2:
			player.addPerk(helpingHand);
			player.subtractPoints(helpingHand.cost);
			Ppoints = player.getPoints();
			break;

			case 3:
			player.addPerk(speedBoost);
			player.subtractPoints(speedBoost.cost);
			Ppoints = player.getPoints();
			break;

			case 4:
			player.addPerk(fastMag);
			player.subtractPoints(fastMag.cost);
			Ppoints = player.getPoints();
			break;
		}

		cout << "Would you like to purchase another? Y/N: ";
		cin >> ioC;	

		if(ioC == 'Y' || ioC == 'y')
		{
			cout << "Pick a number ";
			cin >> numIO;
		}
		else
		{
			break;
		}
	}

	player.addWeapon(M1911);

	cout << "Game version is " << Version.interm <<endl;

	system("PAUSE");

	return 0;
}