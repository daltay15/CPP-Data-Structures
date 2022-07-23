#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 100

class Queue{
private:
    int A[SIZE];
    int front, rear, count;
    int capacity;
public:
    Queue(int size = SIZE)  // Constructor
    {
        front = rear = -1;
        count = 0;
        capacity = SIZE;
    }

    ~Queue() // Destructor
    {
        delete [] A;
    }

    bool isEmpty()      // Check if queue is empty
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()       // Check if queue is full
    {
        if (rear == capacity - 1)
            return true;
        else
            return false;
    }

    void size()     // Return the size of the queue
    {
        cout << "Size of Queue is: " << count << endl;
        return;
    }

    void peek()     // Return the front element of the queue
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << A[front] << endl;
    }

    void enqueue(int data)      // Insert an element at the rear of the queue
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if(isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        A[rear] = data;
        cout << "Element " << data << " is inserted" << endl;
        count++;
    }

    void dequeue()          // Remove an element from the front of the queue
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            cout << "Element " << A[front] << " is deleted" << endl;
            front++;
            count--;
        }
    }
};


int main()
{
    class Queue q;
    q.enqueue(8);
    q.enqueue(5);
    q.enqueue(566);
    q.size();
    q.dequeue();
    q.dequeue();
    q.size();
    q.peek();
}