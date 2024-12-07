#ifndef COMMAND_LINE_MODE_H_INCLUDED
#define COMMAND_LINE_MODE_H_INCLUDED
#include "entity.h"
#include "standard.h"

#include <iostream>

using namespace std;

void cl_master(address_of_folder F,StackOfLog &Undo_Stack);
void undo_master(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);
void redo_master(StackOfLog &Undo_Stack,StackOfLog &Redo_Stack);

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



#endif // COMMAND_LINE_MODE_H_INCLUDED
