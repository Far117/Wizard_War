#ifndef SAVE_H
#define SAVE_H

#include "constants.h"

void save_updater();

void save(Hero);
Hero load(Hero);

void save_spells(Hero);
Hero load_spells(Hero);

void save_story();
void load_story();

bool exists(std::string);
void make(std::string);
#endif // SAVE_H
