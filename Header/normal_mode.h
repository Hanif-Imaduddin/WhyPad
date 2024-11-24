#ifndef NORMAL_MODE_H_INCLUDED
#define NORMAL_MODE_H_INCLUDED
#include "entity.h"

void swipeRight(FILE::File F,CURSOR::Cursor &c,int n);
// I.S: Masukan berupa sebuah file, kursor, dan integer n
// F.S: Cursor digeser ke kanan sebanya n kali

void swipeLeft(FILE::File F,CURSOR::Cursor &c,int n);
// I.S: Masukan berupa sebuah file, kursor, dan integer n
// F.S: Cursor digeser ke kiri sebanya n kali

void slideUp(FILE::File F,CURSOR::Cursor &c,int n);
// I.S: Masukan berupa sebuah file, kursor, dan integer n
// F.S: Cursor digeser ke atas sebanya n kali

void slideDown(FILE::File F,CURSOR::Cursor &c,int n);
// I.S: Masukan berupa sebuah file, kursor, dan integer n
// F.S: Cursor digeser ke bawah sebanya n kali

void rowStart(FILE::File F,CURSOR::Cursor &c);
// F.S: Kursor menunjuk elemen pertama row yang ditunjuk.

void rowEnd(FILE::File F,CURSOR::Cursor &c);
// F.S: Kursor menunjuk elemen terakrhir row yang ditunjuk.

void fileStart(FILE::File F,CURSOR::Cursor &c);
// F.S: Kursor menunjuk elemen pertama file.

void fileEnd(FILE::File F,CURSOR::Cursor &c);
// F.S: Kurosr menunjuk elemen terakhir file.

//Normal mode: navigasi (Mindahin kursor),copy, delete, edit, paste, duplikat baris.

void copyChar(FILE::File &F, SOA::Stack &Clipboard,int row_idx,int start_idx, int end_idx);
// I.S: Masukan berupa File F, index row, index awal, index akhir
// F.S: Elemen row dari index start sampai index akhir akan diletakan ke dalam stack clipboard. Panjang row kurang dari index akhir maka tidak ada yang disalin dan menampilkan pesan error

void pasteChar(FILE::File &F,SOA::Stack &Clipboard, CURSOR::Cursor &c);
// I.S: Masukan berupa File F, clipboard,dan cursor c.
// F.S: Elemen paling atas pada clipboard dimasukan ke sebelah kanan elemen yang ditunjuk cursor, kemudian kursor menunjuk elemen terakhir dari elemen yang baru dimasukan.

void deleteElement(FILE::File &F,CURSOR::Cursor &c);
// I.S: Masukan berupa File F, cursor c.
// F.S: Elemen yang ditunjuk kursor dihapus, kemudian kursor menunjuk elemen di sebelah kiri elemen yang dihapus. Jika elemen yang dihapus merupakan elemen pertama di row, maka kursor menunjuk NIL

void deleteRow(FILE::File &F, CURSOR::Cursor &c);
// I.S: Masukan berupa File F, cursor c.
// F.S: Baris yang ditunjuk kursor dihapus kemudian kursor menunjuk baris dibawahnya. Jika dibawahnya tidak ada baris, maka kursor menunjuk baris di atasnya.

void duplicateRow(FILE::File &F,ROW::Row R, CURSOR::Cursor &c);
// I.S: Masukan berupa file F dan row R.
// F.S: Row R disalin kemudian diletakan salinan dari row tersebut diletakan dibawahnya dan cursor menunjuk elemen terakhir salinan.




#endif // NORMAL_MODE_H_INCLUDED
