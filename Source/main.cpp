#include <iostream>
#include <fstream>
#include <string>

#include "../Header/entity.h"
#include "../Header/standard.h"
#include "../Header/normal_mode.h"
#include "../Header/dummy_file.h"
#include "../Header/insert_mode.h"
#include "../Header/menu.h"
#include "../Header/command_line_mode.h"
#include "../Header/visual_mode.h"

using namespace std;

/*
Ini contoh input user di normal mode
r 5 (geser kursor ke kanan 5 kali)
l 5 (Geser kursor ke kiri 5 kali)
u 5 (Geser kursor ke atas 5 kali)
p 5 (Geser/Dorong kursor ke bawah 5 kali)
d 5 (Hapus elemen di sebelah kiri kursor (termasuk yang di tunjuk) 5 kali)

D (delete row yang ditunjuk kursor)
s (pindah kursor ke awal baris)
S (pindah kursor ke awal file)
e (pindah kursor ke akhir baris)
E (pindah kursor ke akhir file)
t (paste/tempel)

c 5 6 7 (salin elemen di baris ke 5 dari elemen ke 6 sampai elemen ke 7)
*/

void normal_mode_menu(address_of_folder F){
    string input,error_message;
    StackOfLog Undo_Stack;
    Clipboard CB;
    ListOfString input_list;
    string Input_P[4]; //input part
    int Input_P_int[4];

    int n;
    Cursor cursor;

    CB = createClipboard();
    Undo_Stack = createStackOfLog();
    cursor = createCursor(F);

    system("cls");
    printFile(F,cursor);

    cout<<endl<<"(Normal Mode): ";
    getline(cin,input);
    input_list = splitString(input,' ');

    while (getInfo(input_list,0) != "{exit}"){
        if (input_list.length == 1){
            Input_P[0] = getInfo(input_list,0);
            if (Input_P[0] == "D"){// Delete row
                deleteRow(F,Undo_Stack,cursor);
            }else if (Input_P[0] == "s"){// Pindah kursor ke awal baris
                rowStart(cursor);
            }else if (Input_P[0] == "S"){// Pindah kursor ke awal file
                fileStart(cursor);
            }else if (Input_P[0] == "e"){// Pindah kursor ke akhir baris
                rowEnd(cursor);
            }else if (Input_P[0] == "E"){// Pindah kursor ke akhir file
                fileEnd(cursor);
            }else if (Input_P[0] == "t"){// Paste/tempel
                pasteChar(F->info,CB,cursor);
            }else if (Input_P[0] == "im"){
                insert_master(F,cursor,Undo_Stack);
            }else if (Input_P[0] == "clm"){
                cl_master(F,Undo_Stack,cursor);
            }else if (Input_P[0] == "vm"){
                vm_master(F,cursor);
            }else{
                error_message = "Input Invalid!";
            }
        }else if (input_list.length == 2){
            Input_P[0] = getInfo(input_list,0);
            Input_P[1] = getInfo(input_list,1);
            try{
                error_message = "";
                Input_P_int[0] = stoi(Input_P[1]);
            }
            catch(const invalid_argument& e){
                Input_P_int[0] = -1;
            }
            if (Input_P_int[0] > 0){
                if (Input_P[0] == "r"){
                    swipeRight(cursor,Input_P_int[0]);
                }else if (Input_P[0] == "l"){
                    swipeLeft(cursor,Input_P_int[0]);
                }else if (Input_P[0] == "u"){
                    slideUp(cursor,Input_P_int[0]);
                }else if (Input_P[0] == "p"){
                    slideDown(cursor,Input_P_int[0]);
                }else if (Input_P[0] == "d"){
                    deleteElm(F,Undo_Stack,cursor,Input_P_int[0]);
                }else{
                    error_message = "Input Invalid!";
                }
            }else{
                error_message = "Input Invalid!";
            }
        }else if (input_list.length == 4){
            Input_P[0] = getInfo(input_list,0);
            Input_P[1] = getInfo(input_list,1);
            Input_P[2] = getInfo(input_list,2);
            Input_P[3] = getInfo(input_list,3);
            try{
                error_message = "";
                Input_P_int[0] = stoi(Input_P[1]);
                Input_P_int[1] = stoi(Input_P[2]);
                Input_P_int[2] = stoi(Input_P[3]);
            }
            catch(const invalid_argument& e){
                Input_P_int[0] = -1;
                Input_P_int[1] = -1;
                Input_P_int[2] = -1;
            }
            if (Input_P_int[0] >= 0 && Input_P_int[1] >= 0 && Input_P_int[2] >= 0){
                if (Input_P[0] == "c"){
                    copyChar(F->info,CB,Input_P_int[0],Input_P_int[1],Input_P_int[2]);
                }else{
                    error_message = "Input Invalid!";
                }
            }else{
                error_message = "Input Invalid!";
            }
        }else{
            error_message = "Input Invalid!";
        }
        deleteListOfString(input_list);

        system("cls");
        printFile(F,cursor);
        if (error_message != ""){
            cout<<endl<<error_message<<endl;
        }
        cout<<endl<<"(Normal Mode): ";
        getline(cin,input);
        input_list = splitString(input,' ');
    }
}

int main()
{
    int i;
    address_of_folder file_adr,p;

    string input,error_message;
    int input_int;
    Folder folder;

    folder = createFolder("Files");
    load_all_files(folder);

    menu_master(folder,"");
    cout<<"(Menu): ";
    getline(cin,input);
    try{
        error_message = "";
        input_int = stoi(input);
    }
    catch(const invalid_argument& e){
        if (input == "{quit}" || input == "{qs}"){
            input_int = -1;
        }else{
            input_int = -2;
            error_message = "Error: Input tidak valid!";
        }
    }
    while (input_int != -1){
        if (input_int != -2){
            if (input_int > folder.length+1 || input_int < 1){
                error_message = "Error: Input tidak valid";
            }else{
                i = 1;
                p = NIL;
                file_adr = folder.first;
                while (i < input_int && file_adr != NIL){
                    p = file_adr;
                    file_adr = file_adr->next;
                    i++;
                }
                if (file_adr == NIL){
                    cout<<"Masukan nama file: ";
                    getline(cin,input);
                    if (isValidFileName(input,folder)){
                        file_adr = createElmFolder(createFile(input));
                        if (p == NIL){
                            folder.first = file_adr;
                        }else{
                            p->next = file_adr;
                        }
                        folder.length++;
                    }else{
                        error_message = "Error: Nama file tidak valid!";
                    }
                }
                if (error_message == ""){
                    normal_mode_menu(file_adr);
                }
            }
        }
        menu_master(folder,error_message);
        cout<<"(Menu): ";
        getline(cin,input);
        try{
            error_message = "";
            input_int = stoi(input);
        }
        catch(const invalid_argument& e){
            if (input == "{quit}" || input == "{qs}"){
                input_int = -1;
            }else{
                input_int = -2;
                error_message = "Error: Input tidak valid!";
            }
        }
        error_message = "";
    }
    if (input == "{qs}"){
        quitSave(folder);
    }
    return 0;
}
