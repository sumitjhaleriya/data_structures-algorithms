#include <iostream>
#include <set>
using namespace std;

class node{
 public:
    int data;
    node*next;

    node(int val)
    {
       data = val;
       next = NULL;
    }
};
void insertatTail(node* &head,int val)
{
    node*n = new node(val);
    node* temp=head;
    while(temp->next!=NULL)  //traversing in linked list
    {
        temp=temp->next;
    }
    temp->next=n;
                
    if(head==NULL){
        head=n;
        return;
    }
}
void insertatHead(node* &head,int val)
{
    node* n=new node(val);
    node* temp=head;
    n->next=head;
    head=n;
}
void delete_node(node* &head,int val)
{
    node* temp=head;
    while(temp->next->data!=val)
        temp=temp->next;

    node* nodetodelete= temp->next;
    temp->next=temp->next->next;

    delete nodetodelete;
}
bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key)
           return true;
        temp=temp->next;
    }return false;
}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
node* reverse(node* &head)
{
   node* prevptr=NULL;
   node* currptr=head;
   node* nextptr;
   while(currptr!=NULL)
   {
       nextptr = currptr->next;
       currptr->next=prevptr;   

       prevptr=currptr;
       currptr=nextptr;
   }
   return prevptr;
}
node* reverserec(node* &head)
{
    if(head==NULL || head->next==NULL)
       return head;

    node* newhead = reverserec(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}
node* reversek(node* head,int k)
{
    int count = 0;
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    
    while(currptr!=NULL && count<k)
    {
       nextptr=currptr->next;
       currptr->next=prevptr;
       prevptr=currptr;
       currptr=nextptr;
       count++;
    }
    if(nextptr!=NULL)
       head->next= reversek(nextptr,k);
    return prevptr;
}
void evenAfterOdd(node* &head)
{
  node* odd=head;
  node* even=head->next;
  node* evenstart=even;
  while(odd->next!=NULL && even->next!=NULL)
  {
   odd->next = even->next;
   odd = odd->next;
   even->next = odd->next;
   even = even->next;

  }
  odd->next = evenstart;
  if(odd->next!=NULL)
      even->next=NULL;
}
int length(node *head){
   int l =0;
   node* temp=head;
   while(temp!=NULL){
     l++;
     temp=temp->next;
   }
   return l;
}
node* kappend(node* &head,int k)
{
 node* newHead;
 node* newTail;
 node* tail=head;

 int l = length(head);
 k = k%l;
 int count = 1;
 while(tail->next!=NULL)
  {
     if(count==l-k){
          newTail=tail;
     }
     
     if(count==l-k+1){
          newHead=tail;
     }
    
    tail=tail->next;
    count++;
  }
 newTail->next=NULL;
 tail->next=head;
 
 return newHead;
}
void swap(int a,int b){
 int t;
 t = a;
 a = b;
 b = t;
}
node *Sort_Linked_list(node* head){
 node *i = head, *j;
 if (head == NULL)
    return NULL;
 while (i->next != NULL)
 {
    j = head->next;
    while (j != NULL)
    {
          if ((i->data) < (j->data))
              swap(i->data, j->data);
          j = j->next;
    }
    i = i->next;
 }
 return head;
}
int main()
{
  node* head=NULL;
  insertatTail(head,1);
  insertatTail(head,6);
  insertatTail(head,3);
  insertatTail(head, 2);
  insertatTail(head, 7);
  Sort_Linked_list(head);
  display(head);
  //insertatHead(head,4);
  //search(head,3);
  //delete_node(head,2);
  return 0;
}
