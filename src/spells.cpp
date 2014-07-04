#include "spells.h"

#include <vector>

//#include <iostream>

//using namespace std;



Spell push;
Spell torch;
Spell fireball;
Spell slap;
Spell pebble_rain;
Spell air_wave;

std::vector<Spell> spell_list;

void init_spells(){

    push.name="Push";
    push.description="Send your enemies stumbling backwards, hopefully into a wall or over a cliff!";
    push.power_requirement=.5;
    push.type=5;
    push.cost=5;

    torch.name="Torch";
    torch.description="Send a small burst of fire into your opponent's face!";
    torch.power_requirement=2;
    torch.type=1;
    torch.cost=15;

    fireball.name="Fireball";
    fireball.description="Hurl a ball of pure fire into your opponent!";
    fireball.power_requirement=3;
    fireball.type=1;
    fireball.cost=20;

    slap.name="Slap";
    slap.description="Slap your opponent with a small burst of water!";
    slap.power_requirement=2;
    slap.type=2;
    slap.cost=15;

    pebble_rain.name="Pebble Rain";
    pebble_rain.description="Send the pebbles at your feet flying into the air, and have them ran down on your opponent!";
    pebble_rain.power_requirement=2.5;
    pebble_rain.type=3;
    pebble_rain.cost=17;

    air_wave.name="Air Wave";
    air_wave.description="Call the winds to send your opponent flying!";
    air_wave.power_requirement=2.8;
    air_wave.type=4;
    air_wave.cost=20;

    spell_list.push_back(push);
    spell_list.push_back(torch);
    spell_list.push_back(slap);
    spell_list.push_back(pebble_rain);
    spell_list.push_back(air_wave);
    spell_list.push_back(fireball);

    for(int x=0;x<spell_list.size();x++){
        spell_list[x].unlocked=false;
    }
}


