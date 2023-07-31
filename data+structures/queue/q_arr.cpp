#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//implementation of queue using arr 
#define n 100
int Queue[n],front = -1,rear = -1;
void enqueue(int x){
 if (rear == n-1)
 {
     cout << " Overflow"<< endl;
 }
 else if (front == -1 && rear ==-1)
 {
     front = rear = 0;
     Queue[rear] = x;
 }
 else
 {
     rear++;
     Queue[rear] = x;
 }
}
void dequeue(){
 if (rear == front)
 {
     front = rear = -1;
 }
 else if (front == -1 && rear == -1)
 {
     cout << " Underflow" << endl;
 }
 else
 {
     front++;
 }
}
void display(){
    if(front==-1 && rear == -1){
     cout << " empty queue" << endl;
    }
    else
    {
        for(int j = front ; j < rear+1; j++)
        {
            cout <<" "<<j<<" th element of queue :" << Queue[j] << endl;         
        }
    }   
}
int peek(){
    if (front == -1 && rear == -1)
    {
        cout << " empty queue" << endl;
    }
    else
    {
        return Queue[front];
    }
}
int main()
{
      
    return 0;
}