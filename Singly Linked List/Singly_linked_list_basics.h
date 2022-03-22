/* Program contains the following:
1. Creation of node for a linked list
2. Insertion at head in a list                                      Time complexity- O(1)
3. Traversal of a linked list                                       Time complexity- O(n)
4. Insertion at end(tail) of a linked list                          Time complexity- O(n)
5. Insertion at a given position in a linked list                   Time complexity- Best[O(1)]-insertion at head
                                                                                     Worst[O(n)]-insertion at end 
6. Deletion at a given position(head included)                      Time complexity - Best[O(1)] -deletion at head
                                                                                     Worst/Average[O(n)]
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
 node* head=NULL;  //declaring head global so that it can be accessed from anywhere
 //2. Insertion at head
 void insert_head(int d){
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
//3. Traversal of linked list
void traverse(node* h){     //Linked list traversal
    node* curr=h;            //taking a temporary node curr so that head is not lost
    while(curr!=NULL){           //as curr is a pointer it shouldn't be null
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
//4. Insertion at tail/end 
void insert_end(int d){    //Insert at end function
    node* temp=new node;    //Temporary node creation
    temp->data=d;
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
//5. Insertion at a given position
void insert_Pos(int pos,int d){
    node* temp=new node;   //creation of a new node
    temp->data=d;
    if(pos<=1)           // Condition if user wants to insert at head
    insert_head(d);
    else{
        node* pred= head;   //A temporary pointer for traversal as we can't lose head
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
void delete_pos(int pos){
    if(head==NULL)             //condition for an empty list
    cout<<"Nothing to delete"<<endl;
    else if(pos==1){           //condition for deletion at head
        node* temp=head;
        head=head->next;
        temp->next=NULL;       //we point next of deleted node to null as it was pointing to one of the nodes earlier
        delete temp;           //free the allocated memory
    }
    else{                     //condition for deletion at any position
        node* curr=head;      //we need two pointers for deletion, a current and a previous pointer
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