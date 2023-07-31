#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int value)
  {
    data = value;
    next = NULL;
  }
};

class Stack
{
private:
  Node *top;

public:
  Stack()
  {
    top = NULL;
  }

  bool isEmpty()
  {
    return top == NULL;
  }

  void push(int value)
  {
    Node *newNode = new Node(value);
    if (isEmpty())
    {
      top = newNode;
    }
    else
    {
      newNode->next = top;
      top = newNode;
    }
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack is empty." << endl;
      return -1;
    }
    else
    {
      int value = top->data;
      Node *temp = top;
      top = top->next;
      delete temp;
      return value;
    }
  }

  int peek()
  {
    if (isEmpty())
    {
      cout << "Stack is empty." << endl;
      return -1;
    }
    else
    {
      return top->data;
    }
  }
};

int main()
{
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  cout << "Top element: " << stack.peek() << endl;
  while (!stack.isEmpty())
  {
    cout << stack.pop() << " ";
  }
  cout << endl;
  return 0;
}

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// class node_LL
// {
// public:
//   int data;
//   node_LL *next;
//   node_LL(int value)
//   {
//     data = value;
//     next = NULL;
//   }
// };

// class stack_LL
// {
// private:
//   node_LL *head;
//   node_LL *tos;

// public:
//   // Constructor to initialize head and tos
//   stack_LL()
//   {
//     head = NULL;
//     tos = NULL;
//   }

//   int top()
//   {
//     return tos->data;
//   }
//   void push(int v)
//   {
//     node_LL *temp = new node_LL;
//     temp->data = v;
//     temp->next = head;
//     head = temp;
//     tos = temp;
//   }
//   int pop()
//   {
//     int r;
//     if (head == NULL)
//       return -1; // Stack is empty
//     if (head == tos)
//     {
//       r = tos->data;
//       delete tos;
//       head = NULL;
//       tos = NULL;
//       return r;
//     }
//     node_LL *t = head;
//     while (t->next != tos)
//     {
//       t = t->next;
//     }
//     r = tos->data;
//     delete tos;
//     tos = t;
//     return r;
//   }
//   bool Empty()
//   {
//     if (head == NULL)
//       return 1;
//     else
//       return 0;
//   }
//   int size_s()
//   {
//     node_LL *t = head;
//     int s = 0;
//     while (t != NULL)
//     {
//       t = t->next, s++;
//     }
//     return s;
//   }
// };

// int main()
// {
//   stack_LL *st = new stack_LL();
//   st->push(2);
//   cout << "tos : " << st->top() << endl;
//   st->push(4);
//   cout << "tos : " << st->top() << endl;
//   st->push(6);
//   cout << "tos : " << st->top() << endl;
//   st->push(8);
//   cout << "tos : " << st->top() << endl;
//   st->push(10);
//   cout << "tos : " << st->top() << endl;
//   st->pop();
//   cout << "tos : " << st->top() << endl;
//   st->pop();
//   cout << "tos : " << st->top() << endl;
//   return 0;
// }

// // #include <iostream>
// // #include <bits/stdc++.h>
// // using namespace std;
// // class node_LL{
// //   public:
// //     int data;
// //     node_LL *next;
// // };
// // class stack_LL{
// //     private: 
// //       node_LL *head;
// //       node_LL *tos;

// //     public:
// //       stack_LL()
// //       {
// //         head = NULL;
// //         tos = NULL;
// //       }
// //       int top(){
// //         return tos->data;
// //       }
// //       void push(int v){
// //         if (head!=NULL)
// //         {
// //           tos = head;
// //           node_LL *temp = new node_LL;
// //           temp->data = v;
// //           temp->next = head;
// //           head = temp;
// //           tos = temp;
// //         }
// //       } 
// //       int pop(){
// //         int r;
// //         if (head == NULL)
// //           return -1; // Stack is empty
// //         if (head == tos)
// //         {
// //           r = tos->data;
// //           delete tos;
// //           head = NULL;
// //           tos = NULL;
// //           return r;
// //         }
// //         node_LL *t = head;
// //         while (t->next != tos)
// //         {
// //           t = t->next;
// //         }
// //         r = tos->data;
// //         delete tos;
// //         tos = t;
// //         return r;
// //       }
// //       bool Empty(){
// //         if (head == NULL)
// //           return 1;
// //         else
// //           return 0;
// //       }
// //       int size_s(){
// //         node_LL *t = head;
// //         int s=0;
// //         while (t!=NULL)
// //         {
// //             t = t->next,s++;
// //         }
// //         return s;
// //       }
// // };
// // int main()
// // {
// //       stack_LL *st = new stack_LL();
// //       st->push(2);
// //       st->push(4);
// //       st->push(6);
// //       st->push(8);
// //       st->push(10);
// //       int n = st->size_s();
// //       for (int i = 0; i < n; i++)
// //       {
// //         cout << " Val at tos : " << st->top() << endl;
// //         st->pop();
// //       }
// //       return 0;
// // }