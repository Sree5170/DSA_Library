#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    int top;
    int arr[MAX];
public:
    Stack(){top=-1;}
    void push(int x){
        if(top>=(MAX-1)){cout<<"Overflow\n"; return;}
        arr[++top]=x;
    }
    int pop(){
        if(top<0){cout<<"Underflow\n"; return -1;}
        return arr[top--];
    }
};
int main() {
    Stack s;
    cout << "Pushing elements into the stack..." << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Popping elements from the stack:" << endl;
    cout << s.pop() << " popped from stack\n";
    cout << s.pop() << " popped from stack\n";
    cout << s.pop() << " popped from stack\n";
    cout << "\nAttempting to pop from an empty stack:" << endl;
    s.pop();
    return 0;
}