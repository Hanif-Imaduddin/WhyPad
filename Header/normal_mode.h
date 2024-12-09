#ifndef NORMAL_MODE_H_INCLUDED
#define NORMAL_MODE_H_INCLUDED
#include "entity.h"
#include "standard.h"
#include <iostream>

using namespace std;

void swipeRight(Cursor &C,int n);
void swipeLeft(Cursor &C,int n);
void slideUp(Cursor &C,int n);
void slideDown(Cursor &C,int n);

void rowStart(Cursor &C);
void rowEnd(Cursor &C);

void fileStart(Cursor &C);
void fileEnd(Cursor &C);

void copyChar(File F,Clipboard &CB,int row_idx,int start_idx,int end_idx);
void pasteChar(File F,Clipboard &CB, Cursor &C);

void deleteElm(address_of_folder F,StackOfLog &Undo_Stack,Cursor &C,int n);
void deleteRow(address_of_folder F,StackOfLog &Undo_Stack,Cursor &C);


#endif // NORMAL_MODE_H_INCLUDED
