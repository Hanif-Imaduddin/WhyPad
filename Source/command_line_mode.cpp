#include "../Header/command_line_mode.h"
void cl_master(address_of_folder F,StackOfLog &Undo_Stack,Cursor C){
    StackOfLog Redo_Stack;
    string error_message;
    address_of_sol p;
    string input,input_p0;
    ListOfString input_list,target_list;

    Redo_Stack = createStackOfLog();
    system("cls");
    printFile(F,C);
    cout<<endl<<"(Command Line Mode): ";
    getline(cin,input);
    input_list = splitString(input,' ');
    input_p0 = getInfo(input_list,0);

    while (input_p0 != "{exit}"){
        target_list = extractInput(input);
        if (input_p0 == "undo"){
            undo_master(Undo_Stack,Redo_Stack);
        }else if (input_p0 == "redo"){
            redo_master(Undo_Stack,Redo_Stack);
        }else if (target_list.length == 2){
            find_and_replace(F,target_list,Undo_Stack);
        }else{
            error_message = "Input Invalid!";
        }
        system("cls");
        printFile(F,C);
        if (error_message != ""){
            cout<<endl<<error_message<<endl;
        }
        cout<<endl<<"(Command Line Mode): ";
        getline(cin,input);
        input_list = splitString(input,' ');
        input_p0 = getInfo(input_list,0);
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
    pushStackOfLog(Redo_Stack,p);
}
void redo_delete_elm(address_of_sol p,StackOfLog &Undo_Stack){
    address_of_row q,r;
    if (p->info.start_ptr->prev == NIL && p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.first = NIL;
        p->info.row_ptr->info.last = NIL;
    }else if (p->info.start_ptr->prev == NIL){
        p->info.row_ptr->info.first = p->info.end_ptr->next;
        q = p->info.end_ptr->next;
        q->prev = NIL;
    }else if (p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.last = p->info.start_ptr->prev;
        q = p->info.start_ptr->prev;
        q->next = NIL;
    }else{
        q = p->info.start_ptr->prev;
        r = p->info.end_ptr->next;

        q->next = r;
        r->prev = q;
    }
    pushStackOfLog(Undo_Stack,p);
}

void undo_insert_elm(address_of_sol p,StackOfLog &Redo_Stack){
    address_of_row q,r;
    if (p->info.start_ptr->prev == NIL && p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.first = NIL;
        p->info.row_ptr->info.last = NIL;
    }else if (p->info.start_ptr->prev == NIL){
        p->info.row_ptr->info.first = p->info.end_ptr->next;
        q = p->info.end_ptr->next;
        q->prev = NIL;
    }else if (p->info.end_ptr->next == NIL){
        p->info.row_ptr->info.last = p->info.start_ptr->prev;
        q = p->info.start_ptr->prev;
        q->next = NIL;
    }else{
        q = p->info.start_ptr->prev;
        r = p->info.end_ptr->next;

        q->next = r;
        r->prev = q;
    }
    pushStackOfLog(Redo_Stack,p);
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
    pushStackOfLog(Undo_Stack,p);
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
    pushStackOfLog(Redo_Stack,p);
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

        q->next = r;
        r->prev = q;
    }
    pushStackOfLog(Undo_Stack,p);
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

        q->next = p->info.row_ptr->next;
        r->prev = p->info.row_ptr->prev;
    }
    pushStackOfLog(Redo_Stack,p);
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

        q->next = p->info.row_ptr;
        r->prev = p->info.row_ptr;
    }
    pushStackOfLog(Undo_Stack,p);
}
void replace_elm(address_of_folder F,address_of_file row_ptr,StackOfLog &Undo_Stack,address_of_row start_source,address_of_row end_source,address_of_row start_target,address_of_row end_target){
    if (start_source->prev != NIL){
        start_source->prev->next = start_target;
        start_target->prev = start_source->prev;
    }else{
        row_ptr->info.first = start_target;
    }
    if (end_source->next != NIL){
        end_source->next->prev = end_target;
        end_target->next = end_source->next;
    }else{
        row_ptr->info.last = end_target;
    }
    pushStackOfLog(Undo_Stack,createElmStackOfLog(createLog(0,F,row_ptr,start_source,end_source)));
    pushStackOfLog(Undo_Stack,createElmStackOfLog(createLog(1,F,row_ptr,start_target,end_target)));
}
void find_and_replace(address_of_folder F,ListOfString target_list,StackOfLog &Undo_Stack){
    string target,replacement;
    address_of_row start_source,end_source,start_target,end_target,p;
    address_of_file row_temp;
    int i;
    target = getInfo(target_list,0);
    replacement = getInfo(target_list,1);
    row_temp = F->info.first;
    while (row_temp != NIL){
        p = row_temp->info.first;
        start_source = NIL;
        end_source = NIL;
        i = 0;
        while (p != NIL){
            if (target[i] == '\0'){
                if (end_source == NIL){
                    end_source = start_source;
                }
                stringToAddress(replacement,start_target,end_target);
                replace_elm(F,row_temp,Undo_Stack,start_source,end_source,start_target,end_target);
                start_source = NIL;
                end_source = NIL;
                i = 0;
            }
            if (target[i] == p->info){
                if (start_source == NIL){
                    start_source = p;
                }else{
                    end_source = p;
                }
                i++;
            }else{
                start_source = NIL;
                end_source = NIL;
                i = 0;
            }
            p = p->next;
        }
        if (target[i] == '\0'){
            if (end_source == NIL){
                end_source = start_source;
            }
            stringToAddress(replacement,start_target,end_target);
            replace_elm(F,row_temp,Undo_Stack,start_source,end_source,start_target,end_target);
            start_source = NIL;
            end_source = NIL;
        }
        row_temp = row_temp->next;
    }
}
