/*
    Reverse a singly linked list.
    Popular interview question.
*/


#include <iostream>
#include <cstdlib>

using namespace std;

struct Node 
{
    int data;   // data stored in the node
    Node *next; // pointer to next node
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

Node* Reverse(Node* head)      
{
    Node* current = head;   // Initialize current
    Node* prev = NULL;      // Initialize previous node
    Node* next = NULL;      // Initialize next node

    while (current != NULL)
    {
        next = current->next;   // Store next node
        current->next = prev;   // Reverse the current node's pointer
        prev = current;         // Move prev pointer one step forward
        current = next;         // Move current pointer one step forward
    }
    head = prev;                // Update head pointer
    return head;                // Return the new head pointer
} 

void Print(Node* head)
{
    cout << "The list is: ";
    while (head != NULL) // traverse through the list
    {
        cout << head->data << " "; // print the data
        head = head->next; // move to the next node
    }
    cout << endl;   
}


int main()
{
    Node* head = NULL; // Empty list
    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 3);     
    head = Insert(head, 4);
    head = Insert(head, 5);

    Print(head);
    head = Reverse(head);   // Reverse the list
    Print(head);            
}
