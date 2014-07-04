#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>
#include <cstdlib>
#include <string>


struct Spell{
    std::string name;
    std::string description;
    float power_requirement;
    int type; //1=fire, 2=water, 3=earth, 4=air, 5=force
    int cost;
    bool unlocked;
};



void init_spells();

#endif // SPELLS_H
