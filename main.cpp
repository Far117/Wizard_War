#include <iostream>

#include <cstdlib>
#include <time.h>

#include "save.h"
#include "constants.h"

using namespace std;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    const bool isWindows=true;
#else
    const bool isWindows=false;
#endif // defined

void clear_screen()
{
    if(isWindows){
        system("cls");
    }else{
        system("clear");
    }

    return;
}

void pause(unsigned int ms){
    clock_t goal = ms + clock();
    while (goal > clock());
}

void scroll(){
    for(int x=0;x<=3;x++){
        cout << endl;
        pause(1000);
    }
}

Inf info;
Hero player;

void init(){
    player.name="";
    player.age=0;
    player.element="";
    player.boygirl="";
    player.himher="";
    player.hishers="";
    player.sondaughter="";
    player.power=10;
    player.max_power=10;
    player.max_health=100;
    player.health=100;
    player.pop=12;
    player.xp=0;
    player.x=2.5;
    player.level=1;
    player.deposit=0;
    player.caught=0;
    player.killed=0;
    player.total_attacks=0;
    player.deaths=0;
}

string inputS(string x){

    string temp;

    cout << x;
    getline(cin,temp);
    //cout << endl;

    return temp;
}

int inputI(string x){
    int temp;

    cout << x;
    cin >> temp;
    cout << endl;

    cin.clear();
    cin.ignore();
    //getline(cin, temp);
    return temp;
}

float inputF(string x){
    float temp;

    cout << x;
    cin >> temp;
    cout << endl;

    cin.ignore();

    return temp;
}

string lower(string s){ //converts string to lowercase
    for(int j=0;j<s.length();++j){
        s[j]=tolower(s[j]);
    }
    return s;
}

void splash(){
    cout << "                                   Wizard War" << endl;
    cout << "                                 " << info.type << " v. " << info.version << endl;
    cout << "                                 Press enter...." << endl;
    inputS("");
}

//========================================================= Forward Declarations =================

void town();
void starting_story();
void stats();

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
    cout << "This time, the wizard lost. Telling " << player.name << " that his last wishes, he perished...";
    scroll();
    cout << "[Wizard]: " << player.name << ", you must gain power. Save humanity... Avenge me! And remember...";
    scroll();
    cout << "[Wizard]: Just..." << endl;
    scroll();
    cout <<                                      "SCROLL BURNED OFF HERE" ;
    scroll();
    cout << "//////////////////////////////////////////////////////////////////////" << endl;

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

    inputS("Press enter to continue...");

    town();
}

int main()
{
    init();
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
