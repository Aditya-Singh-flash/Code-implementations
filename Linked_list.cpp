#include<iostream>
using namespace std;
//Creating a node class 
 class node{                  
     public:      //declared public as it needs to be accessed by all
     int data;
     node* next;
 };
 node* head=NULL;  //declaring head global so that it can be accessed from anywhere
 void Insert_head(int d){
     node* temp=new node;    //creation of a temporary node
         temp->data=d;       //storing data in temporary node
         if(head==NULL){     //check if list is blank
             head=temp;            //f list is blank the temp node should be made haed
             head->next=NULL;      
         }
         else{
             temp->next=head;      //insertion of node at head
             head=temp;
         }
     }
 int main(){
     Insert_head(5);
     Insert_head(10);
     Insert_head(15);
     cout<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<" "<<head->next->next->next;
     return 0;
 }