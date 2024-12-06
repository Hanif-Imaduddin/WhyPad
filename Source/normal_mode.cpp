#include "../Header/normal_mode.h"

void swipeRight(Cursor &C,int n){
    //untuk memindahkan kursor ke kanan
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
    //untuk memindahkan kursor ke kiri
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
    //untuk memindahkan kursor ke elemen paling awal atas
    int i;
    i = 0;
    if (C.row_ptr != NIL){
        while (i < n && C.row_ptr->prev != NIL){
            C.row_ptr = C.row_ptr->prev;
            i++;
        }
    }
    C.cell_ptr = C.row_ptr->info.first;
}
void slideDown(Cursor &C,int n){
    //untuk memindahkan kursor ke elemen paling awal bawah
    int i;
    i = 0;
    if (C.row_ptr != NIL){
        while (i < n && C.row_ptr->next != NIL){
            C.row_ptr = C.row_ptr->next;
            i++;
        }
    }
    C.cell_ptr = C.row_ptr->info.first;
}

void rowStart(Cursor &C) {
    //memindahkan kursor ke baris paling awal
    C.cell_ptr = C.row_ptr->info.first;
}
void rowEnd(Cursor &C){
    //memindakhkan kursor ke baris paling akhir
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
    elmRow *start_ptr,*end_ptr;
    string str;
    if (!isEmptyClipboard(CB)){
        popClipboard(CB,str);
        stringToAddress(str,start_ptr,end_ptr);
        if (C.cell_ptr != NIL){
            end_ptr->next = C.cell_ptr->next;
            if (C.cell_ptr->next != NIL){
                C.cell_ptr->next->prev = end_ptr;
            }
            C.cell_ptr->next = start_ptr;
            start_ptr->prev = C.cell_ptr;
            C.cell_ptr = start_ptr;
        }else{
            if (C.row_ptr->info.first == NIL){
                C.row_ptr->info.first = start_ptr;
            }else{
                end_ptr->next = C.row_ptr->info.first;
                C.row_ptr->info.first->prev = end_ptr;
                C.row_ptr->info.first = start_ptr;
            }
        }
    }
}
