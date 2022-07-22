#include <iostream>
#include <cstdlib>

using namespace std;

/*
    Doubly linked list node structure 
*/

struct Node 
{
    int data;   // data stored in the node
    Node *next; // pointer to next node
    Node *prev; // pointer to previous node 
};

struct Node* head = NULL;   // head of the list

struct Node* CreateNewNode(int x)
{
    Node *newNode = new Node; // Create a new node
    newNode->data = x;        // Assign data to the new node
    newNode->next = head;     // Link the new node to the head
    newNode->prev = NULL;     // Initialize the previous pointer
    return newNode;
}


void InsertAtHead(int x)
{
    Node *newNode = CreateNewNode(x);
    if (head == NULL)
    {
        head = newNode; // Make the new node as head
        return;
    }
    head->prev = newNode;   // Link the new node to the head
    newNode->next = head;   // Link the new node to the head
    head = newNode;         // Make the new node as head
}


void ReversePrint()
{
    Node* temp = head;
    if(temp == NULL)
    {
        return; // Empty list, so exit
    }

    while (temp->next != NULL) // Go to the last node of the list
    {
        temp = temp->next; // traverse through the list
    }

    cout << "Reverse List: ";
    while (temp != NULL)
    {
        cout << temp->data << " "; // print the data
        temp = temp->prev; // move to the previous node
    }
    cout << endl;
}


void Print()
{
    Node *temp = head;
    cout << "Forward List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    head = NULL; // Empty list

    InsertAtHead(1);
        Print();
        ReversePrint();

    InsertAtHead(3);
        Print();
        ReversePrint();

    InsertAtHead(5);
        Print();
        ReversePrint();
}