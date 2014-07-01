#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

#include "functions.h"

float random_float(float,float);

struct Inf{
    float version=0.2;
    std::string type="Alpha";
    int patch=3;
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

    int fire_level;
    float fire_xp;
    int water_level;
    float water_xp;
    int earth_level;
    float earth_xp;
    int air_level;
    float air_xp;

    int unarmed_level;
    float unarmed_xp;

    int levels;
    float money;

    std::vector<std::string> fire{"Smoke","Embers","Fireball","Fire Boulder","Firestorm",
        "Fire Wave","Kamehameha", "Spirit Bomb"};
    std::vector<std::string> water{"Rain","Hail","Torrent","Wave","Ice Dagger","Ice Wave",
        "Absolute Zero","Nuclear Winter"};
    std::vector<std::string> earth{"Dirt","Rock Throw","Pebble Storm","Boulder Smash",
        "Earthquake","Volcano","Meteor Smash","Meteor Storm"};
    std::vector<std::string> air{"Breeze","Super Blow","Torrential Wind","Hurricane","Tornado",
        "Suffocate","Vacuum","Implosion"};

    std::vector<int> costs{1,2,4,8,16,32,64,128,256,512,1024,2048};

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
        if(check_xp()){
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

class monster{
public:
    float health;
    float power;
    float xp;
    float defence;

    std::string name;

    std::vector<std::string> titles{"Evil","Bad","Weak","Powerful","Crazy","Rabid",
        "Glowing","King","Slimy","Ugly","Soft","Big","Small"};

    std::vector<std::string> first_half{"Cre","Fra","She","Mera","Jure","Lepa","Zeta","Hira",
        "Giga","Frata","Mita","Chraka","Kli","Orodoro","Oro","Bonadu"};

    std::vector<std::string> second_half{"man","mon","jarto","kilki","gario","ploj","qwad","grat",
        "noto","maru","cha","mira","schep","cretaka","plop"};



    void set_xp(){
        xp=health/100+defence+(power/10)/(random_float(1,3));
        if (xp<1){xp=1;}
    }

    void set_name(){
        int r=rand()%titles.size();
        name=name+titles[r];

        r=rand() % first_half.size();
        name=name+ " " + first_half[r];


        r=rand() % second_half.size();
        name=name+second_half[r];
    }

    void clean(){
        health=floorf(health*10+.5)/10;
        power=floorf(power*10+.5)/10;
        defence=floorf(defence*10+.5)/10;
        xp=floorf(xp*10+.5)/10;
    }

    void set_status(){
        if (contains("Giga",name)){
        power*=1.8;
        health*=1.9;
        defence*=1.5;
    }

    if (contains("King", name)){
        power*=1.9;
        health*=2;
        defence*=1.8;
    }

    if (contains("Weak", name)){
        power/=1.5;
        health/=1.4;
        defence/=1.5;
    }

    if (contains("Rabid", name)){
        power*=2;
        health/=2.5;
        defence=0;
    }

    if (contains("Crazy", name)){
        power*=2;
        health/=2;
        defence=0;
    }

    if (contains("plop",name)){
        power/=1.5;
        health/=1.5;
        defence/=1.5;
    }

    }
};

#endif // CONSTANTS_H_INCLUDED
