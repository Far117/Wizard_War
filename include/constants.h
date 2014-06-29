#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <vector>

struct Inf{
    float version=0.1;
    std::string type="Alpha";
    int patch=1;
};

class Hero{ //main player
public:
    std::string name;
    int age;
    std::string boygirl;
    std::string himher;
    std::string hishers;
    std::string sondaughter;
    std::string element;
    float power;
    float max_power;
    float health;
    float max_health;
    int pop;
    float x;
    float xp;
    float defence;
    int level;
    float deposit;
    int caught;

    int killed;
    int total_attacks;
    int deaths;
    float total_xp;

    std::vector<std::string> fire{"Smoke","Embers","Fireball","Fire Boulder","Firestorm","Fire Wave","Kamehameha"};
    std::vector<std::string> water{"Rain","Hail","Torrent","Wave","Ice Dagger","Ice Wave","Absolute Zero"};
    std::vector<std::string> earth{"Dirt","Rock Throw","Pebble Storm","Boulder Smash","Earthquake","Volcano","Meteor Smash"};
    std::vector<std::string> air{"Breeze","Super Blow","Torrential Wind","Hurricane","Tornado","Suffocate","Vacuum"};

    std::vector<int> costs{1,3,4,6,10,12,15};

    void clean(){ //rounds to one decimal
        max_health=floorf(max_health*10+.5)/10;
        health=floorf(health*10+.5)/10;
        max_power=floorf(max_power*10+.5)/10;
        power=floorf(power*10+.5)/10;
        defence=floorf(defence*10+.5)/10;
        xp=floorf(xp*10+.5)/10;
        deposit=floorf(deposit*10+.5)/10;
        x=floorf(x*10+.5)/10;
    }

    void reset_health(){
        clean();
        health=max_health;
    }
    void reset_power(){
        clean();
        power=max_power;
    }

    bool check_xp(){
        if (xp>=x*2.5){
            return true;
        }
        return false;
    }

    void level_up(){
        if(xp>=x*2.5){
            xp-=x*2.5;
            x*=2.5;
            level++;

            max_health*=1.5;
            max_power*=1.5;
            defence*=1.5;

            clean();
            reset_power();
            reset_health();
        }
    }

    void check(){
        if(health>max_health){health=max_health;}
        if(power>max_power){power=max_power;}
    }

    void interest(){
        deposit*=1.1;
        clean();
    }

};

#endif // CONSTANTS_H_INCLUDED
