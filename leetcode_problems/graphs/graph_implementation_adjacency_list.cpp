#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;


template <typename T>
class Graph{

public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        // direction = 0 -> Undirected graph
        // direction = 1 -> Directed Graph
        adj[u].push_back(v);
        if(!direction)
            adj[v].push_back(u);
    }

    void printGraph(){
        for(auto &i: adj){
            cout << i.first << " -> ";
            for(auto &j: i.second)
                cout << j << ", ";
            cout << endl;
        } 
    }
};

int main(){
    Graph<int> g;
    int n,e;    // nodes, edges
    cout << "Enter the number of Nodes" << endl;
    cin >> n;

    cout << "Enter the number of edge" << endl;
    cin >> e;

    for(int i=0; i < e; i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }
    g.printGraph();

}