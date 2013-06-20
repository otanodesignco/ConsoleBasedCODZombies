#include<string>
#include "gun_enum.h"

using namespace std;

class Gun
{
public:
	
	int Damage;
	int Rate_Of_Fire;
	double Reload_speed;
	Multiplier multiplier;
	double multiplers[3];
	Fire_Mode fire_mode;
	int Mag_Size;
	int Clip;
	int Max_Ammo;
	int Capacity;
	string name;
	int limit;
	bool pack_a_punched;
	bool Zoomed_In;
	int price;
	Mobility Gun_Weight;
	Bought_Method obtained;
	Weapon_Slot weapon_position;
	Gun_Class Weapon_Class;

	Gun();

	Gun(string gname, int dmg, int rof, double rspd, Fire_Mode FM, int mag, int maxammo, Mobility weight, Gun_Class cl,Weapon_Slot pos);

	void setModifiers(double head, double chest, double abdomen);

	void setAmmoCapacity(int mag,int max_ammo);

	double HeadMultiplier();

	double ChestMultiplier();

	double AbdomenMultiplier();

	bool Limited();

	bool Pack_A_Punched();

	void Reload();

	bool ClipEmpty();

	bool Out_Of_Ammo();

	bool Zoomed();

	void ZoomIn();

	void ZoomOut();

};

Gun::Gun()
{

}

Gun::Gun(string gname, int dmg, int rof, double rspd, Fire_Mode FM, int mag, int maxammo, Mobility weight, Gun_Class cl,Weapon_Slot pos)
{
	name = gname;
	Damage = dmg;
	Rate_Of_Fire = rof;
	fire_mode = FM;
	Mag_Size = mag;
	Max_Ammo = maxammo;
	Capacity = mag + maxammo;
	Gun_Weight = weight;
	Weapon_Class = cl;
	weapon_position = pos;
}

double Gun::HeadMultiplier()
	{
		return multiplers[HEAD];
	}

double Gun::ChestMultiplier()
	{
		return multiplers[CHEST];
	}

double Gun::AbdomenMultiplier()
	{
		return multiplers[ABDOMEN];
	}

bool Gun::Limited()
	{
		return ((limit > 0) ? true : false);
	}

void Gun::setModifiers(double head, double chest, double abdomen)
	{
		multiplers[HEAD] = head;
		multiplers[CHEST] = chest;
		multiplers[ABDOMEN] = abdomen;
	}

void Gun::setAmmoCapacity(int mag,int max_ammo)
	{
		Mag_Size = mag;
		Max_Ammo = max_ammo;
		Capacity = Mag_Size + Max_Ammo;
	}

void Gun::Reload()
	{
		int temp;

		if(ClipEmpty())
		{
			if(!Out_Of_Ammo())
			{
			
				if(Max_Ammo >= Mag_Size)
				{
				Clip = Mag_Size;
				Max_Ammo = Max_Ammo - Mag_Size;
				}
				else if (Max_Ammo < Mag_Size && Max_Ammo > 0)
				{
					Clip = Max_Ammo;
					Max_Ammo = Max_Ammo - Max_Ammo;
				}
			}
		}
		else
		{
			if(!Out_Of_Ammo())
			{
				temp = Mag_Size - Clip;

				if(Max_Ammo >= temp)
				{
					Clip = Clip + temp;
					Max_Ammo = Max_Ammo - temp;
				}
				else if(Max_Ammo < temp && Max_Ammo > 0)
				{
					Clip = Max_Ammo;
					Max_Ammo = Max_Ammo - Max_Ammo;
				}
			}
		}
	}


bool Gun::Pack_A_Punched()
	{
		return pack_a_punched;
	}

bool Gun::ClipEmpty()
	{
		return ((Clip == 0) ? true : false);
	}

bool Gun::Out_Of_Ammo()
	{
		return ((Max_Ammo == 0) ? true : false);
	}

bool Gun::Zoomed()
	{
		return Zoomed_In;
	}

void Gun::ZoomIn()
	{
		Zoomed_In = true;
	}

void Gun::ZoomOut()
	{
		Zoomed_In = false;
	}