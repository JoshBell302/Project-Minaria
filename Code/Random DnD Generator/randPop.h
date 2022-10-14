#pragma once
#include <string>

// Constant Values
int const MAX_RACES = 10;

/*
 Name:			race
 Purpose:		The exact information for each race
 Variables:		bool apartOfVillage		If this race is apart of the village for the randomization
				float percentage		The percentage of the city this race is apart of
				int populationNumber	The exact number of the populace for that race in that city
*/
class race {
public:
	bool apartOfVillage = 0;
	float percentage = 0.0;
	int populationNumber = 0;
};

/*
 Name:			allRaces
 Purpose:		To keep a clean and collected list of each different races available for the city
 Variables:		race ...				Each of these are the information for that particular race.
*/
class allRaces {
public:
	race race[MAX_RACES];
	std::string names[MAX_RACES] = {
	"Dragonborn", "Dwarf", "Elf", "Genasi", "Gnome", "Halfelf", "Halfling", "Halforc", "Human", "Tiefling"
	};
};

/*
 Name:			fields
 Purpose:		To be filled for the use of providing the user with random variables that can be
				used and manipulated or however the user seems fair.
 Variables:		allRaces races			This is a list of all different forms of races avaiable for the town.
				string type				This is the type of city like village, city, etc. (DMG pg. 16-17).
				string name				This is the name of the town.
*/
class fields {
public:
	allRaces population;
	std::string type = "";
	std::string name = "";
};

// ================================================================================================

fields racesPermitted(fields filling) {
	// Loop between all races to ask if they are within this city
	std::string responce;
	for (int i = 0; i < MAX_RACES; i++) {
		std::cout << "Is the race '" << filling.population.names[i] << "' wanted in this village?\n1 for Yes and 0 for No: ";
		std::cin >> responce;
		filling.population.race[i].apartOfVillage = stoi(responce);
	}
	return filling;
}

/*
 Name:			fillFields
 Description:	This fucntion is to fill the exact fields and boundaries to make sure the data
				returned is the data needed. Some of the fields are the 'max', 'min', 'races'
				fields for other functions in the future to use.
 Input:
 Output:
 */

fields fillFields() {
	fields toFill;
	toFill = racesPermitted(toFill);
	return toFill;
}