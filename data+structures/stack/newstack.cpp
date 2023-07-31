#include <iostream>
using namespace std;

class Stack
{
private:
    int *stack;
    int top;
    int size;

public:
    Stack(int n)
    {
        size = n;
        stack = new int[size];
        top = -1;
    }

    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        stack[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int x = stack[top];
        top--;
        return x;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
};

int main()
{
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.peek() << endl; // Output: 3

    s.pop();
    cout << s.peek() << endl; // Output: 2

    cout << s.isEmpty() << endl; // Output: 0

    s.pop();
    s.pop();
    cout << s.isEmpty() << endl; // Output: 1

    cout << s.pop() << endl; // Output: Stack underflow -1

    return 0;
}
