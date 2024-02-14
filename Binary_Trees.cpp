#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertion(Node *first, int key)
{
    if (first == NULL)
    {
        // Create a new node and return it.
        return new Node(key);
    }
    else if (first->data > key)
    {
        // Insert into the left subtree.
        first->left = insertion(first->left, key);
    }
    else if (first->data < key)
    {
        // Insert into the right subtree.
        first->right = insertion(first->right, key);
    }
    // If the key is equal to the current node's data, do nothing (assuming no duplicates).
    return first;
}

Node *get_min(Node *root)
{
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

Node *delete_node(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delete_node(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete_node(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = get_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << " " << root->data;
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << " " << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << " " << root->data;
    }
}

Node *Search(Node *&root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (root->data < key)
    {
        return Search(root->right, key);
    }
    return Search(root->left, key);
}

int main()
{
    Node *root = NULL;
    root = insertion(root, 30);
    insertion(root, 40);
    insertion(root, 60);
    insertion(root, 80);
    insertion(root, 100);
    insertion(root, 50);
    insertion(root, 71);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    int key = 8;
    if (Search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;

    key = 71;

    // Searching in a BST
    if (Search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;

    key = 80;
    root = delete_node(root, key);
    inorder(root);
    cout << endl;

    return 0;
}
