/*
    Parses a postfix expression and evaluates it.
    The expression is given as a string, and the result is returned as an int.
    The expression may contain +, -, *, /, and parentheses.
    The expression is assumed to be valid.
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define MAX_SIZE 101

class Postfix
{
private:
    int top = -1;
    int A[MAX_SIZE];

public:
    void push(char c)
    {
        if (isFull()) // if the stack is full
        {
            cout << "ERROR: Stack Overflow" << endl;
            return;
        }
        A[++top] = c; // push the elemen to the stack
    }

    int pop()
    {
        if (isEmpty()) // if the stack is empty
        {
            cout << "ERROR: The stack is empty" << endl;
            return '\0';
        }
        return A[top--]; // pop the element from the stack
    }

    bool isFull()
    {
        if (top == MAX_SIZE - 1) // if the stack is full
        {
            return true;
        }
        return false;
    }

    int Top()
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

    int result(char c, int x, int y)
    {
        if (c == '+')
        {
            return y + x;
        }
        else if (c == '-')
        {
            return y - x;
        }
        else if (c == '*')
        {
            return y * x;
        }
        else if (c == '/')
        {
            return y / x;
        }
        else
        {
            return INT_MIN;
        }
    }

    int convertCharToInt(char c)
    {
        int val;
        val = c;
        return int(val - '0');
    }

    char evaluatePostfix(string c, int n)
    {
        for (int i = 0; i <= n - 1; i++)
        {
            if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
            {
                int x = pop();
                int y = pop();
                push(result(c[i], x, y));
            }
            else if(isdigit(c[i]) > 0)
            {
                push(convertCharToInt(c[i]));
            }
        }
        cout << "The answer is: " << pop() << endl;
        return '\0';
    }
};


int main()
{
    class Postfix post;
    const int size = 50;
    string c;
    cout << "Enter a postfix equation: ";
    cin >> c;
    int n = c.length();
    post.evaluatePostfix(c, n);
} 