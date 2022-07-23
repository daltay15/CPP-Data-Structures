/*
    Implement a binary search tree.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *getNewNode(int data)
{
    BstNode *newNode = new BstNode; // Allocate memory for new node
    newNode->data = data;           // Assign data to new node
    newNode->right = NULL;          // Initialize right child to NULL
    newNode->left = NULL;           // Initialize left child to NULL
    return newNode;                 // Return new node
}

BstNode *insert(BstNode *root, int data)
{
    if (root == NULL) // If root is NULL, create new node and return it
    {
        root = getNewNode(data);
        return root;
    }
    else if (data <= root->data) // If data is less than root, insert in left child
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) // If data is greater than root, insert in right child
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(BstNode *root, int data)
{
    if (root == NULL) // If root is NULL, then the tree is empty
    {
        return false;
    }
    else if (data == root->data) // If found
    {
        return true;
    }
    else if (data > root->data) // If data is > than root data, search right child
    {
        return search(root->right, data);
    }
    else if (data < root->data) // If data < root data, search left child
    {
        return search(root->left, data);
    }
    return false;
}

int findMin(BstNode *root)
{
    if (root == NULL) // If root is NULL, return -1
    {
        cout << "ERROR: Tree is empty" << endl;
        return -1;
    }
    else if (root->left == NULL) // If root has no left children, return data
    {
        return root->data;
    }
    else // Recursively traverse the left children until min number found
    {
        return findMin(root->left);
    }
}

int findMax(BstNode *root)
{
    if (root == NULL) // If root is NULL, return -1
    {
        cout << "ERROR: Tree is empty" << endl;
        return -1;
    }
    else if (root->right == NULL) // If root has no right children, return data
    {
        return root->data;
    }
    else // Recursively traverse the right children until max number is found
    {
        return findMax(root->right);
    }
}

int main()
{
    BstNode *root = NULL; // Initialize root to NULL
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 17);
    root = insert(root, 16);
    root = insert(root, 18);
    root = insert(root, 19);
    root = insert(root, 21);
    root = insert(root, 22);
    root = insert(root, 23);
    root = insert(root, 24);


    cout << "The smallest number in the tree is: " << findMin(root) << endl;
    cout << "The largest number in the tree is: " << findMax(root) << endl;

    int number;
    cout << "Enter a number to search: ";
    cin >> number;
    if (search(root, number))
    {
        cout << "Number found" << endl;
    }
    else
    {
        cout << "Number not found" << endl;
    }
    return 0;
}