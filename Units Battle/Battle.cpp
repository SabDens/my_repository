#include "Battle.h"

Battle::Battle()
    : max_teams(2), turns_count(20)
{
}

Battle::Battle(std::initializer_list<Team> list)
{
    const Team* begin = list.begin();
    for (size_t i = 0; i < list.size(); i++)
    {
        teams.push_back(const_cast<Team*>(begin + i));
    }
    max_teams = list.size();
    turns_count = 20;
}

void Battle::Append(const Team& team)
{
    if (teams.size() == max_teams)
    {
        throw std::exception("Max teams");
    }
    teams.push_back(const_cast<Team*>(&team));
}

void Battle::Start()
{
}
void Battle::Start()
{
    BattleTeam& current = GetRandomTeam();
    Team* target;

    while (true)
    {
        for (size_t i = 0; i < teams.size(); i++)
        {
            if (current.team_id != teams[i].team_id)
            {
                if (current.CanTurn())
                {
                    target = &teams[i].team;
                    current.team.Attack(*target);
                    current.Turn();
                    if (target->IsDead())
                    {
                        std::cout << "Team: " << current.team.GetName() << " Kill\n";
                    }
                }
                else
                {
                    std::cout << "Team: " << current.team.GetName() << " have not turns.\n";
                    break;
                }
            }
        }

        current.have_attack = false;
        current = GetRandomTeam();
    }
}

Battle::BattleTeam::BattleTeam(Team team, int team_id, int turns_count)
    : team(team), team_id(team_id), turns_count(turns_count)
{
}

void Battle::BattleTeam::Turn()
{
    turns_count -= team.Alive(); // Assuming `Alive()` returns the count of living units in the team
}
