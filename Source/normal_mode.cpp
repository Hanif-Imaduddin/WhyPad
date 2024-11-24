#include "../Header/normal_mode.h"

void swipeRight(FILE::File F,CURSOR::Cursor &c,int n){
    // I.S: Masukan berupa sebuah file, kursor, dan integer n
    // F.S: Cursor digeser ke kanan sebanya n kali
    int i;
    i = 0;
    while (i < n && c.ptr->next != NIL){
        c.ptr = c.ptr->next;
        c.col_idx++;
        i++;
    }
}

void swipeLeft(FILE::File F,CURSOR::Cursor &c,int n){
    // I.S: Masukan berupa sebuah file, kursor, dan integer n
    // F.S: Cursor digeser ke kiri sebanya n kali
    int i;
    i = 0;
    while (i < n && c.ptr->prev != NIL){
        c.ptr = c.ptr->prev;
        c.col_idx++;
        i++;
    }
}

void slideUp(FILE::File F,CURSOR::Cursor &c,int n){
    // I.S: Masukan berupa sebuah file, kursor, dan integer n.
    // F.S: Cursor digeser ke atas sebanya n kali.
    int i;
    bool stop;
    FILE::Address p;
    p = F->first;
    for (i = 0;i < c.row_idx;i++){
        p = p->next;
    }

    i = 1;
    stop = false;
    while (p->prev != NIL && !stop && i < n){
        stop = p->prev->info.length < c.col_idx;
        if (!stop){
            c.row_idx--;
            p = p->prev;
        }
        i++;
    }

    c.ptr = p->info.first;
    for (int i = 0;i < c.col_idx;i++){
        c.ptr = c.ptr->next;
    }
}

void slideDown(FILE::File F,CURSOR::Cursor &c,int n){
    // I.S: Masukan berupa sebuah file, kursor, dan integer n
    // F.S: Cursor digeser ke bawah sebanya n kali
    int i;
    bool stop;
    FILE::Address p;
    p = F->first;
    for (i = 0;i < c.row_idx;i++){
        p = p->next;
    }

    i = 1;
    stop = false;
    while (p->next != NIL && !stop && i < n){
        stop = p->next->info.length < c.col_idx;
        if (!stop){
            c.row_idx++;
            p = p->next;
        }
        i++;
    }

    c.ptr = p->info.first;
    for (int i = 0;i < c.col_idx;i++){
        c.ptr = c.ptr->next;
    }
}

void rowStart(FILE::File F,CURSOR::Cursor &c){
    // F.S: Kursor menunjuk elemen pertama row yang ditunjuk.
    if (c.ptr != NIL){
        while (c.ptr->prev != NIL){
            c.ptr = c.ptr->prev;
            c.col_idx--;
        }
    }
}

void rowEnd(FILE::File F,CURSOR::Cursor &c){
    // F.S: Kursor menunjuk elemen terakrhir row yang ditunjuk.
    if (c.ptr != NIL){
        while (c.ptr->next != NIL){
            c.ptr = c.ptr->next;
            c.col_idx++;
        }
    }
}

void fileStart(FILE::File F,CURSOR::Cursor &c){
    // F.S: Kursor menunjuk elemen pertama file.
    if (F->first->first != NIL){// Jika di dalam file tidak ada elemen sama sekali, kursor tidak perlu diubah.
        c.col_idx = 0;
        c.row_idx = 0;
        c.ptr = F.first->first;
    }
}

void fileEnd(FILE::File F,CURSOR::Cursor &c){
    // F.S: Kurosr menunjuk elemen terakhir file.
    if (F->last->last != NIL){// Jika di dalam file tidak ada elemen sama sekali, kursor tidak perlu diubah.
        c.col_idx = F->last->length-1;
        c.row_idx = F->length-1;
        c.ptr = F.last->last;
    }
}

//Normal mode: navigasi (Mindahin kursor),copy, delete, edit, paste, duplikat baris.

void copyChar(FILE::File &F, SOA::Stack &Clipboard,int row_idx,int start_idx, int end_idx){
    // I.S: Masukan berupa File F, index row, index awal, index akhir
    // F.S: Elemen row dari index start sampai index akhir akan diletakan ke dalam stack clipboard. Panjang row kurang dari index akhir maka tidak ada yang disalin dan menampilkan pesan error

    FILE::Address p;
    ROW::Address q;
    ROW::Address temp1;
    ROW::Address temp2;
    int i;

    if (row_idx >= F.length){
        cout<<"Error: Row Index out of range"<<endl;
    }else{
        p = F.first;
        for (i = 0;i < row_idx;i++){
            p = p->next;
        }
        if (end_idx >= p->info.length){
            cout<<"Error: Index out of range"<<endl;
        }else{
            q = p->info.first;
            for (i = 0;i < start_idx;i++){
                q = q->next;
            }
            // Membuat salinan
            temp1 = ROW::createElm(q->info);
            temp2 = temp1;
            for (i = 0;i < end_idx-start_idx;i++){
                temp2->next = ROW::createElm(p->next->info);
                p = p->next;
                temp2 = temp2->next;
            }
            SOA::push(Clipboard,temp1);
        }
    }
}

void pasteChar(FILE::File &F,SOA::Stack &Clipboard, CURSOR::Cursor &c);
// I.S: Masukan berupa File F, clipboard,dan cursor c.
// F.S: Elemen paling atas pada clipboard dimasukan ke sebelah kanan elemen yang ditunjuk cursor, kemudian kursor menunjuk elemen terakhir dari elemen yang baru dimasukan.

void deleteElement(FILE::File &F,CURSOR::Cursor &c){
    // I.S: Masukan berupa File F, cursor c.
    // F.S: Elemen yang ditunjuk kursor dihapus, kemudian kursor menunjuk elemen di sebelah kiri elemen yang dihapus.
    //Jika elemen yang dihapus merupakan elemen pertama di row, maka kursor menunjuk NIL
}

void deleteRow(FILE::File &F, CURSOR::Cursor &c);
// I.S: Masukan berupa File F, cursor c.
// F.S: Baris yang ditunjuk kursor dihapus kemudian kursor menunjuk baris dibawahnya. Jika dibawahnya tidak ada baris, maka kursor menunjuk baris di atasnya.

void duplicateRow(FILE::File &F,ROW::Row R, CURSOR::Cursor &c);
// I.S: Masukan berupa file F dan row R.
// F.S: Row R disalin kemudian diletakan salinan dari row tersebut diletakan dibawahnya dan cursor menunjuk elemen terakhir salinan.
