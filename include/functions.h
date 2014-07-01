#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

class Hero;

void clear_screen();
void pause(unsigned int);
void scroll();
void enter();
std::string inputS(std::string);
int inputI(std::string);
float inputF(std::string);
float random_float(float,float);
bool contains(std::string,std::string);
std::string lower(std::string);
Hero init(Hero);

#endif // FUNCTIONS_H
