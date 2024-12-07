#include "../Header/command_line_mode.h"
void cl_master(address_of_folder F,StackOfLog &Undo_Stack,Cursor C){
    StackOfLog Redo_Stack;
    address_of_sol p;
    string input;
    Redo_Stack = createStackOfLog();
    system("cls");
    printFile(F,C);
    cout<<"(Command Line Mode): ";
    getline(cin,input);
    while (input != "{exit}"){
        if (input == "{undo}"){
            undo_master(Undo_Stack,Redo_Stack);
        }else if (input == "{redo}"){
            redo_master(Undo_Stack,Redo_Stack);
        }
        system("cls");
        printFile(F,C);
        cout<<"(Command Line Mode): ";
        getline(cin,input);
    }
    while (!isEmptyStackOfLog(Redo_Stack)){
        popStackOfLog(Redo_Stack,p);
        delete p;
    }
}
/* Instruction code: {Delete row elements: 0, Insert row elemen: 1, Delete Row: 2,
Insert Row: 3,delete file: 4, insert file: 5}*/
void undo_master(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack){
    address_of_sol p;
    if (!isEmptyStackOfLog(Undo_Stack)){
        popStackOfLog(Undo_Stack,p);
        if (p->info.instruction_code == 0){
            undo_delete_elm(p,Redo_Stack);
        }else if (p->info.instruction_code == 1){
            undo_insert_elm(p,Redo_Stack);
        }else if (p->info.instruction_code == 2){
            undo_delete_row(p,Redo_Stack);
        }else if (p->info.instruction_code == 3){
            undo_insert_row(p,Redo_Stack);
        }
    }
}
void redo_master(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack){
    address_of_sol p;
    if (!isEmptyStackOfLog(Redo_Stack)){
        popStackOfLog(Redo_Stack,p);
        if (p->info.instruction_code == 0){
            redo_delete_elm(p,Undo_Stack);
        }else if (p->info.instruction_code == 1){
            redo_insert_elm(p,Undo_Stack);
        }else if (p->info.instruction_code == 2){
            redo_delete_row(p,Undo_Stack);
        }else if (p->info.instruction_code == 3){
            redo_insert_row(p,Undo_Stack);
        }
    }
}

void undo_delete_elm(address_of_sol p,StackOfLog &Redo_Stack){
    address_of_row q,r;
    if (p->info.start_ptr->prev == NIL && p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.first = p->info.start_ptr;
        p->info.row_ptr->info.last = p->info.end_ptr;
    }else if (p->info.start_ptr->prev == NIL){
        p->info.row_ptr->info.first = p->info.start_ptr;
        q = p->info.end_ptr->next;
        q->prev = p->info.end_ptr;
    }else if (p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.last = p->info.end_ptr;
        q = p->info.start_ptr->prev;
        q->next = p->info.start_ptr;
    }else{
        q = p->info.start_ptr->prev;
        r = p->info.end_ptr->next;

        q->next = p->info.start_ptr;
        r->prev = p->info.end_ptr;
    }
}
void redo_delete_elm(address_of_sol p,StackOfLog &Undo_Stack){
    address_of_row q,r;
    if (p->info.start_ptr->prev == NIL && p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.first = NIL;
        p->info.row_ptr->info.last = NIL;
    }else if (p->info.start_ptr->prev == NIL){
        p->info.row_ptr->info.first = NIL;
        q = p->info.end_ptr->next;
        q->prev = NIL;
    }else if (p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.last = NIL;
        q = p->info.start_ptr->prev;
        q->next = NIL;
    }else{
        q = p->info.start_ptr->prev;
        r = p->info.end_ptr->next;

        q->next = NIL;
        r->prev = NIL;
    }
}

void undo_insert_elm(address_of_sol p,StackOfLog &Redo_Stack){
    address_of_row q,r;
    if (p->info.start_ptr->prev == NIL && p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.first = NIL;
        p->info.row_ptr->info.last = NIL;
    }else if (p->info.start_ptr->prev == NIL){
        p->info.row_ptr->info.first = NIL;
        q = p->info.end_ptr->next;
        q->prev = NIL;
    }else if (p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.last = NIL;
        q = p->info.start_ptr->prev;
        q->next = NIL;
    }else{
        q = p->info.start_ptr->prev;
        r = p->info.end_ptr->next;

        q->next = NIL;
        r->prev = NIL;
    }
}
void redo_insert_elm(address_of_sol p,StackOfLog &Undo_Stack){
    address_of_row q,r;
    if (p->info.start_ptr->prev == NIL && p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.first = p->info.start_ptr;
        p->info.row_ptr->info.last = p->info.end_ptr;
    }else if (p->info.start_ptr->prev == NIL){
        p->info.row_ptr->info.first = p->info.start_ptr;
        q = p->info.end_ptr->next;
        q->prev = p->info.end_ptr;
    }else if (p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.last = p->info.end_ptr;
        q = p->info.start_ptr->prev;
        q->next = p->info.start_ptr;
    }else{
        q = p->info.start_ptr->prev;
        r = p->info.end_ptr->next;

        q->next = p->info.start_ptr;
        r->prev = p->info.end_ptr;
    }
}

void undo_delete_row(address_of_sol p,StackOfLog &Redo_Stack){
    address_of_file q,r;
    if (p->info.row_ptr->prev == NIL && p->info.row_ptr->next == NIL){
        p->info.file_ptr->info.first = p->info.row_ptr;
        p->info.file_ptr->info.last = p->info.row_ptr;
    }else if (p->info.row_ptr->prev == NIL){
        p->info.file_ptr->info.first = p->info.row_ptr;
        q = p->info.row_ptr->next;
        q->prev = p->info.row_ptr;
    }else if (p->info.row_ptr->next == NIL){
        p->info.file_ptr->info.last = p->info.row_ptr;
        q = p->info.row_ptr->prev;
        q->next = p->info.row_ptr;
    }else{
        q = p->info.row_ptr->prev;
        r = p->info.row_ptr->next;

        q->next = p->info.row_ptr;
        r->prev = p->info.row_ptr;
    }
}
void redo_delete_row(address_of_sol p,StackOfLog &Undo_Stack){
    address_of_file q,r;
    if (p->info.row_ptr->prev == NIL && p->info.row_ptr->next == NIL){
        p->info.file_ptr->info.first = NIL;
        p->info.file_ptr->info.last = NIL;
    }else if (p->info.row_ptr->prev == NIL){
        p->info.file_ptr->info.first = NIL;
        q = p->info.row_ptr->next;
        q->prev = NIL;
    }else if (p->info.row_ptr->next == NIL){
        p->info.file_ptr->info.last = NIL;
        q = p->info.row_ptr->prev;
        q->next = NIL;
    }else{
        q = p->info.row_ptr->prev;
        r = p->info.row_ptr->next;

        q->next = NIL;
        r->prev = NIL;
    }
}

void undo_insert_row(address_of_sol p,StackOfLog &Redo_Stack){
    address_of_file q,r;
    if (p->info.row_ptr->prev == NIL && p->info.row_ptr->next == NIL){
        p->info.file_ptr->info.first = NIL;
        p->info.file_ptr->info.last = NIL;
    }else if (p->info.row_ptr->prev == NIL){
        p->info.file_ptr->info.first = NIL;
        q = p->info.row_ptr->next;
        q->prev = NIL;
    }else if (p->info.row_ptr->next == NIL){
        p->info.file_ptr->info.last = NIL;
        q = p->info.row_ptr->prev;
        q->next = NIL;
    }else{
        q = p->info.row_ptr->prev;
        r = p->info.row_ptr->next;

        q->next = NIL;
        r->prev = NIL;
    }
}
void redo_insert_row(address_of_sol p,StackOfLog &Undo_Stack){
    address_of_file q,r;
    if (p->info.row_ptr->prev == NIL && p->info.row_ptr->next == NIL){
        p->info.file_ptr->info.first = NIL;
        p->info.file_ptr->info.last = NIL;
    }else if (p->info.row_ptr->prev == NIL){
        p->info.file_ptr->info.first = NIL;
        q = p->info.row_ptr->next;
        q->prev = NIL;
    }else if (p->info.row_ptr->next == NIL){
        p->info.file_ptr->info.last = NIL;
        q = p->info.row_ptr->prev;
        q->next = NIL;
    }else{
        q = p->info.row_ptr->prev;
        r = p->info.row_ptr->next;

        q->next = NIL;
        r->prev = NIL;
    }
}
