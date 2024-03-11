#include <SDL.h>
#include <stdio.h>
#include <iostream>

/*
Unit describes the player and enemies throughout the game. All units have the following stats:
string name - name of the unit
string type - human, humanoid, or beast
string charClass - Specific class of the unit. Humans can change class
int xPos - x position on grid
int yPos - y position on grid
int height - z position on grid
int stats[]:
	HP  - Hit Points. Unit dies when hit points are reduced to zero
	SP - Special Points. Required for skill and magic use. Monsters recover SP by attacking
	Atk - Attack. Damage dealt is based on attack. Most weapons increase Atk
	Def - Defense. Reduces damage. Armor increases Def
	Int - Intelligence. Strength of magic skills and healing
	Res - Resistance. Reduces magic damage.
	Hit - Hit chance. Hit improves the chance of attacks landing
	Ev - Evade. Ev improves the chance of avoiding attacks.
	Grd - Guard. Grd improves the chance of blocking attacks. Weapons have a base Grd that shields can increase. 
	Attacks should check if attack lands, then if attack is blocked
	Mv - Movement. Distance a unit can move. Average is 4
	Jmp - Jump. Height units can jump. Average is 1
double aptitudes[] - Multiplier to stats that affects growth. Units can have different base stats,
but their class dictates how much their base stats are multiplied by
*/
class unit {

private:
	std::string name;
	std::string type;
	std::string charClass;
	int xPos;
	int yPos;
	int height;
	int stats[12];
	double aptitudes[12];

	enum statDef {
		HP,
		SP,
		Atk,
		Def,
		Int,
		Res,
		Hit,
		Ev,
		Grd,
		Mv,
		Jmp
	};


	//Setter. Change the xPos and yPos by given amount. Change height as needed
	//Check if movement is valid
	void move(int xMove, int yMove);

	//Increase most stats by 1 each level up. Move and jump shouldn't change often
	void levelUp();

	//Set name of a unit
	void setName(std::string);

	//Set type of a unit
	void setType(std::string);

	//Set charClass of a unit
	void setCharClass(std::string);

public:
	//Constructor
	unit(std::string name,
		std::string type,
		std::string charClass,
		int stats[],
		double aptitudes[]);

};