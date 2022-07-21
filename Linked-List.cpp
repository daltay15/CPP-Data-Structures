#include <iostream>
#include <cstdlib>

using namespace std;

/*
Linked list with Node* head as a global variable
*/

struct Node 
{
    int data;   // data stored in the node
    Node *next; // pointer to next node
};

struct Node* head = NULL;   // head of the list

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

int main()
{

}




/*
-------------------------------------------------------
Using Linked List with Node* head not as global variable
*/
// #include <iostream>
// #include <cstdlib>

// using namespace std;

// struct Node 
// {
//     int data;   // data stored in the node
//     Node *next; // pointer to next node
// };


// Node* Insert(Node* head ,int x)
// {
//     Node *temp = new Node;  // Create a new node 
//     temp->data = x;     // Assign data to the new node
//     temp->next = NULL;  // Link the new node to the head
//     if (head != NULL)
//     {
//         temp->next = head;
//     }
//     head = temp;        // Make the new node as head
//     return head;
// }

// void Print(Node* head)
// {
//     cout << "The list is: ";
//     while (head != NULL) // traverse through the list
//     {
//         cout << head->data << " "; // print the data
//         head = head->next; // move to the next node
//     }
//     cout << endl;   
// }

// int main()
// {
//     Node* head = NULL; // empty list
//     int n;
//     cout << "Enter the number of elements in the list: ";
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         int x;  
//         cout << "Element " << i + 1 << ": ";
//         cin >> x;   
//         head =Insert(head, x);  
//         Print(head);    
//     }
// }