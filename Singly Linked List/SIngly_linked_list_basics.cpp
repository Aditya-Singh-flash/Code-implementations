//This file only contains the main function
//All the implementations are done in the header file attached

#include<iostream>
#include"Singly_linked_list_basics.h"   //we defined all the implementation in another file and included it as header file
using namespace std;

//main function
int main(){
    delete_pos(3);
    insert_head(5);
     insert_head(10);
     insert_head(15);
     traverse(head);
     insert_end(10);
     insert_end(15);
     insert_end(25);
     insert_Pos(4,65);
     traverse(head);
     delete_pos(7);
     traverse(head);
     delete_pos(3);
     traverse(head);
     delete_pos(1);
     traverse(head);
     traverse(head);
     insert_head(67);
     delete_pos(8);
     traverse(head);
    return 0;
}