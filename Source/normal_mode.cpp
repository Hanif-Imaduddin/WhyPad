#include "../Header/normal_mode.h"

void swipeRight(Cursor &C,int n){
    int i;
    i = 0;
    if (C.cell_ptr != NIL && C.row_ptr != NIL){
        while (i < n && C.cell_ptr->next != NIL){
            i++;
            C.cell_ptr = C.cell_ptr->next;
        }
    }
}
void swipeLeft(Cursor &C,int n){
    int i;
    i = 0;
    if (C.cell_ptr != NIL && C.row_ptr != NIL){
        while (i < n && C.cell_ptr->prev != NIL){
            i++;
            C.cell_ptr = C.cell_ptr->prev;
        }
    }
}
void slideUp(Cursor &C,int n){
    int i;
    i = 0;
    if (C.row_ptr != NIL){
        while (i < n && C.row_ptr->prev != NIL){
            C.row_ptr = C.row_ptr->prev;
            i++;
        }
    }
}
void slideDown(Cursor &C,int n){
    int i;
    i = 0;
    if (C.row_ptr != NIL){
        while (i < n && C.row_ptr->next != NIL){
            C.row_ptr = C.row_ptr->next;
            i++;
        }
    }
}

void rowStart(Cursor &C){
    C.cell_ptr = C.row_ptr->info.first;
}
void rowEnd(Cursor &C){
    C.cell_ptr = C.row_ptr->info.last;
}

void fileStart(Cursor &C){
    C.row_ptr = C.file_ptr->info.first;
}
void fileEnd(Cursor &C){
    C.row_ptr = C.file_ptr->info.last;
}

void copyChar(File F,Clipboard &CB,int row_idx,int start_idx,int end_idx){
    elmFile *p;
    elmRow *q;
    string strElm;
    int i,j;
    p = F.first;
    if (row_idx < F.length){
        i = 0;
        while (i < row_idx){
            p = p->next;
            i++;
        }
        if (end_idx < p->info.length){
           j = 0;
           q = p->info.first;
           while (j < start_idx){
                q = q->next;
                j++;
           }
            strElm = "";
            for (i = start_idx;i <= end_idx;i++){
                strElm += q->info;
                q = q->next;
            }
            pushClipboard(CB,strElm);
        }else{
            cout<<"Error: Column Index out of range!"<<endl;
        }
    }else{
        cout<<"Error: Row Index out of range!"<<endl;
    }
}

void pasteChar(File F,Clipboard &CB, Cursor &C){

}