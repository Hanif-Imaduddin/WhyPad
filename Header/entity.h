#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <iostream>
#define NIL NULL

using namespace std;


namespace ROW{
    typedef char infotype;
    typedef struct elm * Address;
    struct elm{
        infotype info;
        Address next,prev;
    };
    struct Row{
        Address first,last;
        int length;
    };
    Address createElm(char c);
    Row create();
    void print(Row R,CURSOR::Cursor c);
}

namespace CURSOR{
    struct Cursor{
        ROW::Address ptr;
        int row_idx,col_idx;
    };
    Cursor create();
}

namespace FILE{
    typedef ROW::Row infotype;
    typedef struct elm * Address;
    struct elm{
        infotype info;
        Address next,prev;
    };
    struct File{
        Address first,last;
        string name;
        int length;
    };
    Address createElm();
    File create(string name);
    void print(File F);
}

namespace FOLDER{
    typedef FILE::File infotype;
    typedef struct elm * Address;
    struct elm{
        infotype info;
        Address next;
    };
    struct Folder{
        Address first;
        string name;
        int length;
    };
    Address createElm(string name);
    Folder create(string name);
    void print(Folder F);
}

namespace SOA{ //SOA = Stack Of Element Address
    typedef ROW::elm * infotype;
    struct Stack{
        infotype info[10];
        int top;
    };
    Stack create();

    bool isFull(Stack S);
    bool isEmpty(Stack S);
    void push(Stack &S,infotype p);
    void pop(Stack &S,infotype &p);
    infotype peek(Stack S);
}

namespace LOG{
    struct Log{
        bool isInsertion;
        ROW::Address ptr;
    };
    Log create();
}

namespace SOL{ // SOL = Stack Of Log
    typedef LOG::Log infotype;
    typedef struct ElmStack * Address;

    struct ElmStack{
        infotype info;
        Address next;
    };
    struct Stack{
        Address top;
    };
    Stack create();
    bool isEmpty(Stack S);
    void push(Stack &S, Address p);
    void pop(Stack &S, Address &p);
    Address peek(Stack S);
}

#endif // ENTITY_H_INCLUDED
