#pragma once
#include <vector>
#include "Unit.h"
#include <initializer_list>

class Team
{
protected:
    std::string name;
    static bool isFirst;
    std::vector<Unit> units;
    Unit& GetRandomTarget(Team& targets);

public:
    Team();
    Team(const std::initializer_list<Unit>& list);
    void SetName(const std::string& value);
    const std::string& GetName() const;
    void Append(Unit& unit);
    void Attack(Team& enemies);
    bool IsDead() const;
    void Defense();
};
