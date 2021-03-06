#include "functions.h"
#include "constants.h"

#include <cstdlib>
#include <time.h>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

bool exists(string);
void check(bool);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    const bool isWindows=true;
#else
    const bool isWindows=false;
#endif // defined


void clear_screen() {
    if(isWindows){
        system("cls");
    }else{
        //system("clear");
        cout << "\033[2J\033[1;1H";
    }

    return;
}

void pause(unsigned int ms){

    //std::this_thread::sleep_for(std::chrono::milliseconds(ms));

    clock_t goal = ms + clock();
    while (goal > clock());

}

void scroll(){
    for(int x=0;x<=3;x++){
        cout << endl;
        pause(1000);
    }
}

void enter(){
    cout << "Press enter to continue...";
    //cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    cin.ignore();
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

float random_float(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

bool contains(string s, string check){
    if (s.find(check) != string::npos) {
        return true;
    }
    return false;
}

Hero init(Hero p){

    check(isWindows);

    p.name="";
    p.age=0;
    p.element="";
    p.boygirl="";
    p.himher="";
    p.hishers="";
    p.sondaughter="";
    p.power=10;
    p.max_power=10;
    p.max_health=100;
    p.health=100;
    p.pop=12;
    p.xp=0;
    p.x=2.5;
    p.level=1;
    p.deposit=0;
    p.caught=0;
    p.killed=0;
    p.total_attacks=0;
    p.deaths=0;
    p.defence=2;
    p.money=1;

    p.levels=0;

    p.fire_level=1;
    p.fire_xp=0;
    p.fire_need=5;

    p.water_level=1;
    p.water_xp=0;
    p.water_need=5;

    p.earth_level=1;
    p.earth_xp=0;
    p.earth_need=5;

    p.air_level=1;
    p.air_xp=0;
    p.air_need=5;

    p.unarmed_level=1;
    p.unarmed_xp=0;
    p.unarmed_need=5;

    p.force_level=1;
    p.force_xp=0;
    p.force_need=5;

    p.sword_level=1;
    p.sword_xp=0;
    p.sword_need=5;

    unsigned int time_ui = static_cast<unsigned int>( time(NULL) );
    srand(time_ui);

    return p;
}

void install(){
    if(!exists("data/installed")){
        cout << "Installing..." << endl;
        ofstream out("data/moneypatch");
        out.close();
        out.open("data/xppatch");
        out.close();

        out.open("data/installed");
        out.close();

        cout << "Done!" << endl;
    }
}
