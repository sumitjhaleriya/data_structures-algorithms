#include <iostream>
using namespace std;

class ListNode
{ // implimenting using linked list
public:
    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    ListNode *front;
    ListNode *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {
        ListNode *n = new ListNode(x); // creating a node
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n; // adding new node
        back = n;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        ListNode *todelete = front; // deleting from front
        front = front->next;

        delete todelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "NO Element in queue" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
            return true;
        return false;
    }
};
int main()
{

    return 0;
}
