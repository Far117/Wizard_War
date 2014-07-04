#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>
#include <cstdlib>
#include <string>




struct Spell{
    std::string name;
    std::string description;
    float power_requirement;
    int type; //1=fire, 2=water, 3=earth, 4=air, 5=force, 100=physical, 101=blade
    int cost;
    bool unlocked;
    //float damage; // for physical attacks
};

#include "constants.h"

Hero init_spells(Hero);

#endif // SPELLS_H
