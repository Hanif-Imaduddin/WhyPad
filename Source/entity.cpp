#include "../Header/entity.h"

elmRow* createElmRow(char info){
    elmRow *p;
    p = new elmRow;
    p->info = info;
    p->next = NIL;
    p->prev = NIL;
    return p;
}
Row createRow(){
    Row R;
    R.first = NIL;
    R.last = NIL;
    R.length = 0;
    return R;
}

elmFile* createElmFile(Row R){
    elmFile *p;
    p = new elmFile;
    p->info = R;
    p->next = NIL;
    p->prev = NIL;
    return p;
}

Cursor createCursor(){
    Cursor C;
    C.cell_ptr = NIL;
    C.row_ptr = NIL;
    C.file_ptr = NIL;
    return C;
}

File createFile(string name){
    File F;
    F.first = NIL;
    F.last = NIL;
    F.length = 0;
    F.name = name;
}

elmFolder* createElmFolder(File F){
    elmFolder *p;
    p = new elmFolder;
    p->info = F;
    p->next = NIL;
    return p;
}
Folder createFolder(string folder_name){
    Folder F;
    F.first = NIL;
    F.length = 0;
    F.name = folder_name;
}

/*-------------- Clipboard --------------*/

bool isFullClipboard(Clipboard C){
    return C.height == 10;
}
bool isEmptyClipboard(Clipboard C){
    return C.height == 0;
}
void pushClipboard(Clipboard &C,string p){
    C.info[C.top] = p;
    C.top = (C.top+1)%5;
    if (!isFullClipboard(C)){
        C.height++;
    }
}
void popClipboard(Clipboard &C,string &p){
    if (!isEmptyClipboard(C)){
        C.top = (C.top-1)-10*floor(double(C.top-1)/double(10));
        p = C.info[C.top];
        C.height--;
    }
}

string peek(Clipboard C){
    int tempTop;
    tempTop = (C.top-1)-10*floor(double(C.top-1)/double(10));
    return C.info[tempTop];
}


/*-------------- Stack Of Log --------------*/

Log createLog(int instruction_code,elmFolder* file_ptr,elmFile *row_ptr,elmRow *start_ptr,elmRow *end_ptr){
    Log L;
    L.instruction_code = instruction_code;
    L.file_ptr = file_ptr;
    L.row_ptr = row_ptr;
    L.start_ptr = start_ptr;
    L.end_ptr = end_ptr;

    return L;
}
elmStackOfLog* createElmStackOfLog(Log L){
    elmStackOfLog *p;
    p = new elmStackOfLog;
    p->info = L;
    p->next = NIL;

    return p;
}
StackOfLog createStackOfLog(){
    StackOfLog S;
    S.top = NIL;

    return S;
}
