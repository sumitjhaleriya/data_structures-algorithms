#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(node* &head,int val)
{
    int c = val;
    node *newn = new node( c );
    newn->next;
    if(head!=NULL)
        head->prev=newn;
    
    head=newn;  
}
void insertAtTail(node* &head,int val)
{
  if(head==NULL){
       insertAtHead(head,val);
       return;
  }

  node* n=new node(val);
  node* temp=head;

  while(temp->next!=NULL)
      temp=temp->next;

  temp->next=n;
  n->prev=temp;             

}
void display(node* head)
{
   node* temp=head;
   while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
   }
   cout<<endl;
}
void deleteAtHead(node* &head)
{
   node* todel = head;
   head=head->next;
   head->prev=NULL;

   delete todel;
}
void delete_dll(node* &head,int pos){
  
  if(pos==1){
     deleteAtHead(head);
     return;
    }

  node* temp = head;
  int count =1;

  while(temp!=NULL &&count!=pos){
      temp=temp->next;
      count++;
   }
   temp->prev->next=temp->next;
   temp->next->prev=temp->prev;

   delete temp;
}
void reversedll(node *&head){
    
}
 int main()
{
   node *dllh = new node(0);
   display(dllh);
   insertAtHead(dllh, 2);
   display(dllh);
   insertAtHead(dllh, 4);
   display(dllh);
   insertAtHead(dllh, 6);
   display(dllh);
}
