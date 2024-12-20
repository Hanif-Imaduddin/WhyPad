#include "../Header/visual_mode.h"

void vm_master(address_of_folder F,Cursor C){
    string input,input_p0;
    string error_message;
    ListOfString input_list,target_list;

    error_message = "";

    system("cls");
    printFile(F,C);
    cout<<endl<<"(Visual Mode): ";
    getline(cin,input);
    input_list = splitString(input,' ');
    input_p0 = getInfo(input_list,0);

    while (input_p0 != "{exit}"){
        if (input_p0 == "find"){
            target_list = extractInput(input);
            if (target_list.length == 1){
                system("cls");
                findText(F,C,getInfo(target_list,0));
                cout<<endl<<"(Visual Mode): ";
                getline(cin,input);
                input_list = splitString(input,' ');
                input_p0 = getInfo(input_list,0);
            }else{
                error_message = "Invalid Input!";
                system("cls");
                printFile(F,C);
                cout<<endl<<"\33\[31m"<<error_message<<"\33[37m"<<endl;
                cout<<endl<<"(Visual Mode): ";
                getline(cin,input);
                input_list = splitString(input,' ');
                input_p0 = getInfo(input_list,0);
            }
        }
    }
}

void findText(address_of_folder F,Cursor C,string target){
    string temp;
    address_of_file row_temp;
    address_of_row p;
    int i;

    row_temp = F->info.first;
    temp = "";

    cout<<"File: "<<F->info.name<<endl;
    cout<<string(50,'=')<<endl;
    while (row_temp != NIL){
        if (C.row_ptr == row_temp && C.cell_ptr == NIL){
            cout<<"|";
        }
        p = row_temp->info.first;
        i = 0;
        while (p != NIL){
            if (target[i] == '\0'){
                cout<<"\33[94m"<<temp<<"\33[37m";
                temp = "";
                i = 0;
            }
            if (p->info == target[i]){
                temp += p->info;
                i++;
            }else{
                cout<<temp<<p->info;
                temp = "";
                i = 0;
            }
            p = p->next;
        }
        if (target[i] == '\0'){
            cout<<"\33[94m"<<temp<<"\33[37m";
            temp = "";
        }
        cout<<endl;
        row_temp = row_temp->next;
    }
}
