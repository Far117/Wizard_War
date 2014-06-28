#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <iostream>
#include <cmath>

struct Inf{
    float version=0.1;
    std::string type="Pre-Alpha";
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
    int deposit;
    int caught;

    int killed;
    int total_attacks;
    int deaths;
    int total_xp;



    void clean(){ //rounds to one decimal
        max_health=floorf(max_health*10+.5)/10;
        health=floorf(health*10+.5)/10;
        max_power=floorf(max_power*10+.5)/10;
        power=floorf(power*10+.5)/10;
        defence=floorf(defence*10+.5)/10;
        xp=floorf(xp*10+.5)/10;
    }

    void reset_health(){
        health=max_health;
    }
    void reset_power(){
        power=max_power;
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

};

#endif // CONSTANTS_H_INCLUDED
