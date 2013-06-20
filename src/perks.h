#include<string>
#include "perk_enum.h"
using namespace std;

class Perk
{
public:
	int cost;
	float modifer;
	Mod_Types modifierType; 
	string name;
	string effect;
	bool enabled;

	Perk();

	Perk(string Pname, int price, Mod_Types type, float Pmodifier);

	~Perk()
	{};

	friend ostream& operator<<(ostream& os, const Perk& Perks)
	{
		os << Perks.name;
		return os;
	}

	void setPerkName(string PerkName);

	string getPerkName();

	void setModifierAction(Mod_Types action);
};

Perk::Perk()
{

}

Perk::Perk(string Pname, int price, Mod_Types type, float Pmodifier)
	{
		name = Pname;
		cost = price;
		modifierType = type;
		modifer = Pmodifier;
		enabled = false;
	}

void Perk::setModifierAction(Mod_Types action)
	{
			modifierType = action;
	}

string Perk::getPerkName()
	{
		if(name != "")
		{
			return name;
		}
		else
		{
			return "";
		}
	}

void Perk::setPerkName(string PerkName)
	{
		name = PerkName;
	}