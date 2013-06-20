// include all external header files
#include<string>
#include<vector>
#include "gunlist.h"
#include "perklist.h"
#include "structs.h"
#include "player_enum.h"

using namespace std; // use namespace so we don't need to prefix std:: before std methods

class Player : public Gun, public Perk // player class that inherits multiple classes so I can use their methods, data members, and create lists of their objects
{
	private:

	int defaultPoints;
	int MAX_GUNS;
	int MAX_PERKS;

	public:

	int down_count;
	int revives;
	bool revived;
	int kills;
	bool perkAmountExtended;
	int health;
	int speed;
	PLAYER_STATE playerState;
	string name;
	vector<Gun> guns;
	vector<Perk> perks;
	Location location;

	Player();//default contructor with no args

	Player(int life, int spd, string Pname); // constructor with args

	void setName(string fname, string lname, string mname = ""); // sets the players name

	void addPerk(Perk perk_a_cola); // add perk to perk vector

	void addWeapon(Gun weapon); // add weapon to weapon vector

	void clearPerks(); // removes all perks from vector

	void playerDowned(); // changes player state to downed

	void reviving(); // revives player

	void gotKill(); // sets kill count up 1

	int getPoints(); // return player points

	void subtractPoints(int amt); // subtracts players points

	void addPoints(int amt); // adds player points
};

Player::Player()
{
	health = 100;
	speed = 100;
	name = "";
	perkAmountExtended = false;
	bool revived = false;
	playerState = UP;
	MAX_GUNS = 2;
	MAX_PERKS = 4;
	defaultPoints = 9500;
}

Player::Player(int life, int spd, string Pname)
	{
		health = life;
		speed = spd;
		name = Pname;
		perkAmountExtended = false;
		bool revived = false;
		playerState = UP;
		MAX_GUNS = 2;
		MAX_PERKS = 4;
		defaultPoints = 9500;
}

void Player::addPoints(int amt)
	{
		defaultPoints += amt;
	}

void Player::subtractPoints(int amt)
	{
		if(defaultPoints == 0)
		{

		}
		else
		{
			defaultPoints -= amt;

			if(defaultPoints < 0)
			{
				defaultPoints;
			}
		}
	}

int Player::getPoints()
	{
		return defaultPoints;
	}

void Player::setName(string fname, string lname, string mname)
{
	name = fname + " " + mname + " " + lname;
}

void Player::addPerk(Perk perk_a_cola)
{
	int perkSlotsUsed = perks.size();

	if(!perkAmountExtended)
	{
		if(perkSlotsUsed != MAX_PERKS)
		{
			for(int j = 0; j < perkSlotsUsed; j++)
			{
				if(perks[j].name != perk_a_cola.name)
				{
					perks.push_back(perk_a_cola);
					break;
				}
			}
		}
	}
	else
	{
		perks.push_back(perk_a_cola);
	}
}
	
void Player::addWeapon(Gun weapon)
{
	int weaponsList = guns.size();

	if(weaponsList != MAX_GUNS)
	{
		guns.push_back(weapon);
	}
}
	
void Player::clearPerks()
{
	perks.clear();
}
	
void Player::playerDowned()
{
	clearPerks();
	down_count++;
}
	
void Player::reviving()
{
	revives++;
}
	
void Player::gotKill()
{
	kills++;
}