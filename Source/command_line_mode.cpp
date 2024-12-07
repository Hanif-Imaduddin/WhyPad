#include "../Header/command_line_mode.h"
void cl_master(address_of_folder F,StackOfLog &Undo_Stack){
    StackOfLog Redo_Stack;
    address_of_sol p;
    string input;
    Redo_Stack = createStackOfLog();
    system("cls");
    printFile(F);
    cout<<"(Command Line Mode): ";
    getline(cin,input);
    while (input != "{exit}"){
        if (input == "{undo}"){
            undo_master(Undo_Stack,Redo_Stack);
        }else if (input == "{redo}"){
            redo_master(Undo_Stack,Redo_Stack);
        }
        system("cls");
        printFile(F);
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
    if (!isEmptyStackOfLog(Undo_Stack)){
        popStackOfLog(Undo_Stack,p);
        if (p->info.instruction_code == 0){
            undo_delete_elm(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 1){
            undo_insert_elm(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 2){
            undo_delete_row(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 3){
            undo_insert_row(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 4){
            undo_delete_file(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 5){
            undo_create_file(Undo_Stack,Redo_Stack);
        }
    }
}
void redo_master(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack){
    if (!isEmptyStackOfLog(Redo_Stack)){
        popStackOfLog(Undo_Stack,p);
        if (p->info.instruction_code == 0){
            redo_delete_elm(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 1){
            redo_insert_elm(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 2){
            redo_delete_row(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 3){
            redo_insert_row(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 4){
            redo_delete_file(Undo_Stack,Redo_Stack);
        }else if (p->info.instruction_code == 5){
            redo_create_file(Undo_Stack,Redo_Stack);
        }
    }
}

void undo_delete_elm(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
void redo_delete_elm(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);

void undo_insert_elm(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
void redo_insert_elm(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);

void undo_delete_row(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
void redo_delete_row(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);

void undo_insert_row(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
void redo_insert_row(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);

void undo_create_file(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
void redo_create_file(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);

void undo_delete_file(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
void redo_delete_file(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
