#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <iostream>
#define NIL NULL

using namespace std;

namespace COL{
    struct Col{
        char info;
        Col *next,*prev,*top,*bot;
    };
    Col * create(char c);
}

namespace ROW{
    struct Row{
        COL::Col *first;
        int length;
        Row *next,*prev;
    };
    Row * create();
    void print(Row R);
}

namespace FILE{
    struct File{
        ROW::Row *first;
        string name;
        int length;
        File *next;
    };
    File * create(string name);
    void print(File F);
}

namespace FOLDER{
    struct Folder{
        FILE::File *first;
        int length;
    };
    Folder create();
    void print(Folder F);
}


#endif // ENTITY_H_INCLUDED
