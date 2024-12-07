#include "../Header/standard.h"

void stringToAddress(string str,address_of_row &start_ptr,address_of_row &end_ptr){
    int i;
    elmRow *p,*q;
    start_ptr = createElmRow(str[0]);
    if (str.length() != 1){
        end_ptr = createElmRow(str[str.length()-1]);
        p = start_ptr;
        for (i = 1;i < str.length()-1;i++){
            q = createElmRow(str[i]);
            p->next = q;
            q->prev = p;
            p = p->next;
        }
        p->next = end_ptr;
        end_ptr->prev = p;
    }else{
        end_ptr = start_ptr;
    }
}

//Menampilkan seluruh isi file
void printFile(address_of_folder F,Cursor C){
    address_of_file p;
    address_of_row q;
    int i;

    p = F->info.first;
    i = 1;
    cout<<"File: "<<F->info.name<<endl;
    cout<<string(50,'=')<<endl;
    while (p != NIL){
        cout<<i<<". ";
        q = p->info.first;
        while (q != NIL){
            cout<<q->info;
            if (q == C.cell_ptr){
                cout<<"|";
            }
            q = q->next;
        }
        cout<<endl;
        p = p->next;
        i++;
    }
}

void hold(){
    string input;
    getline(cin,input);
}

//Menampilkan judul aplikasi
void printHeader(){
    system("cls");
    cout << string(50, '=') << endl;
}
