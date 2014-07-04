#ifndef SAVE_H
#define SAVE_H

#include "constants.h"

void save_updater();

void save(Hero);
Hero load(Hero);

void save_spells();
void load_spells();

bool exists(std::string);
void make(std::string);
#endif // SAVE_H
