#include "../Header/entity.h"

elmRow* createElmRow(char info){
    //create new ElmRow
    elmRow *p;
    p = new elmRow;
    p->info = info;
    p->next = NIL;
    p->prev = NIL;
    return p;
}
Row createRow(){
    //create new row
    Row R;
    R.first = NIL;
    R.last = NIL;
    R.length = 0;
    return R;
}

elmFile* createElmFile(Row R){
    //create new elmFila
    elmFile *p;
    p = new elmFile;
    p->info = R;
    p->next = NIL;
    p->prev = NIL;
    return p;
}

Cursor createCursor(){
    //create cursor
    Cursor C;
    C.cell_ptr = NIL;
    C.row_ptr = NIL;
    C.file_ptr = NIL;
    return C;
}

File createFile(string name){
    //create new file
    File F;
    F.first = NIL;
    F.last = NIL;
    F.length = 0;
    F.name = name;

    return F;
}

elmFolder* createElmFolder(File F){
    //create new elmFolder
    elmFolder *p;
    p = new elmFolder;
    p->info = F;
    p->next = NIL;
    return p;
}
Folder createFolder(string folder_name){
    //Create new folder
    Folder F;
    F.first = NIL;
    F.length = 0;
    F.name = folder_name;

    return F;
}

/*-------------- Clipboard --------------*/

bool isFullClipboard(Clipboard C){
    //mengecek apakah clipboard sudah penuh.
    //mengembalikan true jika penuh
    return C.height == 10;
}
bool isEmptyClipboard(Clipboard C){
    //mengecek apakah clipboard masih kosong.
    //mengembalikan true jika penuh
    return C.height == 0;
}
void pushClipboard(Clipboard &C,string p){
    //prosedur untuk menambahkan clipboard
    C.info[C.top] = p;
    C.top = (C.top+1)%5;
    if (!isFullClipboard(C)){
        C.height++;
    }
}
void popClipboard(Clipboard &C,string &p){
    //untuk melakukan pop pada clipboard
    if (!isEmptyClipboard(C)){
        C.top = (C.top-1)-10*floor(double(C.top-1)/double(10));
        p = C.info[C.top];
        C.height--;
    }
}

string peekClipboard(Clipboard C){
    //untuk melihat nilai paling atas
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

bool isEmptyStackOfLog(StackOfLog S){
    return S.top == NIL;
}
void pushStackOfLog(StackOfLog &S, address_of_sol p){
    p->next = S.top;
    S.top = p;
}
void popStackOfLog(StackOfLog &S, address_of_sol &p){
    if (isEmptyStackOfLog(S)){
        p = NIL;
    }else{
        p = S.top;
        S.top = S.top->next;
        p->next = NIL;
    }
}
address_of_sol peekStackOfLog(StackOfLog S){
    return S.top;
}
