#include "Team.h"

bool Team::isFirst = true;

Unit& Team::GetRandomTarget(Team& targets)
{
    int rand_index;
    do
    {
        rand_index = rand() % targets.units.size() + 1;
    } while (targets.units[rand_index].IsDead());

    return targets.units[rand_index];
}

Team::Team()
    : name("NoName")
{
    if (isFirst)
    {
        isFirst = false;
        srand(time(0));
    }
}

Team::Team(const std::initializer_list<Unit>& list)
    : Team()
{
    const Unit* begin = list.begin();
    for (size_t i = 0; i < list.size(); i++)
    {
        units.push_back(*(begin + i));
    }
}

void Team::SetName(const std::string& value)
{
    name = value;
}
const std::string& Team::GetName() const
{
    return name;
}

void Team::Append(Unit& unit)
{
    units.push_back(unit);
}

void Team::Attack(Team& enemies)
{
    for (size_t i = 0; i < units.size(); i++)
    {
        if (enemies.IsDead())
        {
            break;
        }
        auto& target = GetRandomTarget(enemies);
        units[i].Attack(target);
    }
}

bool Team::IsDead() const
{
    bool flag = true;
    for (size_t i = 0; i < units.size(); i++)
    {
        if (!units[i].IsDead())
        {
            flag = false;
            break;
        }
    }
    return flag;
}
