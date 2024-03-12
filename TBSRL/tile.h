#include <SDL.h>
#include <stdio.h>
#include <iostream>

/*
The game map is composed of tiles. Tiles have the following properties:
int xPos: x position of tile
int yPos: y pos of tile
int height: height of a tile. Tile height indicates the top of the tile, so tiles can't be passed under
tiletype type: ground type:
	normal - no special traits
	water - halves movement of non aquatic units. Defined by class?
unit character: Unit occupying the tile, if any
*/
class tile {

private:

	enum tileType {
		normal,
		water
	};

	int xPos;
	int yPos;
	int height;
	tileType type;
	//unit character;

	//set location of tile
	void setPos(int xPos, int yPos);

	//set height of tile
	void setHeight(int height);

	//set unit of tile
	//void setUnit(unit character);



public:

	//Get position of tile. xPos * yPos
	int getTilePos();

	//get height of tile
	int getHeight();

	//get tileType of tile
	tileType getTileType();

	//get unit on tile
	//unit getUnit();

	tile(int xPos,
		int yPos,
		int height,
		tileType type);

};
