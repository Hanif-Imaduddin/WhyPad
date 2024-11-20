#include "entity.h"

namespace COL{
    Col * create(char c){
        Col *C;
        C = new Col;
        C->info = c;
        C->next = NIL;
        C->prev = NIL;
        C->top = NIL;
        C->bot = NIL;

        return C;
    }
}

namespace ROW{
    Row * create(){
        Row * R;
        R = new Row;
        R->next = NIL;
        R->prev = NIL;
        R->first = NIL;
        R->length = 0;
        return R;
    }
    void print(Row R){
        COL::Col *p;
        p = R.first;
        while (p != NIL){
            cout<<p->info;
            p = p->next;
        }
        cout<<endl;
    }
}

namespace FILE{
    File create(string name){
        File F;
        F.first = NIL;
        F.name = name;
        F.length = 0;
    }
    void print(File F){
        ROW::Row *p;
        p = F.first;
        while (p != NIL){
            ROW::print(p);
        }
    }
}

namespace FOLDER{
    Folder create(){
        Folder F;
        F.first = NIL;
        F.length = 0;
    }
    void print(Folder F){
        int i;
        FILE::File *p;
        p = F.first;
        i = 1;
        while (p != NIL){
            cout<<i<<". "<<p->name<<endl;
            p = p->
        }
    }
}
