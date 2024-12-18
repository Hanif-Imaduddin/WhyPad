#ifndef VISUAL_MODE_H_INCLUDED
#define VISUAL_MODE_H_INCLUDED

#include <iostream>
#include <string>
#include "standard.h"
#include "entity.h"

using namespace std;

void vm_master(address_of_folder F,Cursor C);

void head(address_of_folder F);
void tail(address_of_folder F);
void findText(address_of_folder F,Cursor C,string target);



#endif // VISUAL_MODE_H_INCLUDED
