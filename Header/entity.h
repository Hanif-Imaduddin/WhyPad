#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <iostream>
#include <cmath>
#define NIL NULL


using namespace std;

typedef struct elmRow * address_of_row;
typedef struct elmFile * address_of_file;
typedef struct elmFolder * address_of_folder;

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
    elmFile *first;
    int length;
    string name;
};

elmRow* createElmRow(char info);
Row createRow();

elmFile* createElmFile(Row R);
File createFile(string name);

elmFolder* createElmFolder(File F);
Folder createFolder(string folder_name);

struct Clipboard{ // Stack
    string info[10];
    int height,top;
};
bool isFullClipboard(Clipboard C);
bool isEmptyClipboard(Clipboard C);
void pushClipboard(Clipboard &C,string p);
void popClipboard(Clipboard &C,string &p);
string peek(Clipboard C);


/* Instruction code: {Delete row elements: 0, Insert row elemen: 1, Delete Row: 3,
Insert Row: 4,delete file: 5, insert file: 6}*/
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

#endif // ENTITY_H_INCLUDED
