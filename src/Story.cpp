#include "Story.h"

#include "constants.h"
#include "functions.h"

using namespace std;

Completed story;

void init_story(){
    story.first_power=false;

    story.kidnapped=false;
    story.kidnapped_a=false;
}

monster lost_son(monster m){
    clear_screen();

    cout << "Help! Help!";
    scroll();
    cout << "You need to help me! My son has been kidnapped by a crazy wolf!!!";
    scroll();
    cout << "Please! I'll pay you ";

    return m;
}

monster get_story(monster m){
    m=lost_son(m);

    return m;
}
