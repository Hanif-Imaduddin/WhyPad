#ifndef STANDARD_H_INCLUDED
#define STANDARD_H_INCLUDED

#include <string>
#include "entity.h"
#include <iostream>

using namespace std;

void stringToAddress(string str,address_of_row &start_ptr,address_of_row &end_ptr);
void printFile(address_of_folder F,Cursor C);
void printHeader();



#endif // STANDARD_H_INCLUDED
