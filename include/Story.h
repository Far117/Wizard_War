#ifndef STORY_H
#define STORY_H

#include "constants.h"

struct Completed{
    bool first_power;

    bool kidnapped;
    bool kidnapped_a;
};



void init_story();

monster get_story(monster m);

monster lost_son(monster m);

#endif // STORY_H
