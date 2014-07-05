#include "token.h"
#include "constants.h"
#include "save.h"

#include <fstream>
#include <iostream>

using namespace std;

monster load_token(){
    clear_screen();
    make("tokens");

    string folder="tokens/";

    string temp=lower(inputS("Enter the name of who you would like to fight: "));

    string location=folder+temp+".tkn";

    ifstream in(location.c_str());

    monster m;

    in >> m.name;
    in >> temp;
    m.health=atof(temp.c_str());
    in >> temp;
    m.power=atof(temp.c_str());
    in >> temp;
    m.defence=atof(temp.c_str());

    in.close();

    m.set_money();
    return m;
}

void save_token(Hero p){
    clear_screen();
    cout << "Creating token..." << endl;
    make("tokens");

    string location="tokens/"+p.name+".tkn";

    ofstream out(location.c_str());
    out << p.name << endl;
    out << p.max_health << endl;
    out << p.max_power << endl;
    out << p.defence;
    out.close();

    cout << "Done!" << endl;
    enter();
}
