/*
    Deleting the nth node from a linked list
*/


#include <iostream>
#include <cstdlib>

using namespace std;

struct Node 
{
    int data;   // data stored in the node
    Node* next; // pointer to next node
};

struct Node* head;   // head of the list          

void Insert(int x)
{
    Node *temp = new Node;  // Create a new node 
    temp->data = x;     // Assign data to the new node
    temp->next = head;  // Link the new node to the head
    head = temp;        // Make the new node as head
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

void Delete(int n)  // Delete a node from the list
{
    struct Node* temp1 = head;
    if (n == 1)         
    {
        head = temp1->next; // Make the new node as head
        delete temp1;    // Delete the node
        return;        // Return from the function
    }

    for(int i = 0; i < n-2; i++)    // Traverse to the nth node
    {
        temp1 = temp1->next;    // Move to the next node
    }
    // temp 1 points to (n-1)th node

    struct Node* temp2 = temp1->next; // temp2 points to (n)th node
    temp1->next = temp2->next; // Link the new node to the head
    free(temp2); // Delete temp2
}


int main()
{
    head = NULL; // empty list
    Insert(2);  // List: 2
    Insert(3);  // List: 3 2
    Insert(4);  // List: 4 3 2
    Insert(5);  // List: 5 4 3 2

    Print();    

    int n;
    cout << "Enter the position of the element to be deleted: ";
    cin >> n;

    Delete(n);  
    Print();
}