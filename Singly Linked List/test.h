/*
this is the same file as Singly_linked_list_basics.h but the implementation is a bit different. Instead of 
using a global head, the head ode is passed as an argument in the file. Also, the head node is passed as a reference
as we want the original linked list to be changed and not a copy to be formed.
*/
#include<iostream>
using namespace std;
//1. Creating a node class 
 class node{                  
     public:      //declared public as it needs to be accessed by all
     int data;
     node* next;
     node(){         //constructor definition 
         this->next=NULL;    //Every time a new node is created, its next pointer is automatically set to NULL
     }
     ~node(){            // Destructor definition to destroy the object and free the memory
         if(this->next!=NULL){  //if the next pointer is already null we don't need to free it
             delete next;
             this->next= NULL;
         }
     }
 };
 //2. Insertion at head
 void insert_head(int d,node* &h){
     node* temp=new node;    //creation of a temporary node
         temp->data=d;       //storing data in temporary node
         if(h==NULL){     //check if list is blank
             h=temp;            //f list is blank the temp node should be made haed
             h->next=NULL;      
         }
         else{
             temp->next=h;      //insertion of node at head
             h=temp;
         }
     }
//3. Traversal of linked list
void traverse(node* &h){     //Linked list traversal
    node* curr=h;            //taking a temporary node curr so that head is not lost
    while(curr!=NULL){           //as curr is a pointer it shouldn't be null
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
//4. Insertion at tail/end 
void insert_end(int d,node* &h){    //Insert at end function
    node* temp=new node;    //Temporary node creation
    temp->data=d;
    if(h==NULL){         // check for an empty list
        h=temp;
    }
    else{
        node* curr=h;    // temporary pointer for traversal to end
        while(curr->next!=NULL){  // if next pointer points to null it will stop
            curr=curr->next;
        }
        curr->next=temp;  // curr will be at the last node after the end of while loop
    }
}
//5. Insertion at a given position
void insert_Pos(int pos,int d,node* &h){
    node* temp=new node;   //creation of a new node
    temp->data=d;
    if(pos<=1)           // Condition if user wants to insert at head
    insert_head(d,h);
    else{
        node* pred= h;   //A temporary pointer for traversal as we can't lose head
        int i=1;            //i=1 because we count it from 1 and go till (pos-1)
        while(i<(pos-1) && pred!=NULL){
            pred=pred->next; 
            i++;
        }
        if(pred==NULL)
        cout<<"Invalid position as linked list is smaller than requested position";
        else{
            temp->next=pred->next;
            pred->next=temp;
        }
    }
}
//6. Deletion at a given position
void delete_pos(int pos,node* &h){
    if(h==NULL)             //condition for an empty list
    cout<<"Nothing to delete"<<endl;
    else if(pos==1){           //condition for deletion at head
        node* temp=h;
        h=h->next;
        temp->next=NULL;       //we point next of deleted node to null as it was pointing to one of the nodes earlier
        delete temp;           //free the allocated memory
    }
    else{                     //condition for deletion at any position
        node* curr=h;      //we need two pointers for deletion, a current and a previous pointer
        node* prev=NULL;      //curr points to the node to be deleted once loop gets completed
        int i=1;
        while(curr!=NULL && i<pos){
            prev=curr;        //current and previous both should be incremented through the list
            curr=curr->next;  //we assigned prev first so that curr doesn't get pointed to next node before assignment 
            i++;
        }
        if(curr==NULL)    //as curr points to the index we want to delete, if it points to null it doesn't exist
        cout<<"Invalid index"<<endl;
        else{
            prev->next=curr->next;
            curr->next =NULL;      //if next of deleted isn't assigned null it might give segmentation fault
            delete curr;
        }
    }
}
void reverse(node* &h){
    node *prev=NULL,*temp=NULL;
    node* curr=h;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    h=prev;
}