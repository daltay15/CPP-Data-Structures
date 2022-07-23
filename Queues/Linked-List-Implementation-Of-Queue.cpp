/*
    Queue implementation using linked list
*/

#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 100

class Queue{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *front, *rear;
    int count;
    int capacity;

public:
    Queue(int size = SIZE) // Constructor
    {
        front, rear = NULL;
        count = 0;
        capacity = SIZE;
    }

    ~Queue() // Destructor
    {
        Node *temp;
        while (front != NULL)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() // Check if queue is empty
    {
        if (front == NULL && rear == NULL) 
        {
            return true;
        }
        return false;
    }

    bool isFull() // Check if queue is full
    {
        if (rear->next == NULL) // rear->next is NULL because rear is the last node
        {
            return true;
        }
        return false;
    }

    void size() // Return the size of the queue
    {
        cout << "Queue size is : " << count << endl;
        return;
    }

    void peek() // Return the front of the queue
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }

    void enqueue(int data) // Insert an element at the rear of the queue
    {
        if (isFull())   
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if(isEmpty())
        {
            front = new Node;   // Create a new node
            front->data = data; // Assign data to the new node
            front->next = NULL; // Assign NULL to the next pointer of the new node
            rear = front;       // Assign the new node to the rear pointer
        }
        else
        {
            Node* temp = new Node;  
            temp->data = data;      // Assign data to the new node
            temp->next = NULL;      // Assign NULL to the next pointer of the new node    
            rear->next = temp;      // Assign the new node to the next pointer of the rear node    
            rear = temp;            // Assign the new node to the rear pointer
        }
        count++;    
    }

    void dequeue() // Remove an element from the front of the queue
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear) // If only one element is present in the queue
        {
            delete front;
            front = NULL;
            rear = NULL;
        }
        else    
        {
            Node* temp = front;
            front->next = front->next->next;
            delete temp;
        }
        count--;
        cout << "Element " << front->data << " is deleted" << endl;
    }
    
};

int main()
{
    class Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.size();
    q.peek();
    q.dequeue();
}
