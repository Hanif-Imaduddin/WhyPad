#include <iostream>
#include <string>
#include "../Header/entity.h"
#include "../Header/standard.h"
#include "../Header/normal_mode.h"
#include "../Header/dummy_file.h"
#include "../Header/insert_mode.h"
#include "../Header/menu.h"
#include "../Header/command_line_mode.h"

using namespace std;

void file_menu(address_of_folder F){
    string input,error_message;
    int n;
    Cursor cursor;

    system("cls");
    cursor = createCursor(F);
    printFile(F,cursor);

    cout<<endl<<"(Normal Mode): ";
    getline(cin,input);
    while (input != "{exit}"){
        if (input == "{insert}"){

        }else if (input == "{command}"){

        }else if (input == "{visual}"){

        }else if (input.length() > 0){
            try{
                n = stoi(input[1:])
            }
            catch(const invalid_argument& e){
                error_message = "";
                n = -1;
            }
            if (n == -1){
                error_message = "Error: Input tidak valid!";
            }else{
                /*
                    r: geser kursor ke kanan
                    l: geser kursor ke kiri
                    u: geser kursor ke atas
                    p: geser kursor ke bawah
                    d: delete elemen row yang dipilih
                    D: delete row yang ditunjuk kursor
                    s: Row start
                    S: File start
                    e: row end
                    E:  File end
                    c: copy
                    t: tempel/paste
                */
                if (input[0] == 'r'){
                    swipeRight(cursor,n);
                }else if (input[0] == 'l'){
                    swipeLeft(cursor,n);
                }else if (input[0] == 'u'){
                    slideUp(cursor,n);
                }else if (input[0] == 'p'){
                    slideDown(cursor,n);
                }else if (input[0] == 'd'){

                }else if (input[0] == 'D'){

                }else if (input[0] == 's'){
                    if (input.length > )
                }else if (input[0] == 'S'){

                }else if (input[0] == 'e'){

                }else if (input[0] == 'E'){

                }else if (input[0] == 'c'){

                }else if (input[0] == 't'){

                }else{
                    error_message = "Error: Input tidak valid!";
                }
            }
        }
    }
}

int main()
{
    int i;
    address_of_folder file_adr,p;

    string input,error_message;
    int input_int;
    Folder folder;
    folder = createFolder("Whypad");
    menu_master(folder,"");
    cout<<"(Menu): ";
    getline(cin,input);
    try{
        error_message = "";
        input_int = stoi(input);
    }
    catch(const invalid_argument& e){
        if (input == "{quit}"){
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
                i = 0;
                p = NIL;
                file_adr = folder.first;
                while (i < input_int && file_adr != NIL){
                    p = file_adr;
                    file_adr = file_adr->next;
                }
                if (file_adr == NIL){
                    cout<<"Masukan nama file: ";
                    getline(cin,input);
                    file_adr = createElmFolder(createFile(input));
                    if (p == NIL){
                        folder.first = file_adr;
                    }else{
                        p->next = file_adr;
                        file_adr = p;
                    }
                    folder.length++;
                    file_menu(file_adr);
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
            if (input == "{quit}"){
                input_int = -1;
            }else{
                input_int = -2;
                error_message = "Error: Input tidak valid!";
            }
        }
    }
    return 0;
}

/*
    Folder folder;
    File lorem;
    Cursor cursor;
    lorem = lorem_ipsum();
    folder = createFolder("Cek");
    folder.first = createElmFolder(lorem);
    menu_master(folder);
    cin >> input;
    while (input != -1 ){
        menu_master(folder);
        getline(cin,input);
        if ('1')
    }
*/

/*
Test Dummy File
    Folder folder;
    File lorem;
    Cursor cursor;
    lorem = lorem_ipsum();
    folder = createFolder("Nyoba aja");
    folder.first = createElmFolder(lorem);
    cursor.cell_ptr = lorem.first->info.first->next;
    cursor.file_ptr = folder.first;
    cursor.row_ptr = lorem.first;
    printFile(folder.first,cursor);
    return 0;
*/
/*
Test Insert
    Folder folder;
    File lorem;
    Cursor cursor;
    lorem = lorem_ipsum();
    folder = createFolder("Nyoba aja");
    folder.first = createElmFolder(lorem);
    cursor.cell_ptr = lorem.first->info.first->next;
    cursor.file_ptr = folder.first;
    cursor.row_ptr = lorem.first;
    printFile(folder.first,cursor);

    insert_master(folder.first,cursor);
    return 0;
*/
