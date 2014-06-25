#include <iostream>

using namespace std;

struct info{
    float version=0;
    string type="pre-alpha";
};

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

    cin.ignore();

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

void splash(){
    cout << "          Wizard War" << endl;
    cout << "     " << type << " v " << version << endl;
    cout << "        Press enter...." << endl;
    inputS("");
}

int main()
{
    return 0;
}
