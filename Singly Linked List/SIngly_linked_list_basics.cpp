//This file only contains the main function
//All the implementations are done in the header file attached
//We have attached "reverse.h" only because the other file "Singly_linked_list_basics.h"
//has been include in reverse file and if we again attach it here it will fail in compilation
//saying class and functions have been defined twice because of double connectivity.


#include<iostream>
#include"reverse.h"    //we defined all the implementation in another file and included it as header file
using namespace std;

//main function
int main(){
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
     insert_head(67);
     delete_pos(8);
     traverse(head);
     reverse();
     traverse(head);
    return 0;
}

/*
Head node has been declared as global variable so that it can be accessed from anywhere and we do not 
need to pass it as an argument every time we call a function. In case I declare it as a local variable
or a private member within another cass, it will be required to be passed as an argument and also returned
back by the function once the operation is performed*/