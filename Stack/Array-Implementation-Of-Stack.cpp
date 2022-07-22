/*
    Stack using an array.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 100


class Stack
{
private:
    int top = -1;
    int A[MAX_SIZE];

public:
    void push(int x)
    {
        if (top == MAX_SIZE - 1) // if the stack is full
        {
            cout << "ERROR: Stack Overflow" << endl;
            return;
        }
        A[++top] = x; // push the element to the stack
    }

    void pop()
    {
        if (top == -1) // if the stack is empty
        {
            cout << "ERROR: No elements to pop" << endl;
            return;
        }
        top--; // pop the element from the stack
    }

    int Top()
    {
        return A[top]; // return the data of the head
    }

    void print()
    {
        int i = 0;
        cout << "Stack:";
        for (i = 0; i <= top; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    class Stack s;
    s.push(1);
    s.print();
    s.push(2);
    s.print();
    s.push(3);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
}