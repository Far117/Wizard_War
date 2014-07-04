#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

#include "functions.h"
#include "spells.h"

float random_float(float,float);

struct Inf{
    float version=0.5;
    std::string type="Beta";
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

    int fire_level;
    float fire_xp;
    float fire_need;

    int water_level;
    float water_xp;
    float water_need;

    int earth_level;
    float earth_xp;
    float earth_need;

    int air_level;
    float air_xp;
    float air_need;

    int force_level;
    float force_xp;
    float force_need;

    int unarmed_level;
    float unarmed_xp;
    float unarmed_need;

    int sword_level;
    float sword_xp;
    float sword_need;

    int levels;

    float money;
    float total_money;

    std::vector<Spell> spell_list;

    /*
    std::vector<std::string> fire{"Smoke","Embers","Fireball","Fire Boulder","Firestorm",
        "Fire Wave","Kamehameha", "Spirit Bomb"};
    std::vector<std::string> water{"Rain","Hail","Torrent","Wave","Ice Dagger","Ice Wave",
        "Absolute Zero","Nuclear Winter"};
    std::vector<std::string> earth{"Dirt","Rock Throw","Pebble Storm","Boulder Smash",
        "Earthquake","Volcano","Meteor Smash","Meteor Storm"};
    std::vector<std::string> air{"Breeze","Super Blow","Torrential Wind","Hurricane","Tornado",
        "Suffocate","Vacuum","Implosion"};
    */

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
        money=floorf(money*10+.5)/10;

        fire_xp=floorf(fire_xp*10+.5)/10;
        fire_need=floorf(fire_need*10+.5)/10;

        water_xp=floorf(water_xp*10+.5)/10;
        water_need=floorf(water_need*10+.5)/10;

        earth_xp=floorf(earth_xp*10+.5)/10;
        earth_need=floorf(earth_need*10+.5)/10;

        air_xp=floorf(air_xp*10+.5)/10;
        air_need=floorf(air_need*10+.5)/10;

        unarmed_xp=floorf(unarmed_xp*10+.5)/10;
        unarmed_need=floorf(unarmed_need*10+.5)/10;

        sword_xp=floorf(sword_xp*10+.5)/10;
        sword_need=floorf(sword_need*10+.5)/10;

        force_xp=floorf(force_xp*10+.5);
        force_need=floorf(force_need*10+.5);
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

        clear_screen();
        levels-=3;
        level++;
        std::cout << "With deep practice and discipline, you have leveled up!" << std::endl;
        enter();
        std::cout << "Would you like to increase your health (1), power (2), or defence (3)?" << std::endl;
        int choice=inputI(": ");

        if(choice==1){
            max_health*=1.5;
        }else if(choice==2){
            max_power*=1.5;
        }else if(choice==3){
            defence*=1.5;
        }

        pop*=1.5;

        clean();
        reset_power();
        reset_health();
    }


    void check(){
        if(health>max_health){health=max_health;}
        if(power>max_power){power=max_power;}
    }

    void interest(){
        deposit*=1.1;
        clean();
    }

    void check_powers(){
        if(fire_xp>=fire_need){
            std::cout << "Your Fire Skills Increased!" << std::endl;
            enter();

            fire_level++;
            fire_need*=1.5;
            levels++;
        }

        if(earth_xp>=earth_need){
            clear_screen();
            std::cout << "Your Earth Skills Increased!" << std::endl;
            std::cout << earth_xp << "\n" << earth_need << "\n";
            enter();

            earth_level++;
            earth_need*=1.5;
            levels++;
        }

        if(water_xp>=water_need){
            clear_screen();
            std::cout << "Your Water Skills Increased!" << std::endl;
            enter();

            water_level++;
            water_need*=1.5;
            levels++;
        }

        if(air_xp>=air_need){
            clear_screen();
            std::cout << "Your Air Skills Increased!" << std::endl;
            enter();

            air_level++;
            air_need*=1.5;
            levels++;
        }

        if(force_xp>=force_need){
            clear_screen();
            std::cout << "Your Force Skills Increased!" << std::endl;
            enter();

            force_level++;
            force_need*=1.5;
            levels++;
        }

        if(unarmed_xp>=unarmed_need){
            clear_screen();
            std::cout << "Your Unarmed Skills Increased!" << std::endl;
            enter();

            unarmed_level++;
            unarmed_need*=1.5;
            levels++;
        }

        if(sword_xp>=sword_need){
            clear_screen();
            std::cout << "Your Blade Skills Increased!" << std::endl;
            enter();

            sword_level++;
            sword_need*=1.5;
            levels++;
        }

        if(levels>=3){
            level_up();
        }
    }

    void gain(int type){ //1=fire, 2=water, 3=earth, 4=air, 5=force, 100=physical, 101=blade
        if (type==1){
            if(lower(element)=="fire"){
                fire_xp+=1+random_float(0,2)*1.2;
            }else{
                fire_xp+=1+random_float(0,2);
            }
        }else if(type==2){
            if(lower(element)=="water"){
                water_xp+=1+random_float(0,2)*1.2;
            }else{
                water_xp+=1+random_float(0,2);
            }
        }else if(type==3){
            if(lower(element)=="earth"){
                earth_xp+=1+random_float(0,2)*1.2;
            }else{
                earth_xp+=1+random_float(0,2);
            }
        }else if(type==4){
            if(lower(element)=="air"){
                air_xp+=1+random_float(0,2)*1.2;
            }else{
                air_xp+=1+random_float(0,2);
            }
        }else if(type==5){
            if(lower(element)=="force"){
                force_xp+=1+random_float(0,2);
            }else{
                force_xp+=1+random_float(0,2);
            }
        }else if(type==100){
            if(lower(element)=="unarmed"){
                unarmed_xp+=1+random_float(0,2)*1.2;
            }else{
                unarmed_xp+=1+random_float(0,2);
            }
        }else if(type==101){
            if(lower(element)=="sword" || lower(element)=="sword combat" || lower(element)=="swords"){
                sword_xp+=1+random_float(0,2)*1.2;
            }else{
                sword_xp+=1+random_float(0,2);
            }
        }

        check_powers();
    }

    float get_multiplier(int y){
        if(y==1){
            return 0.9+((float)fire_level/10);
        }else if(y==2){
            return 0.9+((float)water_level/10);
        }else if(y==3){
            return 0.9+((float)earth_level/10);
        }else if(y==4){
            return 0.9+((float)air_level/10);
        }else if(y==5){
            return 0.9+((float)force_level/10);
        }else if(y==100){
            return 0.9+((float)unarmed_level/10);
        }else if(y==101){
            return 0.9+((float)sword_level/10);
        }else{
            std::cerr << "Unknown type!!!";
        }
    }
};

class monster{
public:
    float health;
    float power;
    float money;
    float defence;

    std::string name;

    std::vector<std::string> titles{"Evil","Bad","Weak","Powerful","Crazy","Rabid",
        "Glowing","King","Slimy","Ugly","Soft","Big","Small"};

    std::vector<std::string> first_half{"Cre","Fra","She","Mera","Jure","Lepa","Zeta","Hira",
        "Giga","Frata","Mita","Chraka","Kli","Orodoro","Oro","Bonadu"};

    std::vector<std::string> second_half{"man","mon","jarto","kilki","gario","ploj","qwad","grat",
        "noto","maru","cha","mira","schep","cretaka","plop"};



    void set_money(){
        money=health/100+defence+(power/10)/(random_float(1,5));
        //if (xp<1){xp=1;}
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
        money=floorf(money*10+.5)/10;
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
