#include<iostream>
using namespace std;

//1. Creating node for doubly linked list
class node{
    public:
    int data;            
    node* prev;                //pointer for previous node 
    node* next;                //pointer for next node
    node(){                    //constructor for initializing both pointers as null
        this->prev=NULL;
        this->next=NULL;
    }
    ~node(){                   //destructor for deletion of node
        if(this->prev!=NULL){   //(initializing the pointers to null again and free the memory)
        delete prev;
        this->prev=NULL;
        }
        if(this->next!=NULL){
        delete next;
        this->next=NULL;
        }
    }
};
node* head=NULL;
int main(){
    cout<<"Hello";
    node* n1=new node;
    n1->data=100;
    cout<<"\n"<<n1->data<<" "<<n1->prev<<" "<<n1->next<<" "<<head;
    return 0;
}