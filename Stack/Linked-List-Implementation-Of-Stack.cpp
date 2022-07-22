#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;          // data stored in the node
    Node *link = NULL; // pointer to next node
};

Node *top = NULL; // global variable to store the head of the list

class StackLinkedList
{
public:
    void Push(int x)
    {
        Node *temp = new Node; // create a new node
        temp->data = x;        // assign data to the new node
        temp->link = top;      // link the new node to the head
        top = temp;            // make the new node as head
    }

    void Pop()
    {
        Node *temp = top; // store the head in a temporary variable
        if (isEmpty())  // if the stack is empty
        {
            cout << "ERROR: No elements to pop" << endl;
            return;
        }
        else
        {
            temp = top;      // store the head in a temporary variable
            cout << "Popped: " << temp->data << endl;
            top = top->link; // move the head to the next node
            free(temp);      // free the memory allocated to the old head
        }
    }

    void Top()
    {
        if (isEmpty()) // if the stack is empty
        {
            cout << "ERROR: No elements to pop" << endl;
            return;
        }
        cout << "Top: " << top->data; // print the data of the head
        cout << endl;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }

    void Print()
    {
        Node *curr = top;    // Pointer to the head
        cout << "Stack: ";
        while (curr != NULL) // traverse through the list
        {
            cout << curr->data << " "; // print the data
            curr = curr->link;         // move to the next node
        }
        cout << endl;
        return;
    }
};

int main()
{
    class StackLinkedList sll;
    sll.Push(1);
    sll.Push(2);
    sll.Push(3);
    sll.Print();
    sll.Top();
    sll.Pop();
    sll.Print();
    sll.Pop();
    sll.Top();
}
