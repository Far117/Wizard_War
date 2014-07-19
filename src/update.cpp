#include "update.h"
#include "constants.h"
#include "functions.h"

#include <fstream>
#include <sstream>


using namespace std;

void download(bool isWindows){

    clear_screen();

    string changelog="https://raw.githubusercontent.com/Far117/Wizard_War/master/changelog.txt";
    string zip="https://dl.dropboxusercontent.com/u/68488237/updates/wizardwarc%2B%2B/WizardWar.zip";

    string winChange="bitsadmin /transfer mydownloadjob /download /priority normal "+changelog+" c:\\Downloads\\changelog";
    string winZip="bitsadmin /transfer mydownloadjob /download /priority normal "+zip+" C:\\Downloads\\WizardWar.zip";

    string linChange="wget "+changelog;
    string linZip="wget " + zip;

    ifstream in;
    string temp;

    if(isWindows){
        system(winChange.c_str());

        in.open("C:\\Downloads\\changelog");
    }else{
        system(linChange.c_str());

        in.open("changelog.txt");
    }

    while(!in.eof()){
        in >> temp;
        cout << temp << endl;
    }
    in.close();

    if(isWindows){
        remove("C:\\Downloads\\changelog");
    }else{
        remove("changelog.txt");
    }

    cout << "\n\n\n";

    cout << "Downloading update zip...\n\n\n";

    if(isWindows){
        system(winZip.c_str());
    }else{
        system(linZip.c_str());
    }

    cout << "Done!";
    enter();

    clear_screen();

    if(isWindows){
        cout << "You will find the update package in C:/Downloads/WizardWar.zip\nPlease unzip it over your current installation" << endl;
    }else{
        cout << "Please unzip Wizard.War.zip over your current installation" << endl;
    }

    enter();
    cout << "Read those directions!" << endl;
    enter();
    exit(0);
}

void check(bool win){
    string path="https://raw.githubusercontent.com/Far117/Wizard_War/master/data/version";

    string winPath="bitsadmin /transfer mydownloadjob /download /priority normal "+path+" c:\\Downloads\\version";
    string linPath="wget "+path;
    Inf i;
    int ver=i.build;

    int newVer;
    string temp;

    cout << "Checking for updates..." << endl;

    if(win){

        system(winPath.c_str());
        ifstream in("C:\\Downloads\\version");
        in >> temp;
        in.close();

        remove("C:\\Downloads\\version");
    }else {
        system(linPath.c_str());
        ifstream in("version");
        in >> temp;
        in.close();

        remove("version");
    }


    newVer=atoi(temp.c_str());


    if (newVer>ver){
        cout << "Found new version!" << endl << endl;
        enter();

        download(win);
    } else {
        cout << "Current version up to date..." << endl;
        enter();

        clear_screen();
    }
}
