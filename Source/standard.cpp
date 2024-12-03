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
