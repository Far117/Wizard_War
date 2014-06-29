#include "save.h"
#include "constants.h"

#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

int inputI(string);
void clear_screen();
void town();
void enter();

bool exists(string name){
    ifstream check(name);
    return check.good();
}

void save(Hero h){
    clear_screen();

    cout << "Saving..." << endl;
    ofstream out("save.dat");

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
    out << h.total_xp;

    out.close();
    cout << "Save complete!" << endl;
    enter();

    town();
}

Hero load(Hero player){
    clear_screen();

    cout << "Loading..." << endl;
    ifstream in("save.dat");

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

    cout << "Load complete!" << endl;
    enter();
    player.clean();

    return player;
}
