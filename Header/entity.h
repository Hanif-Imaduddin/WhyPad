#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <iostream>
#include <cmath>
#define NIL NULL

using namespace std;

struct elmRow{
    char info;
    elmRow *next,*prev;
};
struct Row{
    elmRow *first,*last;
    int length;
};

struct Cursor{
    elmRow *cell_ptr;
    elmFile *row_ptr;
    elmFolder *file_ptr;
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
    string info; // Berisi info elemen yang dihapus jika delete/insert elemen
    elmFolder *file_address; // Berisi elemen folder jika delete/insert file
    elmFile *row_address; // Berisi elemen file jika delete/insert row
    int row_idx,col_idx; // Row id menyesuaikan instruction code
};
struct elmStackOfLog{
    Log info;
    elmStackOfLog *next;
};
struct StackOfLog{
    elmStackOfLog *top;
};
Log createLog(int instruction_code,string info, elmFolder *file_address,elmFile *row_address,int row_idx,int col_idx);
elmStackOfLog* createElmStackOfLog(Log L);
StackOfLog createStackOfLog();

#endif // ENTITY_H_INCLUDED
