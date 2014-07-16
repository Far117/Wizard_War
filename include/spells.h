#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>
#include <cstdlib>
#include <string>

//#include <constants.h>
class monster;
class Hero;


struct Spell{
    std::string name;
    std::string description;
    float power_requirement;
    int type; //1=fire, 2=water, 3=earth, 4=air, 5=force, 100=physical, 101=blade, 102=Alteration, 103=Forbidden
    int cost;
    bool unlocked;
    bool ultimate=false;
    int intelligence;
    //float damage; // for physical attacks

};


#include "constants.h"

Hero init_spells(Hero);
monster init_evil_spell(monster, Hero);

#endif // SPELLS_H
