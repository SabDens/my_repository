#include "Battle.h"

void Battle::Stop()
{

}

Battle::BattleTeam& Battle::GetRandomTeam()
{
	int rand_index;
	do
	{
		rand_index = rand() % teams.size();
	} while (teams[rand_index].team->IsDead() || !teams[rand_index].have_attack);

	return teams[rand_index];
}

void Battle::ResetAfterBattle()
{

}

bool Battle::SomeoneHasAttack() const
{
	for (size_t i = 0; i < teams.size(); i++)
	{
		if (teams[i].have_attack)
			return true;
	}
	return false;
}

void Battle::ResetTeams()
{
	for (size_t i = 0; i < teams.size(); i++)
	{
		teams[i].have_attack = true;
	}
}

Battle::Battle()
	: max_teams(2), max_turns_count(20)
{
}

void Battle::Append(const Team& team)
{
	if (teams.size() == max_teams)
		throw std::exception("Max teams");
	teams.push_back(BattleTeam(const_cast<Team*>(&team), teams.size() != 0 ? teams.back().team_id + 1 : 0, max_turns_count));
}

void Battle::Start()
{
	Team* target;
	do
	{
		BattleTeam& current = GetRandomTeam();
		for (size_t i = 0; i < teams.size(); i++)
		{
			if (current.team_id != teams[i].team_id)
			{
				if (current.CanTurn())
				{
					target = teams[i].team;
					std::cout << "Team: " << current.team->GetName() << " turn.\n";
					current.team->Attack(*target);
					current.Turn();
					if (target->IsDead())
					{
						std::cout << "Team: " << current.team->GetName() << " kill Team: " << target->GetName() << std::endl;
						teams.erase(teams.cbegin() + i);
					}
				}
				else
				{
					std::cout << "Team: " << current.team->GetName() << " have not turns.\n";
					break;
				}
			}
		}
		current.have_attack = false;

		if (teams.size() == 1)
		{
			std::cout << "Team: " << current.team->GetName() << " win!\n";
			return;
		}
		else if (!SomeoneHasAttack())
		{
			ResetTeams();
		}

	} while (SomeoneHasAttack());

	std::cout << "Draw!\n";
}

Battle::BattleTeam::BattleTeam(Team* team, int team_id, int turns_count)
	: team(team), team_id(team_id), turns_count(turns_count)
{
}

void Battle::BattleTeam::Turn()
{
	turns_count -= team->aLive();
}

bool Battle::BattleTeam::CanTurn() const
{
	return turns_count > 0;
}

void Battle::BattleTeam::Reset()
{
	have_attack = false;
}
