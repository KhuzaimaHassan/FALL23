#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
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
int getlength(Node*&head){
    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
void insertathead(Node*&head,Node* &tail,int data){
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
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node*print1(Node*&head){
    Node*temp=head;
    int cnt=1;
    int middle=(getlength(head)/2);
    while(cnt<middle&&temp!=NULL){
       temp=temp->next;
       cnt++;
    }
    return temp;
}
int main(){
    Node*Node1=new Node(10);
    Node*head=Node1;
    Node*&tail=Node1;
    insertathead(head,tail,9);
    print(head);
    insertathead(head,tail,8);
    print(head);
    insertathead(head,tail,7);
    print(head);
    cout<<"Length: "<<getlength(head)<<endl;
    cout<<"MIDDLE: "<<print1(head)->data;

}