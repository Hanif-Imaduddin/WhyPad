#include "../Header/menu.h"
#include "../Header/standard.h"


void printFolder(Folder F){
    address_of_folder P;
    int i = 1;
    P = F.first;
    cout << "Folder " << F.name << endl;
    while (P != NIL){
        cout << "  " << i << ". " << P->info.name << endl;
        i++;
    }
}
void menu_master(Folder F){
    printHeader();
    printFolder(F);
    cout << "  " << F.length+1 << ". " << "{Buat file baru}" << endl;
}
