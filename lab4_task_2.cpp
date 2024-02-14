#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data) {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
~Node(){
    int value=this->data;
    if (this->next==NULL){
        delete next;
        this->next=NULL;
    }
    cout<<"Memory is free for"<<value<<endl;
}
};
void insertathead(Node*&head,Node*&tail,int data){
    if (head==NULL){
        Node*temp=new Node (data);
        head=temp;
        tail=temp;
    }
    else{
        Node*temp=new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
        temp->prev=NULL;
    }
}
void insertattail(Node*&head,Node*&tail,int data){
    if (tail==NULL){
        Node*temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
        Node*temp=new Node (data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        temp->next=NULL;
    }
}
void insertatposition(Node*&head,Node*&tail,int position,int data){
    if (position==1){
        insertathead(head,tail,data);
        return;
    }
  Node*temp=head;
   int cnt =1;
    while(cnt<position-1){
        temp=temp->next;
    cnt++;
    }
    if (temp->next==NULL){
        insertattail(head,tail,data);
        return;
    }
   Node* Nodetoinsert=new Node(data);
   Nodetoinsert->next=temp->next;
   temp->next->prev=Nodetoinsert;
   temp->next=Nodetoinsert;
   Nodetoinsert->prev=NULL;
}
void print (Node*&head){
    Node*temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* combineLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    head2->prev = temp;
    return head1;
}
void SelectionSort(Node*&head){
    Node*temp=head;
    Node*curr;
    Node*max;
    while(temp!=NULL){
          max=temp;
          curr=temp->next;
          while(curr!=NULL){
            if (max->data < curr->data){
                max=curr;
            }
          curr=curr->next;
          }
         if (max->data!=temp->data){
            swap(max->data,temp->data);
         } 
           temp=temp->next;
          
          }
    }

int main()
{
    Node*head1=NULL;
    Node*tail1=NULL;
    cout<<"Printing List L : ";
    insertathead(head1,tail1,2);
    insertattail(head1,tail1,4);
    insertatposition(head1,tail1,3,6);
    insertatposition(head1,tail1,4,8);
    insertatposition(head1,tail1,5,10);
    print(head1);
    Node*head2=NULL;
    Node*tail2=NULL;
    cout<<"Printing List M : ";
    insertathead(head2,tail2,1);
    insertattail(head2,tail2,3);
    insertatposition(head2,tail2,3,5);
    insertatposition(head2,tail2,4,7);
    insertatposition(head2,tail2,5,9);
    print (head2);
    cout<<"Printing Combined Lists : ";
    Node* combinedHead = combineLists(head1, head2);
    print(combinedHead);
    cout<<"Printing List in desending order : ";
    SelectionSort(combinedHead);
    print(combinedHead);       
    return 0;
}