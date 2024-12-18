#ifndef COMMAND_LINE_MODE_H_INCLUDED
#define COMMAND_LINE_MODE_H_INCLUDED
#include "entity.h"
#include "standard.h"

#include <iostream>

using namespace std;

void cl_master(address_of_folder F,StackOfLog &Undo_Stack,Cursor C);
void undo_master(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
void redo_master(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);

void undo_delete_elm(address_of_sol p,StackOfLog &Redo_Stack);
void redo_delete_elm(address_of_sol p,StackOfLog &Undo_Stack);

void undo_insert_elm(address_of_sol p,StackOfLog &Redo_Stack);
void redo_insert_elm(address_of_sol p,StackOfLog &Undo_Stack);

void undo_delete_row(address_of_sol p,StackOfLog &Redo_Stack);
void redo_delete_row(address_of_sol p,StackOfLog &Undo_Stack);

void undo_insert_row(address_of_sol p,StackOfLog &Redo_Stack);
void redo_insert_row(address_of_sol p,StackOfLog &Undo_Stack);

void replace_elm(address_of_folder F,address_of_file row_ptr,StackOfLog &Undo_Stack,address_of_row start_source,address_of_row end_source,address_of_row start_target,address_of_row end_target);
void find_and_replace(address_of_folder F,ListOfString target_list,StackOfLog &Undo_Stack);



#endif // COMMAND_LINE_MODE_H_INCLUDED
