#ifndef STANDARD_H_INCLUDED
#define STANDARD_H_INCLUDED

#include <string>
#include "entity.h"
#include <iostream>
#include <fstream>
#define NIL NULL

using namespace std;

void stringToAddress(string str,address_of_row &start_ptr,address_of_row &end_ptr);
void printFile(address_of_folder F,Cursor C);
void hold(); // nahan screen biar nggak dihapus
void printHeader();
void load_all_files(Folder &F);
ListOfString splitString(string str, char delimiter);
ListOfString extractInput(string input);
void fileTOfile(File F);
void quitSave(Folder F);
bool isValidFileName(string file_name,Folder F);


#endif // STANDARD_H_INCLUDED
