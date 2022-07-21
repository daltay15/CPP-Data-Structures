#include <iostream>
#include <cstdlib>

using namespace std;

struct Node 
{
    int data;   // data stored in the node
    Node* next; // pointer to next node
};

struct Node* head;  

void Insert(int data, int n)    
{
    Node* temp1 = new Node();   // Create a new node
    temp1->data = data;    // Assign data to the new node
    temp1->next = NULL;  // Link the new node to the head
    if (n == 1)         
    {
        temp1->next = head; // Make the new node as head
        head = temp1;    // Make the new node as head
        return;        // Return from the function
    }
    Node* temp2 = head;
    for(int i = 0; i < n-2; i++)    // Traverse to the nth node
    {
        temp2 = temp2->next;    // Move to the next node
    }
    temp1->next = temp2->next;  // Link the new node to the head
    temp2->next = temp1;    // Link the new node to the head     
}

void Print()
{
    cout << "The list is: ";
    Node *curr = head;     // make a pointer to the head
    while (curr != NULL) // traverse through the list
    {
        cout << curr->data << " "; // print the data
        curr = curr->next; // move to the next node
    }
    cout << endl;   
}


int main()
{
    head = NULL; // empty list
    Insert(2, 1);   // List: 2
    Insert(3, 2);   // List: 2 3
    Insert(4, 1);   // List: 4 2 3
    Insert(5, 2);   // List: 4 5 2 3
    Print();
}