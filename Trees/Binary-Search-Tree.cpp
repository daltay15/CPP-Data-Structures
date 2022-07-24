/*
    Implement a binary search tree.
*/

#include <iostream>
#include <cstdlib>
#include <queue>

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
    else if (data < root->data) // If data is less than root, insert in left child
    {
        root->left = insert(root->left, data);
    }
    else // If data is greater than root, insert in right child
    {
        root->right = insert(root->right, data);
    }
    return root;
}

BstNode *deleteData(BstNode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data) // If data is less than root, delete in left child
    {
        root->left = deleteData(root->left, data);
    }
    else if (data > root->data) // If data is greater than root, delete from right child
    {
        root->right = deleteData(root->right, data);
    }
    else    // If data is equal to root, delete it
    {
        if (root->left == NULL && root->right == NULL)  // If root has no children
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) // If root has only right child
        {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)   // If root has only left child
        {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }
        else // If root has both children
        {
            BstNode *temp = root->right;    
            while (temp->left != NULL)  // Find inorder successor
            {
                temp = temp->left;
            }
            root->data = temp->data;    // Copy inorder successor data to root
            root->right = deleteData(root->right, temp->data); // Delete inorder successor
        }
    }
    return root;
}
 


bool search(BstNode *root, int data)
{
    if (root == NULL) // If root is NULL, then the tree is empty
    {
        cout << "ERROR: Tree is empty" << endl;
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

int findHeight(BstNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else // Recursively traverse the tree
    {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}

bool isBST(struct BstNode *root)    // Popular Interview question
{
    if (root == NULL)
        return true;

    /* false if left is > than root */
    if (root->left != NULL && root->left->data > root->data)
        return false;

    /* false if right is < than root */
    if (root->right != NULL && root->right->data < root->data)
        return false;

    /* false if, recursively, the left or right is not a BST */
    if (!isBST(root->left) || !isBST(root->right))
        return false;

    /* passing all that, it's a BST */
    return true;
}

void levelOrder(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BstNode *> Q; // Create a queue to store the nodes
    Q.push(root);       // Push root to the queue
    while (!Q.empty())  // While queue is not empty
    {
        BstNode *current = Q.front(); // Get the front node
        cout << current->data << " "; // Print the data
        if (current->left != NULL)    // If left chhild exists, push to queue
        {
            Q.push(current->left); // Push left child to queue
        }
        if (current->right != NULL) // If right child exists, pusht to queue
        {
            Q.push(current->right); // Push right child to queue
        }
        Q.pop(); // Pop the front node
    }
}

void preOrder(BstNode *root) // Recursive pre-order traversal <DLR>
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BstNode *root) // Recusive in-order traversal <LDR>
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(BstNode *root) // Recursive post-order traversal <LRD>
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    BstNode *root = NULL; // Initialize root to NULL
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 17);
    root = insert(root, 18);
    root = insert(root, 19);
    root = insert(root, 16);
    root = insert(root, 11);
    root = insert(root, 13);
    root = insert(root, 14);
    root = insert(root, 21);
    root = insert(root, 22);


    cout << "The smallest number in the tree is: " << findMin(root) << endl;
    cout << "The largest number in the tree is: " << findMax(root) << endl;
    cout << "The height of the tree is: " << findHeight(root) << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    root = deleteData(root, 12);
    root = deleteData(root, 14);

    cout << "Level Order Traversal After Deletion: ";
    levelOrder(root);
    cout << endl;

    cout << "Pre Order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In Order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post Order Traversal: ";
    postOrder(root);
    cout << endl;

    if (isBST(root))
    {
        cout << "The tree is a binary search tree" << endl;
    }
    else
    {
        cout << "The tree is not a binary search tree" << endl;
    }

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