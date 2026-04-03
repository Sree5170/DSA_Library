#include<iostream>
using namespace std;
class CircularQueue{
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int s){
        front=rear=-1;
        size=s;
        arr=new int[s];
    }
    void enqueue(int value){
        if((front==0 && rear==size-1)||(rear==(front-1)%(size-1))){
            cout<<"\nQueue is full.";
            return;
        }
        else if(front==-1){
            front=rear=0;
            arr[rear]=value;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=value;
        }
        else{
            rear++;
            arr[rear]=value;
        }
        cout<<"\nInserted: "<<value;
    }
    int dequeue(){
        if(front==-1){
            cout<<"\nQueue is Empty.";
            return -1;
        }
        int data=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=-1; rear=-1;
        }
        else if(front=size-1) front=0;
        else front++;
        return data;
    }
    void displayQueue(){
        if(front==-1){
            cout<<"\nQueue is empty"; return;
        }
        cout<<"\nElements in Circular Queue: ";
        if(rear>=front){
            for(int i=front;i<=rear;i++) cout<<arr[i]<<" ";
        }
        else{
            for(int i=front;i<size;i++) cout<<arr[i]<<" ";
            for(int i=0;i<=rear;i++) cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    CircularQueue q(5);
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(16);
    q.enqueue(-6);
    q.displayQueue();
    cout<<"\nDeleted value: "<<q.dequeue();
    cout<<"\nDeleted value: "<<q.dequeue();
    q.displayQueue();
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
    q.displayQueue();
    return 0;
}