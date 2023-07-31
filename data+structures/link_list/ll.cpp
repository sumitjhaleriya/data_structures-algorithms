#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    void append(int data)
    {
        if (head == nullptr)
        {
            head = new Node();
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new Node();
            current->next->data = data;
            current->next->next = nullptr;
        }
    }
    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
    void add_pos(int pos, int data)
    {
        Node *tp = head;
        Node *newnode = new Node();
        newnode->data = data;
        pos--;
        while (pos-- > 0)
        {
            tp = tp->next;
            pos--;
        }
        newnode->next = tp->next;
        tp->next = newnode;
    }
    int find_length(int data){
        Node *travptr = head;
        int l = 1;
        while (travptr->next != NULL)
        {
            travptr = travptr->next,l++;
        }
        return l;
    }
    void insert_at_middle(int data ,int pos){
        Node *tp = head,*p,*q;
        Node *newnode = new Node();
        newnode->data = data;
        int k = 1;
        p = head;
        if(pos==1){
            newnode->next = tp;
            head = newnode;
        }
        else{
            while ((p != NULL) && (k<pos))
            {
                k++;
                q=p;
                p = p->next;
            }
            q->next = newnode;
            newnode->next = p;
        }
    }
    void del_at_middle(int pos)
    {
        Node *tp = head, *p, *q;
        int k = 1;
        p = head;
        if (pos == 1)
        {
            head = head->next;
            p->next = NULL;
        }
        else
        {
            while ((p != NULL) && (k < pos))
            {
                k++;
                q = p;
                p = p->next;
            }
            q->next = p->next;
            p->next = NULL;
        }
    }
    bool CheckPalindrome()
    {
        Node *tp = head;
        if(head == NULL){
            return false;
        }
        else
        {
            while (tp)
            {
                
            }
               
        }
    }
    Node *RHead()
    {
        Node *tp = head;
        return tp;
    }
};
Node *Sort_Linked_list(Node *head)
{
    Node *i = head, *j;
    if (head == NULL)
        return NULL;
    while (i->next != NULL)
    {
        j = i->next;
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
    LinkedList list;
    list.append(1);
    list.append(4);
    list.append(3);
    list.append(2);
    //list.append(5);
    //list.append(6);
    list.print();
    cout << " length = " << list.find_length(1) << endl;
    //list.insert_at_middle(8,3);
    list.print();
    cout << " length = " << list.find_length(1) << endl;
    //list.del_at_middle(3);
    list.print();
    cout << " length = " << list.find_length(1) << endl;
    Sort_Linked_list(list.RHead());
    list.print();
    return 0;
}