/** Code360: Cycle Detection in Undirected Graph
 * Link: https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;



/* Algo:
- Keep track of Visited
- Keep Track of parent of the node
- Everything similar to BFS Traversal only change is:
    - When we reach a cycle: (nextNode != parent and visited[nextNode] == true)
*/
void prepareAdjacencyList(int m, vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList){
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

bool detectCycleUsingBFS(int src, unordered_map<int, list<int>> adjList, unordered_map<int, bool> &visited){
    queue<int> q;
    unordered_map<int, int> parent;

    parent[src] = -1;

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto &i: adjList[node]){
            if(visited[i] == true && i != parent[node]){
                return true;
            } 
            else if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = node;
            }
        }
    }
    return false;
}


string cycleDetectionBFS(vector<vector<int>> &edges, int n, int m)
{
    // Build the adjacency List
    unordered_map<int, list<int>> adjList;
    prepareAdjacencyList(m, edges, adjList);

    unordered_map<int, bool> visited(n);
    unordered_map<int, int> parent(n);

    bool ans;
    // To traverse to through each connected components
    // To handle disconnected components
    for(int i=0; i<n; i++){
        if(!visited[i]){
            ans = detectCycleUsingBFS(i, adjList, visited);     // node, parent, adjList
            if(ans == true)
                return "Yes";
        }
    }
    return "No";
}


bool detectCycleUsingDFS(int node, int parent, unordered_map<int, list<int>> adjList, unordered_map<int, bool> visited){
    visited[node] = true;
    for(int &i: adjList[node]){
        if(!visited[i]){
            bool cycleDetected = detectCycleUsingDFS(i, node, adjList, visited);
            if(cycleDetected)
                return true;
        }
        else if(i != parent){
            return true;
        }
    }
}


string cycleDetectionDFS(vector<vector<int>> &edges, int n, int m)
{
    // Build the adjacency List
    unordered_map<int, list<int>> adjList;
    prepareAdjacencyList(m, edges, adjList);

    unordered_map<int, bool> visited(n);
    unordered_map<int, int> parent(n);

    bool ans;
    // To traverse to through each connected components
    // To handle disconnected components
    for(int i=0; i<n; i++){
        if(!visited[i]){
            ans = detectCycleUsingDFS(i, -1, adjList, visited);     // node, parent, adjList
            if(ans == true)
                return "Yes";
        }
    }
    return "No";
}




int main(){
    int n = 5;
    vector<vector<int>> edges {{4,0},{4,3},{1,4}};
    cout << cycleDetectionBFS(edges, n, edges.size()) << endl;
    cout << cycleDetectionDFS(edges, n, edges.size()) << endl;
}
