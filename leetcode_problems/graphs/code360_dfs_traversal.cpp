/** Code360: DFS Traversal
 * Link: https://www.naukri.com/code360/problems/dfs-traversal_630462
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;


// Given : Undirected and Disconnected Graph G(V,E)

/* Algo :
- Prepare Adjacecy List for each node
- Make a visited map for the nodes which are visited
- Make recursive calls if :
    - visited[i] is false
    - dfs(node)
*/

void prepareAdjacencyList(int numEdges, vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList){
    for(int i=0; i < numEdges; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);        // coz undirected graph
    }
}

void dfs(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &component){
    component.push_back(node);
    visited[node] = true;

    for(auto &i: adjList[node]){
        if(!visited[i])
            dfs(i, adjList, visited, component);
    }
}



vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Prepare adjacency list in form of an unordered_map
    unordered_map<int, list<int>> adjList;
    prepareAdjacencyList(E, edges, adjList);

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, adjList, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}

void print2DVectors(vector<vector<int>> &res){
    for(auto &i: res){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<int>> edges{{0,2},{0,1},{1,2},{3,4}};
    int V = 5, E = 4;

    auto ans = depthFirstSearch(V,E,edges);
    print2DVectors(ans);

}