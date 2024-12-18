#include "../Header/insert_mode.h"

void insert_master(address_of_folder F,Cursor &C,StackOfLog &Undo_Stack){
    string input;
    address_of_row start_adr,end_adr;
    address_of_file R;
    system("cls");
    printFile(F,C);
    cout<<endl<<"(Insert Mode): ";
    getline(cin,input);
    while (input != "{exit}"){
        if (input == "{row}") {
            if (C.row_ptr->next == NIL) {
                R = createElmFile(createRow());
                C.row_ptr->next = R;
                R->prev = C.row_ptr;
                R->next = NIL;
            } else {
                R = createElmFile(createRow());
                R->next = C.row_ptr->next;
                C.row_ptr->next->prev = R;
                C.row_ptr->next = R;
                R->prev = C.row_ptr;
            }
            pushStackOfLog(Undo_Stack,createElmStackOfLog(createLog(3,C.file_ptr,R,NIL,NIL)));
            C.row_ptr = R;
            C.cell_ptr = R->info.first;
        }else{
            stringToAddress(input,start_adr,end_adr);
            if (C.cell_ptr == NIL){ // cell_ptr nill belum tentu row nya kosong
                if (C.row_ptr->info.first == NIL){
                    C.row_ptr->info.first = start_adr;
                    C.row_ptr->info.last = end_adr;
                }else{
                    end_adr->next = C.row_ptr->info.first;
                    C.row_ptr->info.first->prev = end_adr;
                    C.row_ptr->info.first = start_adr;
                }
            }else if (C.cell_ptr->next == NIL){ // cell_ptr udah pasti elemen terakhir
                C.cell_ptr->next = start_adr;
                start_adr->prev = C.cell_ptr;
                C.row_ptr->info.last = end_adr;
            }else{ // Row nggak mungkin kosong
                end_adr->next = C.cell_ptr->next;
                C.cell_ptr->next->prev = end_adr;

                C.cell_ptr->next = start_adr;
                start_adr->prev = C.cell_ptr;
            }
            C.row_ptr->info.length += input.length();
            pushStackOfLog(Undo_Stack,createElmStackOfLog(createLog(1,C.file_ptr,C.row_ptr,start_adr,end_adr)));
            C.cell_ptr = end_adr;
        }
        system("cls");
        printFile(F,C);
        cout<<endl<<"(Insert Mode): ";
        getline(cin,input);
    }
}
