#include <iostream>
#include <cstdlib>

using namespace std;

struct Node 
{
    int data;   // data stored in the node
    Node* next; // pointer to next node
};

struct Node* head;  

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
    while (curr != NULL)
    {
        cout << curr->data << " "; // print the data
        curr = curr->next; // move to the next node
    }
    cout << endl;
}


int main()
{
    head = NULL; // empty list
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;  
        cout << "Element " << i + 1 << ": ";
        cin >> x;   
        Insert(x);  
        Print();    
    }
}