/* Program contains the following:
1. Creation of node for a linked list
2. Insertion at head in a list
3. Traversal of a linked list
4. Insertion at end(tail) of a linked list   */


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
void traverse(node* h){     //Linked list traversal
    node* curr=h;            //taking a temporary node curr so that head is not lost
    while(curr!=NULL){           //as curr is a pointer it shouldn't be null
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
} 
void insert_end(int d){    //Insert at end function
    node* temp=new node;    //Temporary node creation
    temp->data=d;
    temp->next=NULL;        // As this node will be last node, so next can be pointed to null
    if(head==NULL){         // check for an empty list
        head=temp;
    }
    else{
        node* curr=head;    // temporary pointer for traversal to end
        while(curr->next!=NULL){  // if next pointer points to null it will stop
            curr=curr->next;
        }
        curr->next=temp;  // curr will be at the last node after the end of while loop
    }
}
//main function
 int main(){  
     Insert_head(5);
     Insert_head(10);
     Insert_head(15);
     cout<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<endl;
     traverse(head);
     insert_end(10);
     insert_end(15);
     insert_end(25);
     traverse(head);

     return 0;
 }