// union that allows us to create Versioning without using to much space, reserved bytes for double but can hold either value
union GAME_VERSION
{
	int full;
	double interm;
}Version;