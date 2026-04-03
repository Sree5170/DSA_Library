#include<iostream>
using namespace std;
struct AdjNode{
    int dest;
    AdjNode* next;
};
struct AdjList{AdjNode* head;};
class Graph{
public:
    int V;
    AdjList* array;
    Graph(int V){
        this->V=V;
        array=new AdjList[V];
        for(int i=0;i<V;i++) array[i].head=NULL;
    }
    void addEdge(int src,int dest){
        AdjNode* newNode=new AdjNode();
        newNode->dest=dest;
        newNode->next=array[src].head;
        array[src].head=newNode;
        newNode=new AdjNode();
        newNode->dest=src;
        newNode->next=array[dest].head;
        array[dest].head=newNode;
    }
    void BFS(int start){
        bool* visited=new bool[V];
        for(int i=0;i<V;i++) visited[i]=false;
        int* queue=new int[V];
        int front=0,rear=0;
        visited[start]=true;
        queue[rear++]=start;
        while(front<rear){
            int curr=queue[front++];
            cout<<curr<<" ";
            for(AdjNode* temp=array[curr].head;temp!=NULL;temp=temp->next){
                if(!visited[temp->dest]){
                    visited[temp->dest]=true;
                    queue[rear++]=temp->dest;
                }
            }
        }
    }       
};
int main(){
    Graph g(5);
    g.addEdge(2, 1);
    g.addEdge(2, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    cout << "Breadth First Traversal (starting from vertex 2): " << endl;
    g.BFS(2);
    cout << endl;
    return 0;
}