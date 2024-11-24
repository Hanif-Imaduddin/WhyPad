#include "../Header/entity.h"

namespace ROW{
    Address createElm(char c){
        Address p;
        p = new elm;
        p->info = c;
        p->next = NIL;
        p->prev = NIL;
        return p;
    }
    Row create(){
        Row R;
        R.first = NIL;
        R.last = NIL;
        R.length = 0;
        return R;
    }
    void print(Row R,CURSOR::Cursor c){
        Address p;
        p = R.first;
        while (p != NIL){
            cout<<p->info;
            if (p == c){
                cout<<'|';
            }
            p = p->next;
        }
        cout<<endl;
    }
}

namespace CURSOR{
    Cursor create(){
        Cursor C;
        C.ptr = NIL;
        C.col_idx = -1;
        C.row_idx = -1;
        return C;
    }
}

namespace FILE{
    Address createElm(){
        Address p;
        p = new elm;
        p->info = ROW::create();
        p->next = NIL;
        p->prev = NIL;
        return p;
    }
    File create(string name){
        File F;
        F.first = NIL;
        F.last = NIL;
        F.length = 0;
        F.name = name;
        return F;
    }
    void print(File F,CURSOR::Cursor c){
        Address p;
        p = F.first;
        while (p != NIL){
            ROW::print(p->info,c));
        }
    }
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
    Address createElm(string name){
        Address p;
        p = new elm;
        p->info = FILE::create(name);
        p->next = NIL;
        return p;
    }
    Folder create(string name){
        Folder F;
        F.first = NIL;
        F.length = 0;
        F.name = name;
        return F;
    }
    void print(Folder F){
        int i;
        Address p;
        p = F.first;
        i = 1;
        while (p != NIL){
            cout<<i<<". "<<p->info.name<<endl;
            p = p->
        }
    }
}
namespace SOA{ //SOA = Stack Of Element Address
    Stack create(){
        Stack S;
        S.top = 0;
        return S;
    }

    bool isFull(Stack S){
        return S.top == 10;
    }
    bool isEmpty(Stack S){
        return S.top == 0;
    }
    void push(Stack &S,infotype p){
        if (!isFull(S)){
            S.info[S.top] = p;
            S.top++;
        }
    }
    void pop(Stack &S,infotype &p){
        if (!isEmpty(S)){
            S.top--;
            p = S.info[S.top];
        }else{
            p = NIL;
        }
    }
    infotype peek(Stack S){
        return S.info[S.top-1];
    }
}

namespace LOG{
    Log create(bool isInsertion, ROW::Address first){
        Log l;
        l.isInsertion = isInsertion;
        l.ptr = first;
    }
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
    Stack create(){
        Stack S;
        S.top = NIL;
        return S;
    }
    bool isEmpty(Stack S){
        return S.top == NIL;
    }
    void push(Stack &S, Address p){ // Insert first
        p->next = S.top;
        S.top = p;
    }
    void pop(Stack &S, Address &p){
        p = S.top;
        if (!isEmpty(S)){
            S.top = S.top->next;
            p->next = NIL;
        }
    }
    Address peek(Stack S){
        return S.top;
    }
}
