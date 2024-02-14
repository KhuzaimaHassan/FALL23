#include <iostream>
#include <queue>
using namespace std;

// A binary tree node has data, a pointer to the left child, and a pointer to the right child
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Given a binary tree, print its nodes in inorder
void printInorder(Node *node)
{
    if (node == NULL)
        return;
    // first recur on the left child
    printInorder(node->left);
    // then print the data of the node
    cout << node->data << " ";
    // now recur on the right child
    printInorder(node->right);
}

// Implement pre-order traversal
void printPreorder(Node *node)
{
    if (node == NULL)
        return;
    // first print the data of the node
    cout << node->data << " ";
    // then recur on the left child
    printPreorder(node->left);
    // now recur on the right child
    printPreorder(node->right);
}

// Implement post-order traversal
void printPostorder(Node *node)
{
    if (node == NULL)
        return;
    // first recur on the left child
    printPostorder(node->left);
    // then recur on the right child
    printPostorder(node->right);
    // now print the data of the node
    cout << node->data << " ";
}

// Function to create a binary tree based on user input
Node *createUserTree()
{
    char stopChar;
    int data;
    cout << "Enter the root value: ";
    cin >> data;
    Node *root = newNode(data);

    // Use a queue to keep track of nodes to be processed
    queue<Node *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Left child
        cout << "Enter the left child value for node " << currentNode->data << " ('q' to stop): ";
        cin >> stopChar;
        if (stopChar == 'q')
            break;
        cin >> data;
        currentNode->left = newNode(data);
        nodeQueue.push(currentNode->left);

        // Right child
        cout << "Enter the right child value for node " << currentNode->data << " ('q' to stop): ";
        cin >> stopChar;
        if (stopChar == 'q')
            break;
        cin >> data;
        currentNode->right = newNode(data);
        nodeQueue.push(currentNode->right);
    }

    return root;
}

int main()
{
    // Create a binary tree based on user input
    Node *root = createUserTree();

    // Function calls for different traversals
    cout << "\nInorder traversal of the binary tree is \n";
    printInorder(root);

    cout << "\nPreorder traversal of the binary tree is \n";
    printPreorder(root);

    cout << "\nPostorder traversal of the binary tree is \n";
    printPostorder(root);

    return 0;
}
