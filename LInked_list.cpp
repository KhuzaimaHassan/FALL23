#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        delete next;
        this->next = NULL;
        cout << "Memory is free " << value << endl;
    }
};

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *merge_two_sorted_LL(Node *head, Node *head1)
{
    Node *t1 = head;
    Node *t2 = head1;
    Node *dummynode = new Node(-1);
    Node *temp = dummynode;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = new Node(t1->data);
            temp = temp->next;
            t1 = t1->next;
        }
        else
        {
            temp->next = new Node(t2->data);
            temp = temp->next;
            t2 = t2->next;
        }
    }
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;

    Node *result = dummynode->next;
    dummynode->next = NULL;
    delete dummynode;
    return result;
}

Node *findmiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void merge_sortLL(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *middle = findmiddle(head);
    Node *right = middle->next;
    middle->next = NULL;

    Node *left = head;

    // Recursive calls for left and right halves
    merge_sortLL(left);
    merge_sortLL(right);

    // Merge the sorted halves and update the head
    head = merge_two_sorted_LL(left, right);
}

int main()
{
    Node *node1 = new Node(7);
    Node *head = node1;
    InsertAtHead(head, 1);
    InsertAtHead(head, 3);
    InsertAtHead(head, 5);
    InsertAtHead(head, 2);
    InsertAtHead(head, 10);
    cout << "First list: ";
    print(head);

    cout << endl
         << "SORTED LIST" << endl;

    merge_sortLL(head);
    print(head);

    return 0;
}
