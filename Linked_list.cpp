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