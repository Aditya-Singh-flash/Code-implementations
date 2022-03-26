#include<iostream>
using namespace std;
#include"Singly_linked_list_basics.h"

void reverse(){
    node *prev=NULL,*temp=NULL;
    node* curr=head;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
}