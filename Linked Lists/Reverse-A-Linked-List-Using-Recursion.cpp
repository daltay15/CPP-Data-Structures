/*
    Reverse a singly linked list using recursion.
*/


#include <iostream>
#include <cstdlib>

using namespace std;

struct Node 
{
    int data;   // data stored in the node
    Node *next; // pointer to next node
};

struct Node* head;

void Reverse(Node* p)       
{
   if (p->next == NULL)
   {
        head = p;       
        return;     
   } 
   Reverse(p->next);    // Recursively call the function until end of list     
   Node* q = p->next;   // 
   q->next = p;
   q->next = NULL;
}


void PrintReverse(Node* p)  // local variable
{
    if(p == NULL) return;
    PrintReverse(p->next);      // Print the next node    
    cout << p->data << " ";     // Print the data
}




int main()
{
    Node* head = NULL; // Empty list      

}
