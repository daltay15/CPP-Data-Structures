/*
    Checks user input for balanced parentheses using a stack.
    Returns true if parentheses are balanced, false otherwise.
    Popular interview question.
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
    void push(char x)
    {
        if (isFull()) // if the stack is full
        {
            cout << "ERROR: Stack Overflow" << endl;
            return;
        }
        A[++top] = x; // push the elemen to the stack
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

    bool isParenthesesBalanced(char c[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (c[i] == '(' || c[i] == '{' || c[i] == '[')      
            {
                push(c[i]);
            }
            else if (c[i] == ')'|| c[i] == '}' || c[i] == ']' ) 
            {
                if (isEmpty())
                {
                    cout << "Ubalanced Parentheses" << endl;    
                    return false;
                }
                else if (Top() == '(' && c[i] == ')')   
                {
                    pop();  
                }   
                else if (Top() == '{' && c[i] == '}')
                {
                    pop();
                }
                else if (Top() == '[' && c[i] == ']')
                {
                    pop();
                }
                else
                {
                    cout << "Unbalanced parentheses" << endl;
                    return false;
                }
            }
        }
        if (isEmpty())  
        {
            cout << "Balanced Parentheses" << endl;     
            return true;
        }
        else
        {
            cout << "Unbalanced Parentheses" << endl;
            return false;
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
    cout << c << endl;
    s.isParenthesesBalanced(c, strlen(c));
} 