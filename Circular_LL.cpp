#include<iostream>
#include<utility>  // for std::pair
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next == NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for " << value << endl;
    }
};

void InsertNode(Node* &tail, int element, int data) {
    if (tail == NULL) {
        Node* NewNode = new Node(data);
        tail = NewNode;
        NewNode->next = NewNode;
    }
    else {
        Node* temp = tail;
        while (temp->data != element) {
            temp = temp->next;
        }
        Node* New = new Node(data);
        New->next = temp->next;
        temp->next = New;
    }
}

void DeleteNode(Node*& tail, int value) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else {
        Node* prev = tail;
        Node* curr = prev->next;
        while (curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == prev) {
            tail = NULL;
        }
        else if (tail == curr) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &tail) {
    Node* temp = tail;
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    int cnt = 0;
    do {
        cout << tail->data << " ";
        tail = tail->next;
        cnt++;
    } while (tail != temp);
    cout << endl << "length: " << cnt << endl;
}


pair<Node*, Node*> breakCircularList(Node* tail) {
    pair<Node*, Node*> result;

    if (tail == NULL || tail->next == tail) {
        // The list is empty or has only one element, cannot be split
        result.first = tail;
        result.second = NULL;
        return result;
    }

    // Use the tortoise and hare approach to find the midpoint
    Node* slow = tail->next;
    Node* fast = tail->next->next;

    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Set the heads and tails for the two halves
    result.first = tail->next;
    result.second = slow->next;

    // Break the circular link between the two halves
    slow->next = tail->next;
    tail->next = result.second;

    return result;
}

int main() {
    Node* tail = NULL;

    InsertNode(tail, 3, 4);
    print(tail);
    InsertNode(tail, 4, 5);
    print(tail);
    InsertNode(tail, 5, 6);
    print(tail);
    InsertNode(tail, 6, 7);
    print(tail);
    InsertNode(tail, 7, 8);
    print(tail);
    InsertNode(tail, 8, 9);
    print(tail);

    pair<Node*, Node*> halves = breakCircularList(tail);

    cout << "First Half: ";
    print(halves.first);

    cout << "Second Half: ";
    print(halves.second);

    return 0;
}
