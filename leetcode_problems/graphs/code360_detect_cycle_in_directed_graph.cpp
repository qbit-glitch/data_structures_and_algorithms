/** Code360: Detect Cycle in Directed GRaph
 * Link: https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

/* Algo :
- Do a normal DFS Traveral in a GRaph
- Keep an extra array to track the DFS calls
- if(dfsVisited[neighbour] == 1 and visited[neighbour] == True) => Cycle is present
- if(visited[neighbour] == True) => Cycle may or may not be present
*/

void prepareAdjacencyList(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adjList){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }
}



bool checkCycleDFS(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto &neighbour: adjList[node]){
        if(!visited[neighbour]){
            bool ans = checkCycleDFS(neighbour, adjList, visited, dfsVisited);    
            if(ans)
                return true;
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // build the adjacency List
    unordered_map<int, list<int>> adjList;

    prepareAdjacencyList(edges, adjList);

    unordered_map<int, bool> visited(n);
    unordered_map<int, bool> dfsVisited(n);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = checkCycleDFS(i, adjList, visited, dfsVisited);
            if(ans)
                return true;
        }
    }
    return false;

}

int main(){
    vector<pair<int, int>> edges{{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    cout << detectCycleInDirectedGraph(6, edges) << endl;
}