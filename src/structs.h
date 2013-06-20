struct Point // struct to serve as base for loaction class
{
	int x;
	int y;
	int z;
};

class Location : public Point
{
public:
	Location(); // default contructor no args

	Location(int _x, int _y, int _z); // constructor that creates a point in 3d space

	void setX(int _x); // set x coord

	void setY(int _y); // set y coord

	void setZ(int _z); // set z coord

	void copyLocation(Location coords); // copies the location of another location

	int getX(); // return x coord

	int getY(); // return y coord

	int getZ(); // return z coord

};
Location::Location()
{
	x = 0;
	y = 0;
	z = 0;
}

Location::Location(int _x, int _y, int _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Location::setY(int _y)
{
	y = _y;
}

void Location::setX(int _x)
{
	x = _x;
}

void Location::setZ(int _z)
{
	z = _z;
}

void Location::copyLocation(Location coords)
{
	x = coords.x;
	y = coords.y;
	z = coords.z;
}

int Location::getX()
{
	return x;
}

int Location::getY()
{
	return y;
}

int Location::getZ()
{
	return z;
}


