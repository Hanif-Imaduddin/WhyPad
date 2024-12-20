#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <iostream>
#include <cmath>
#define NIL NULL


using namespace std;

typedef struct elmRow * address_of_row; //pointer to element row
typedef struct elmFile * address_of_file; //pointer to element file
typedef struct elmFolder * address_of_folder; //pointer to element folder
typedef struct elmStackOfLog * address_of_sol; // pointer to element stack of log

struct elmRow{
    char info;
    elmRow *next,*prev;
};
struct Row{
    elmRow *first,*last;
    int length;
};

struct elmFile{
    Row info;
    elmFile *next,*prev;
};
struct File{
    elmFile *first,*last;
    int length;
    string name;
};
struct elmFolder{
    File info;
    elmFolder *next;
};
struct Cursor{
    elmRow *cell_ptr;
    elmFile *row_ptr;
    elmFolder *file_ptr;
};
struct Folder{
    elmFolder *first;
    int length;
    string name;
};

elmRow* createElmRow(char info);
Row createRow();

elmFile* createElmFile(Row R);
File createFile(string name);

elmFolder* createElmFolder(File F);
Folder createFolder(string folder_name);

Cursor createCursor(address_of_folder F);

struct Clipboard{ // Stack
    string info[8];
    int height,top;
};

Clipboard createClipboard();
bool isFullClipboard(Clipboard C);
bool isEmptyClipboard(Clipboard C);
void pushClipboard(Clipboard &C,string p);
void popClipboard(Clipboard &C,string &p);
string peekClipboard(Clipboard C);


/* Instruction code: {Delete row elements: 0, Insert row elemen: 1, Delete Row: 2,
Insert Row: 3}*/

struct Log{
    int instruction_code;
    elmFolder* file_ptr;
    elmFile* row_ptr;
    elmRow *start_ptr,*end_ptr;
};
struct elmStackOfLog{
    Log info;
    elmStackOfLog *next;
};
struct StackOfLog{
    elmStackOfLog *top;
};
Log createLog(int instruction_code,elmFolder* file_ptr,elmFile *row_ptr,elmRow *start_ptr,elmRow *end_ptr);
elmStackOfLog* createElmStackOfLog(Log L);
StackOfLog createStackOfLog();

bool isEmptyStackOfLog(StackOfLog S);
void pushStackOfLog(StackOfLog &S, address_of_sol p);
void popStackOfLog(StackOfLog &S, address_of_sol &p);
address_of_sol peekStackOfLog(StackOfLog S);

/*-------------- List Of String --------------*/

typedef struct elmListOfString * address_of_los;

struct elmListOfString{
    string info;
    address_of_los next;
};

struct ListOfString{
    address_of_los first;
    int length;
};

ListOfString createListOfString();
address_of_los createElmListOfString(string info);
void insertListOfString(ListOfString &L,address_of_los p);
void deleteListOfString(ListOfString &L);
string getInfo(ListOfString L,int idx);



#endif // ENTITY_H_INCLUDED
