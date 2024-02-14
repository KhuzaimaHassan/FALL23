#include<iostream>
using namespace std;
class Node{
 public: 
 int data;
 Node*prev;
 Node*next;
 // Constructor
 Node(int data){
    this->data=data;
    this->prev=NULL;
    this->next=NULL;
 }
 ~Node(){
    int value=this->data;
    if(this->next==NULL)
    {
        delete next ;
        this->next = NULL;
    }
    cout<<"Memory is free "<<value<<endl;
}
};
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlength(Node* &head){
    int len=0;
    Node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void InsertAtHead(Node*&head,Node*&tail,int data){
    if (head==NULL){
        Node*temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{Node*temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    temp->prev=NULL;}
}
void InsertAtTail(Node*&head,Node*&tail,int data){
    if(tail==NULL){
        Node*temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{Node*temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    temp->next=NULL;}
}
void InsertAtPosition(Node*&head,Node*&tail,int position,int data){
    Node*temp=head;
    if (position==1){
        InsertAtHead(head,tail,data);
        return;
    }
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if (temp->next==NULL){
        InsertAtTail(head,tail,data);
        return;
    }
    Node*Nodetoinsert=new Node(data);
    Nodetoinsert->next=temp->next;
    temp->next->prev=Nodetoinsert;
    temp->next=Nodetoinsert;
    Nodetoinsert->prev=temp;
}

void deletenode(Node*&head,int position){
 if (position==1)
 {
   Node*temp=head;
   temp->next->prev=NULL;
   head=temp->next;
   temp->next=NULL;
   delete temp;
 }
 else{
   // delete any middle or last node
   Node*curr=head;
   Node*prev=NULL;

   int cnt = 1;
   while (cnt<position)
   {
    prev= curr;
    curr=curr->next;
    cnt++;
   }
   
   curr->prev=NULL;
   prev->next=curr->next;
   curr->next=NULL;
   delete curr;
    
   }

}
Node* reverseDoublyLinkedList(Node* &head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        // Swap next and prev pointers for the current node
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;

        // Move to the next node
        curr = curr->prev;
    }

    // Update the head pointer
    head = prev->prev;

    return head;
}

int main()
{
    //Node*node1=new Node(10);
    Node*head=NULL;
    Node*tail=NULL;
    print(head);
    InsertAtHead(head,tail,23);
    InsertAtHead(head,tail,3);
    print(head);  
    cout<<getlength(head)<<endl;
    cout<<head->prev<<endl;
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,1);
    print(head);
    cout<<tail->next<<endl;
   InsertAtPosition(head,tail,3,4);
   print(head);
   InsertAtPosition(head,tail,1,4);
   print(head);
   InsertAtPosition(head,tail,7,4);
   print(head);
   cout<<"Head: "<<head->data<<endl;
     cout<<"Tail: "<<tail->data<<endl;
   deletenode(head,1);
   print(head);
   deletenode(head,6);
   print(head);
   reverseDoublyLinkedList(head);
   print(head);
    cout<<"Head: "<<head->data<<endl;
     cout<<"Tail: "<<tail->data<<endl;
   cout<<"LENGTH : "<<getlength(head)<<endl;
    return 0;
}