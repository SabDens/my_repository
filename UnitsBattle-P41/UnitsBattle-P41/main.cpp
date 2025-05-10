#include <iostream>
#include "Swordsman.h"
#include "Team.h"
#include "Archer.h"
#include "Bow.h"
#include "Battle.h"
#include "Mage.h"

int main()
{
	Team team1;
	team1.Append(fighter::Swordsman());
	team1.Append(fighter::Mage());
	team1.Append(fighter::Archer());
	team1.SetName("Team 1");

	Team team2;
	team2.Append(fighter::Archer());
	team2.Append(fighter::Mage());
	team2.Append(fighter::Archer());
	team2.SetName("Team 2");
	
	Battle battle1;
	battle1.Append(team1);
	battle1.Append(team2);
	battle1.Start();

	return 0;
}