#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class LinkedList{
    Node* head;
public: 
    LinkedList(){head=NULL;}
    void insert(int val){
        Node* newNode=new Node;
        newNode->data=val;
        newNode->next=head;
        head=newNode;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    LinkedList list;
    list.insert(30);
    list.insert(20);
    list.insert(10);
    cout<<"Linked List: ";
    list.display();
    return 0;
}