#include "../Header/standard.h"

void stringToAddress(string str,address_of_row &start_ptr,address_of_row &end_ptr){
    int i;
    elmRow *p,*q;
    /*
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
    }*/
    if (str.length() > 0){
        start_ptr = createElmRow(str[0]);
        end_ptr = start_ptr;
        for (i = 1;i < str.length();i++){
            p = createElmRow(str[i]);
            end_ptr->next = p;
            p->prev = end_ptr;
            end_ptr = p;
        }
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
        if (p == C.row_ptr && C.cell_ptr == NIL){
            cout<<"|";
        }
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

File read_file(string file_name){
    ifstream file_reader("Files/"+file_name);
    string row_str;
    address_of_row start_adr,end_adr;
    File F;
    F = createFile(file_name);

    F.name = file_name;
    if (getline(file_reader,row_str)){
        stringToAddress(row_str,start_adr,end_adr);
        F.first->info.first = start_adr;
        F.first->info.last = end_adr;
        F.first->info.length = row_str.length();
        F.last = F.first;

        while( getline(file_reader,row_str)){
            cout<<row_str<<endl;
            stringToAddress(row_str,start_adr,end_adr);
            F.last->next = createElmFile(createRow());
            F.last->next->info.first = start_adr;
            F.last->next->info.last = end_adr;
            F.last->next->info.length = row_str.length();
            F.length++;
            F.last->next->prev = F.last;
            F.last = F.last->next;
        }
    }
    file_reader.close();
    return F;
}

void load_all_files(Folder &F){
    ifstream file_reader("Files/config.txt");
    string file_name;
    int count;
    address_of_folder p;

    p = NIL;
    count = 0;
    if (getline(file_reader,file_name)){
        F.first = createElmFolder(read_file(file_name));
        p = F.first;
        F.length++;
        while (getline(file_reader,file_name)){
            p->next = createElmFolder(read_file(file_name));
            F.length++;
            p = p->next;
        }
    }
    file_reader.close();
}

ListOfString splitString(string str, char delimiter){
    ListOfString L;
    int i;
    string temp;
    L = createListOfString();
    i = 0;
    temp = "";
    while (str[i] != '\0'){
        if (str[i] == delimiter){
            insertListOfString(L,createElmListOfString(temp));
            temp = "";
        }else{
            temp += str[i];
        }
        i++;
    }
    if (temp != ""){
        insertListOfString(L,createElmListOfString(temp));
    }
    return L;
}
ListOfString extractInput(string input){
    ListOfString L;
    bool append_mode;
    L = createListOfString();
    string temp;
    int i;
    i = 0;
    temp = "";
    append_mode = false;
    while (input[i] != '\0'){
        if (input[i] == '{'){
            append_mode = true;
        }else if (input[i] == '}'){
            insertListOfString(L,createElmListOfString(temp));
            temp = "";
            append_mode = false;
        }else if (append_mode == true){
            temp += input[i];
        }
        i++;
    }
    return L;
}
