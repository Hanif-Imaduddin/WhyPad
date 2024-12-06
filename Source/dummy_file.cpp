#include "../Header/dummy_file.h"

Row stringToRow(string str){
    Row R;
    address_of_row start_adr,end_adr;
    R = createRow();
    stringToAddress(str,start_adr,end_adr);
    R.first = start_adr;
    R.last = end_adr;
    R.length = str.length();
    return R;
}

File AoSToFile(string *str_arr,int n,string file_name){
    File F;
    address_of_file p,q;
    F = createFile(file_name);
    if (n > 0){
        F.first = createElmFile(stringToRow(str_arr[0]));
        if (n > 1){
            p = F.first;
            F.last = createElmFile(stringToRow(str_arr[n-1]));
            for (int i = 1;i < n-1;i++){
                q = createElmFile(stringToRow(str_arr[i]));
                p->next = q;
                q->prev = p;
                p = p->next;
            }
            p->next = F.last;
            F.last->prev = p;
        }
    }
    return F;
}

File lorem_ipsum(){
    File F;
    string str_arr[5];
    address_of_file p,q;

    str_arr[0] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras feugiat bibendum erat eget sollicitudin. Maecenas lobortis nulla quis nisl molestie, commodo pellentesque quam";
    str_arr[1] = "iaculis. Curabitur blandit felis metus, vel auctor est porttitor quis. Sed leo tortor, cursus non magna eu, finibus vestibulum orci. Vivamus molestie justo sit amet erat";
    str_arr[2] = "vulputate egestas. Nunc pharetra sapien diam. Quisque felis arcu, vulputate quis pretium sed, pharetra nec sapien. Sed rhoncus sem turpis. Nunc viverra nisi eget velit";
    str_arr[3] = "imperdiet fringilla. Quisque ultricies est eget nisl tincidunt, vel hendrerit quam tincidunt. Nullam ullamcorper erat in velit porttitor, nec blandit augue tristique.";
    str_arr[4] = "pulvinar venenatis nisi. Morbi lectus nisi, rhoncus ut volutpat at, suscipit vel tortor. Donec nisi purus, auctor ut lectus a, pulvinar fermentum dolor.";
    F = AoSToFile(str_arr,5,"Lorem Ipsum");
    return F;
}
