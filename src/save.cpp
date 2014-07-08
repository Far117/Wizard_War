#include "save.h"
#include "constants.h"
#include "functions.h"
#include "spells.h"
#include "Story.h"

#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    const bool isWindows=true;
    #include <direct.h>
#else
    const bool isWindows=false;
#endif // defined


using namespace std;

int inputI(string);
void clear_screen();
void town();
void enter();

extern vector<Spell> spell_list;

void make(string name){
#if isWindows
    _mkdir(name.c_str());
#else
    string path="mkdir "+name;
    system(path.c_str());
#endif
}

bool exists(string name){
    ifstream check(name);
    return check.good();
}

void save(Hero h){
    clear_screen();

    cout << "Saving..." << endl;
    make("data");
    ofstream out("data/save.dat");

    if(!out){
        cerr <<"Error!" << endl;
    }

    out << h.name << "\n";
    out << h.age << "\n";
    out << h.boygirl << "\n";
    out << h.element << "\n";
    out << h.max_power << "\n";
    out << h.power << "\n";
    out << h.max_health << "\n";
    out << h.health << "\n";
    out << h.pop << "\n";
    out << h.xp << "\n";
    out << h.x << "\n";
    out << h.defence << "\n";
    out << h.level << "\n";
    out << h.deposit << "\n";
    out << h.caught << "\n";
    out << h.killed << "\n";
    out << h.total_attacks << "\n";
    out << h.deaths << "\n";
    out << h.total_xp << "\n";

    out << h.money << "\n";

    out << h.fire_level << "\n";
    out << h.fire_xp << "\n";
    out << h.fire_need << "\n";

    out << h.water_level << "\n";
    out << h.water_xp << "\n";
    out << h.water_need << "\n";

    out << h.earth_level << "\n";
    out << h.earth_xp << "\n";
    out << h.earth_need << "\n";

    out << h.air_level << "\n";
    out << h.air_xp << "\n";
    out << h.air_need << "\n";

    out << h.force_level << "\n";
    out << h.force_xp << "\n";
    out << h.force_need << "\n";

    out << h.unarmed_level << "\n";
    out << h.unarmed_xp << "\n";
    out << h.unarmed_need << "\n";

    out << h.sword_level << "\n";
    out << h.sword_xp << "\n";
    out << h.sword_need << "\n";

    out << h.levels;

    out.close();
    save_spells(h);
    save_story();


    if(!exists("data/moneypatch")){
        ofstream out("data/moneypatch");
        out.close();
    }


    cout << "Save complete!" << endl;
    enter();

    town();
}

Hero load(Hero player){
    clear_screen();
    save_updater();

    cout << "Loading..." << endl;
    ifstream in("data/save.dat");

    if(!in){
        cerr <<"Error!" << endl;
    }

    vector<string> lines;
    string line;

    while(!in.eof()){
        in >> line;
        lines.push_back(line);
        cout << line << endl;
    }

    in.close();

    stringstream convert;

    player.name=lines[0];

    convert << lines[1];
    convert >> player.age;
    convert.str("");

    player.boygirl=lines[2];

    if(player.boygirl=="boy"){
        player.himher="him";
        player.hishers="his";
        player.sondaughter="son";
    }else {
        player.himher="her";
        player.hishers="hers";
        player.sondaughter="daughter";
    }


    player.element=lines[3];

    player.max_power=std::atof(lines[4].c_str());

    player.power=atof(lines[5].c_str());

    player.max_health=atof(lines[6].c_str());

    player.health=atof(lines[7].c_str());

    player.pop=atoi(lines[8].c_str());

    player.xp=atof(lines[9].c_str());

    player.x=atof(lines[10].c_str());

    player.defence=atoi(lines[11].c_str());

    player.level=atoi(lines[12].c_str());

    player.deposit=atof(lines[13].c_str());

    player.caught=atoi(lines[14].c_str());

    player.killed=atoi(lines[15].c_str());

    player.total_attacks=atoi(lines[16].c_str());

    player.deaths=atoi(lines[17].c_str());

    player.total_xp=atof(lines[18].c_str());

    player.money=atof(lines[19].c_str());

    player.fire_level=atoi(lines[20].c_str());
    player.fire_xp=atof(lines[21].c_str());
    player.fire_need=atof(lines[22].c_str());

    player.water_level=atoi(lines[23].c_str());
    player.water_xp=atof(lines[24].c_str());
    player.water_need=atof(lines[25].c_str());

    player.earth_level=atoi(lines[26].c_str());
    player.earth_xp=atof(lines[27].c_str());
    player.earth_need=atof(lines[28].c_str());

    player.air_level=atoi(lines[29].c_str());
    player.air_xp=atof(lines[30].c_str());
    player.air_need=atof(lines[31].c_str());

    player.force_level=atoi(lines[32].c_str());
    player.force_xp=atof(lines[33].c_str());
    player.force_need=atof(lines[34].c_str());

    player.unarmed_level=atoi(lines[35].c_str());
    player.unarmed_xp=atof(lines[36].c_str());
    player.unarmed_need=atof(lines[37].c_str());

    player.sword_level=atoi(lines[38].c_str());
    player.sword_xp=atof(lines[39].c_str());
    player.sword_need=atof(lines[40].c_str());

    player.levels=atoi(lines[41].c_str());

    player=load_spells(player);
    load_story();

    cout << "Load complete!" << endl;
    //cout << player.earth_level << endl << player.earth_xp << endl << player.earth_need << endl;
    enter();
    player.clean();

    return player;
}

void save_spells(Hero player){
    ofstream out("data/spells.dat");

    for(int x=0;x<player.spell_list.size();x++){
        out << player.spell_list[x].unlocked << "\n";
    }

    out.close();
}

Hero load_spells(Hero p){
    if (!exists("data/spells.dat")){save_spells(p);}
    ifstream in("data/spells.dat");

    int x=0;
    string y="";

    while(!in.eof()){
        in >> y;
        p.spell_list[x].unlocked=atoi(y.c_str());
        x++;
    }

    return p;
}

void save_updater(){

    if(!exists("data/moneypatch")){
        cout << "\nApplying Money Patch (0.5 update)..." << endl;

        ofstream out("data/save.dat",ios::app);
        out << "\n" << 1;
        out.close();

        ofstream o ("data/moneypatch");
        o.close();

        cout << "Success!\n" << endl;
    }

    if(!exists("data/xppatch")){
        cout <<"\nApplying XP Patch (0.5 update)..." << endl;

        ofstream out("data/save.dat",ios::app);

        out << "\n" << 1 << "\n";
        out << 0 << "\n";
        out << 5 << "\n";

        for(int x=0;x<6;x++){
            out << 1 << "\n";
            out << 0 << "\n";
            out << 5 << "\n";
        }
        out.close();

        out.open("data/xppatch");
        out.close();

        cout << "Success!" << endl;
    }
}

extern Completed story;

void save_story(){
    ofstream out("data/story.dat");
    out << story.first_power;
    out.close();
}

void load_story(){
    if(!exists("data/story.dat")){
        ofstream out("data/story.dat");
        out.close();
    }

    ifstream in("data/story.dat");

    string s;
    in >> s;
    in.close();

    story.first_power=atoi(s.c_str());
}
