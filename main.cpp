#include <iostream>

#include <cstdlib>
#include <vector>

#include "save.h"
#include "constants.h"
#include "functions.h"

using namespace std;




Inf info;
Hero player;




void splash(){
    cout << "                                   Wizard War" << endl;
    cout << "                                " << info.type << " " << info.version << " Patch #" << info.patch << endl;
    cout << "                                 Press enter...." << endl;
    inputS("");
}

//========================================================= Forward Declarations =================

void town();
void starting_story();
void stats();
void apothecary();
void hall();
void bank();
void sheriff();
void outside();
void hospital();

//================================================================= End ==========================

void newCharacter(){
    clear_screen();

    player.name=inputS("What is your name: ");
    player.age=inputI("How old are you: ");
    player.boygirl=lower(inputS("Are you a boy or a girl: "));

    if(player.boygirl=="boy"){
        player.himher="him";
        player.hishers="his";
        player.sondaughter="son";
    } else{
        player.himher="her";
        player.hishers="hers";
        player.sondaughter="daughter";
    }

    player.element=inputS("Is your preferred element Fire, Water, Earth, or Air: ");

    if (player.name=="superskip"){
        town();
    }

    starting_story();
}

void starting_story(){
    clear_screen();
    for (int x=0;x<50;x++) cout << endl;

    cout << "=================================================================";
    cout << "                          The Scroll of Beginnings:";
    scroll();
    cout << "A long, long time ago, in a land far, far away...";
    scroll();
    cout << "A great wizard lived with his only " << player.sondaughter << ", " << player.name << ".";
    scroll();
    cout << "His arch-nemisis, [illegible], had just risen to power...";
    scroll();
    cout << "They fought in an epic clash, destroying entire countries.";
    scroll();
    cout << "Eventually, the wizard won, and peace remained for years.";
    scroll();
    cout << "Until one fateful day, on [illegible], [illegible] returned...";
    scroll();
    cout << "This time, the battle raged for months. Civilization itself hung by a thread...";
    scroll();
    cout << "Almost all life was extinct, save for the rabid monsters summoned to help the dark wizard..." ;
    scroll();
    cout << "This time, the wizard lost. Telling " << player.name << " his last wishes, he perished...";
    scroll();
    cout << "[Wizard]: " << player.name << ", you must gain power. Save humanity... Avenge me! And remember...";
    scroll();
    cout << "[Wizard]: Just..." << endl;
    scroll();
    cout << "[Wizard]: Just..." << endl;
    scroll();
    cout << "[Wizard]: Just..." << endl;
    scroll();
    cout <<                                      "SCROLL BURNED OFF HERE" ;
    scroll();
    cout << "//////////////////////////////////////////////////////////////////////" << endl;
    scroll();

    enter();

    town();
}

void town(){
    clear_screen();
    int choice;

    cout << "Welcome to Pensor! Population: " << player.pop << endl;
    cout << "Would you like to:" << endl;
    cout << "View your Stats? (1)" << endl;
    cout << "Visit the Apothecary? (2)" << endl;
    cout << "Visit Town Hall? (3)" << endl;
    cout << "Visit the Police Offices? (4)" << endl;
    cout << "Go outside? (5)" << endl;
    cout << "Or save? (6)" << endl;

    choice=inputI("["+player.name+"]: ");

    if(choice==1){
        stats();
    } else if (choice==2){
        apothecary();
    }else if (choice==3){
        hall();
    } else if(choice==4){
        sheriff();
    } else if (choice==5){
        outside();
    }else if(choice==6){
        save(player);
    }else if(choice==117){
        player=load(player);
    }

    town();
    }

void stats(){
    clear_screen();
    float need=player.x*2.5-player.xp;
    if(need<0){need=0;}

    cout << "==========Stats========" << endl;
    cout << "Name: " << player.name << endl;
    cout << "Age: " << player.age << endl;
    cout << "Element: " << player.element << endl;
    cout << "XP: " << player.xp << endl;
    cout << "XP Needed to Level Up: " << need << endl;
    cout << "Level: " << player.level << endl;
    cout << "Health: " << player.health << "/" << player.max_health << endl;
    cout << "Power: " << player.power << "/" << player.max_power << endl;
    cout << "Defence: " << player.defence << endl;
    cout << "==========Records======" << endl;
    cout << "Total Attacks Made: " << player.total_attacks << endl;
    cout << "Deaths: " << player.deaths << endl;
    cout << "Enemies Killed: " << player.killed << endl;
    cout << "Total XP Earned: " << player.total_xp << endl;

    if (need==0){
        if (lower(inputS("You have enough XP to level up! Would you like to? "))=="yes"){
            player.xp-=(player.x*2.5);
            player.x*=2.5;

            player.level++;

            player.max_health*=1.5;
            player.max_power*=1.5;
            player.defence*=1.5;

            player.clean();
            player.reset_health();
            player.reset_power();

            cout << "Congratulations! You are now 50% stronger!" << endl;
            enter();
            stats();
        }
    }

    enter();

    town();
}

void apothecary(){
    clear_screen();
    bool bought=true;

    cout << "You have " << player.xp << "XP, " << player.health << "/" << player.max_health << " health," << endl;
    cout << player.max_power << " power, and " << player.defence << " defence." << endl;
    cout << endl;
    cout << "[Lyla]: I have lots of high quality potions for sale. Would you like:" << endl;
    cout << "Small health potion: Heals 20 hp for 1 xp? (1)" << endl;
    cout << "Medium health potion: Heals 75 hp for 3 xp? (2)" << endl;
    cout << "Large health potion? Heals 150 hp for 10 xp? (3)" << endl;
    cout << "Small upper health potion? Increases max health by 5 for 10 xp? (4)" << endl;
    cout << "Medium upper health potion? Increases max health by 20 for 15 xp? (5)" << endl;
    cout << "Large upper health potion? Increases max health by 50 for 30 xp? (6)" << endl;
    cout << "Defence potion? Increases defence by 20% for 15 xp? (7)" << endl;
    cout << "Or maybe a power potion? Increases your power by 20% for 15 xp? (8)" << endl;
    cout << "Or do you just want to get out of here? (9)" << endl;

    int choice=inputI("["+player.name+"]: ");

    if (choice==1&&player.xp>=1){
        player.xp-=1;
        player.health+=20;
    }else if (choice==2&&player.xp>=3){
        player.xp-=3;
        player.health+=75;
    }else if (choice==3&&player.xp>=10){
        player.xp-=10;
        player.health+=150;
    }else if (choice==4&&player.xp>=10){
        player.xp-=10;
        player.max_health+=5;
    }else if (choice==5&&player.xp>=15){
        player.xp-=15;
        player.max_health+=20;
    }else if (choice==6&&player.xp>=30){
        player.xp-=30;
        player.max_health+=50;
    }else if (choice==7&&player.xp>=15){
        player.xp-=15;
        player.defence*=1.2;
    } else if (choice==8&&player.xp>=15){
        player.xp-=15;
        player.max_power*=1.2;
        player.reset_power();
    }else if (choice==9){
        player.check();
        town();
    }else{
        cout << "[Lyla] You don't have that kind of cash!";
        bought=false;
    }

    if(bought){cout << "Thanks for your purchase!" << endl;}

    player.check();
    player.clean();
    enter();
    apothecary();
}

void hall(){
    clear_screen();

    cout << "[Mayor]: Hello, " << player.name << ", is there something you need?" << endl;
    cout << "Would you like to use the bank (1), build new homes (2), or leave (3)?" << endl;

    int choice=inputI("["+player.name+"]: ");

    if (choice==1){
        bank();
    }else if(choice==2){
        if (lower(inputS("Would you like to spend XP to build new homes? "))=="yes"){
                cout << "You have " << player.xp << " XP" << endl;
                int percent=inputI("How much would you like to spend? ");
                if (percent<=player.xp){
                    player.xp-=percent;
                    player.pop*=(1+percent/100);
                    cout << "Population increased by " << percent << "%!";
                    enter();
                    hall();
                }else {
                    cout << "You don't have that much XP!";
                    enter();
                    hall();
                }

            }


    } else if (choice==3){
        town();
    }
        cout << "Invalid choice!";
        enter();
        hall();
}

void bank(){
    clear_screen();
    cout << "You have " << player.xp << " XP in your pocket, and " << player.deposit << " XP in the bank." << endl;
    cout << endl;
    cout << "[Banker]: Hello, sir. Would you like to make a deposit or withdrawl? Or would you like to leave?" << endl;

    string choice=lower(inputS("["+player.name+"]: "));

    if (choice=="leave"){
        town();
    }else if (choice=="deposit"){
        cout << "[Banker] How much would you like to deposit?" << endl;
        float amount=inputF(": ");

        if (amount>player.xp){
            cout << "You don't have that kind of cash!!!" << endl;
            enter();
            bank();
        }else{
            player.xp-=amount;
            player.deposit+=amount;
            player.clean();

            cout << "[Banker]: Thanks for your business!" << endl;
            enter();
            bank();
        }
    } else if(choice=="withdraw"||choice=="withdrawl"){
        float amount=inputF("How much would you like to withdraw? ");

        if (amount>player.deposit){
            cout << "You don't have that kind of money!!!" << endl;
            enter();
            bank();
        }else{
            player.xp+=amount;
            player.deposit-=amount;
            player.clean();

            cout << "[Banker]: Thanks for your business!" << endl;
            enter();
            bank();
        }
    }else if(choice=="leave"){
        town();
    }
}

void sheriff(){
    clear_screen();

    cout << "[Ray]: Ahm the sheriff 'round these parta. Watcha need?" << endl;

    cout << "You can either give him your captured monsters (1)" << endl;
    cout << "Or leave (2)" << endl;
    cout << endl;

    int choice=inputI("["+player.name+"]: ");

    if (choice==1&&player.caught>0){
        float amount=player.caught*3+player.caught+(player.level*1.5);
        player.xp+=amount;

        cout << "[Ray]: Here yer go!" << endl;
        cout << "Received " << amount << " XP from Ray" << endl;
        player.clean();

        enter();
        town();
    }else if (choice==1&&player.caught==0){
        cout << "[Ray]: Whadder yer want? Me to uh takun' nothin' but air?" << endl;
        enter();
        town();
    } else {
        town();
    }
}

void outside(){
    clear_screen();
    monster m;
    int choice;
    int damage;
    bool critical=false;
    bool auto_fight=false;

    m.health=random_float(player.max_health*0.5,player.max_health*2);
    m.power=random_float(player.max_power*0.5,player.max_power*1);
    m.defence=random_float(player.defence*0.5,player.defence*1.8);

    if(rand()%50==0){
        m.name=player.name;
        m.power=player.power;
        m.health=player.health;
        m.defence=player.defence;

        cout << "You spotted the Dark Wizard up ahead!" << endl;
        enter();
        cout << "The Dark Wizard used Mirror Bluff!" << endl;
        enter();
        cout << "What has he done?!?" << endl;
        enter();
    }else{
        m.set_name();
        m.set_status();
    }

    m.set_xp();
    m.xp+=random_float(m.xp-(m.xp*2/5),m.xp*2/5);
    m.clean();

    vector<string> powers;
    if (lower(player.element)=="fire"){powers=player.fire;}
    if (lower(player.element)=="water"){powers=player.water;}
    if (lower(player.element)=="earth"){powers=player.earth;}
    if (lower(player.element)=="air"){powers=player.air;}

    cout << "A " << m.name << " jumps out at you!" << endl;
    enter();

    while(m.health>0 && player.health>0){
        clear_screen();

        cout << "You have " << player.health << "/" << player.max_health << " health" << endl;
        cout << "You have " << player.power << "/" << player.max_power << " power" << endl;
        cout << endl;
        cout << "The " << m.name << " has " << m.health << " health" << endl << endl;
        cout << "How do you want to attack?" << endl;

        for(int j=0;j<powers.size();j++){
            cout << "Use " << powers[j] << "? (" << j << ")" << endl;
        }

        cout << "Just punch it, really hard? ("<< powers.size() <<")" << endl;
        cout << "Or try to escape? ("<<powers.size()+1 << ")" << endl;
        cout << endl << "Hint: Enter 9001 to enter auto punch mode..." << endl;

        if (!auto_fight){
            choice=inputI(": ");
            if (choice==9001){auto_fight=1;}
        }else{
            choice=powers.size();
        }


        if(choice>powers.size()+1||choice<0){
            cout << "You tripped!" << endl;
        }else if (choice==powers.size()){
            player.total_attacks++;
            damage=player.power-m.defence;

            if (damage<1){damage=1;}

            if (rand()%10==0){//critical
                    damage*=rand()%3+2;
                    critical=true;
            }

            cout << "You punched the " << m.name << ", HARD." << endl;
            if (critical){cout << "Critical hit!" << endl; critical=false;}
            cout << "You caused " << damage << " damage!" << endl;

            m.health-=damage;

            if(m.health<0){
                enter();
                break;
            }
        } else if (choice==powers.size()+1) {
            if (rand()%(10-(10/(int)(m.power+.5))+2)==0){
                clear_screen();
                cout << "Escape successful!" << endl;
                player.reset_power();
                enter();
                town();
            } else{
                cout << "Couldn't escape!!!" << endl << endl;
            }
        } else{
            if (player.costs[choice]>player.max_power){
                cout << "You aren't skilled enough to use that!" << endl;
            }else if (player.costs[choice]>player.power){
                cout << "You're to tired to use that!" << endl;
            }else {
                player.total_attacks++;
                cout << "You used " << powers[choice] << "!" << endl;
                damage=player.costs[choice]*11-m.defence;

                if (damage<1){damage=1;}

                if (rand()%10==0){//critical
                    damage*=rand()%3+2;
                    critical=true;
                }



                if (critical){cout << "Critical hit!" << endl; critical=false;}
                cout << "You caused " << damage << " damage!" << endl;

                m.health-=damage;
                player.power-=player.costs[choice];

                if(m.health<0){enter(); break;}
            }

        }

        if (!auto_fight){enter();}

        damage=m.power-player.defence;
        if (damage<1){damage=1;}
        m.power/=1.1;

        cout << endl;
        cout << "The " << m.name << " attacked you for " << damage << " damage!" << endl;
        if (!auto_fight){enter();}

        player.health-=damage;
    }

    player.reset_power();
    player.deposit*=1.1; //10% interest

    if(player.health<=0){
        hospital();
    }else{
        clear_screen();
        cout << "You beat the " << m.name << "!" << endl;
        cout << "You earned " << m.xp << " XP!" << endl;
        player.xp+=m.xp;
        cout << "You found one " << m.name << " body! The sheriff might want it..." << endl;

        player.caught++;
        player.killed++;
        player.total_xp+=m.xp;

        if (player.check_xp()){
            cout << "You have enough XP to level up!" << endl;
        }
        enter();
        town();
    }
}

void hospital(){
    clear_screen();
    player.deaths++;
    bool said_no=false;

    cout << "[Nurse]: Oh my. You seem to have died. Don't worry! We brought you back with SCIENCE!" << endl;
    cout << "[Nurse]: ... And a lot of tylenol..." << endl;
    cout << "[Nurse]: Anyway, to heal you 100% will cost 2 XP. " << endl;
    if (player.xp>=2){
        cout << "[Nurse]: Would you like to pay for that? " << endl;
        if (lower(inputS(": "))=="yes"){
            player.xp-=2;
            player.reset_health();
            cout << "[Nurse]: Thank you!" << endl;
        } else {
            said_no=true;
        }
    } else {
        said_no=true;
    }

    if (said_no){
        cout << "[Nurse]: Oh. Dang, I really wanted that cash." << endl;
        cout << "[Nurse]: We can charge you in demonic-... I mean other ways though." << endl;
        if (lower(inputS("Interested? \n: "))=="yes"){
            player.x*=1.1;
            player.reset_health();
        } else {
            player.health=player.max_health/2;
            player.clean();
        }
    }
    enter();


    clear_screen();
    cout << "[Nurse]: We hope to see you again. Very soon. Hehehehe..." << endl;
    enter();
    town();
}

int main()
{
    player=init(player);
    splash();
    clear_screen();

    if(exists("save.dat")){
        if(lower(inputS("Do you want to load a game or start a new one: "))=="new"){
            newCharacter();
        }else{
            player=load(player);
            town();
        }
    }else{
        newCharacter();
    }

    return 0;
}
