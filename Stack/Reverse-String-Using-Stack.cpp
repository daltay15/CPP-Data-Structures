/*
    Given a string, reverse it using stack.
*/


#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

#define MAX_SIZE 101

class Stack
{
private:
    int top = -1;
    char A[MAX_SIZE];

public:
    void push(int x)
    {
        if (isFull()) // if the stack is full
        {
            cout << "ERROR: Stack Overflow" << endl;
            return;
        }
        A[++top] = x; // push the element to the stack
    }

    void pop()
    {
        if (isEmpty()) // if the stack is empty
        {
            cout << "ERROR: The stack is empty" << endl;
            return;
        }
        A[top--] = '\0'; // pop the element from the stack
    }

    bool isFull()
    {
        if (top == MAX_SIZE - 1) // if the stack is full
        {
            return true;
        }
        return false;
    }

    char Top()
    {
        return A[top]; // return the data of the head
    }

    bool isEmpty()
    {
        if (top == -1) // if the stack is empty
        {
            return true;
        }
        return false;
    }

    void reverse(char c[], int n)   // reverse the string using stack
    {
        for (int i = 0; i < n; i++)     // push the string to the stack
        {
            push(c[i]); 
        }
        for (int i = 0; i < n; i++)     // pop the string from the stack
        {
            c[i] = Top();             // store the popped element in the string
            pop();                  // pop the element from the stack
        }
    }
};

int main()
{
    class Stack s;
    const int size = 50;
    char c[size];
    cout << "Enter a string: ";
    cin.getline(c, size);
    s.reverse(c, strlen(c));
    cout << "the reversed string is: " << c << endl;
}