#include<iostream>
using namespace std;
//Creating a node class 
 class node{                  
     public:      //declared public as it needs to be accessed by all
     int data;
     node* next;
 };
 //Creation of list class
 //List class contains implementation of linked list functionalities
 class List{
     private:
     node* head;    //private so that only constructor or member 
     public:        //function can access
     List(){        //Constructor for assigning head as NULL
         head=NULL;
     }
 };
 int main(){
     node* n1=new node;
     n1->data=10;
     n1->next=NULL;
     cout<<n1->data<<" "<<n1->next;
     return 0;
 }