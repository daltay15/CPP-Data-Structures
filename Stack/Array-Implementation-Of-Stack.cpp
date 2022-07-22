#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 100
int A[MAX_SIZE];
int top = -1;

class Stack
{
public:
    void Push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "ERROR: Stack Overflow" << endl;
            return;
        }
        A[++top] = x;
    }

    void Pop()
    {
        if (top == -1)
        {
            cout << "ERROR: No elements to pop" << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        return A[top];
    }

    void Print()
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
    s.Push(1);
    s.Print();
    s.Push(2);
    s.Print();
    s.Push(3);
    s.Print();
    s.Pop();
    s.Print();
    s.Pop();
    s.Print();
}