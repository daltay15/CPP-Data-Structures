#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;   // Data stored in the node
    Node *next; // Pointer to next node
};

Node* Insert(Node* head ,int x)
{
    Node *temp = new Node;  // Create a new node 
    temp->data = x;     // Assign data to the new node
    temp->next = NULL;  // Link the new node to the head
    if (head != NULL)
    {
        temp->next = head;
    }
    head = temp;        // Make the new node as head
    return head;
}

void Print(Node* p)  // local variable
{
    if(p == NULL) return;
    cout << p->data << " ";     // Print the data
    Print(p->next);      // Print the next node    
}

void PrintReverse(Node* p)  // local variable
{
    if(p == NULL) return;
    PrintReverse(p->next);      // Print the next node    
    cout << p->data << " ";     // Print the data
}


int main()
{
    Node* head = NULL;         // Local variable
    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);
    
    cout << "Recursive Print: ";
    Print(head);
    cout << endl;
    cout << "Recursive Print Reverse: ";
    PrintReverse(head);
}

