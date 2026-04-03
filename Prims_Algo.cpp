#include<iostream>
#define V 5
#define INF 999999
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int minKey = INF, minIndex;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }
        mstSet[minIndex] = true;
        for (int v = 0; v < V; v++) {
            if (graph[minIndex][v] && !mstSet[v] && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }
    for (int i = 1; i < V; i++) {
        std::cout << parent[i] << " - " << i << std::endl;
    }
};
int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph);
    return 0;
}