/** Code360: BFS in Graph
 * Link: https://www.naukri.com/code360/problems/bfs-in-graph_973002
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// Directed graph

/* Algo :
- Build the Adjacency List -> Already given in the question
- Make a visited map
- Store the elements in a queue while doing Breadth First Search
- while(!queue.empty()) -> 
    - Take the first element from Queue and Print it
    - Mark the node as visited in the visited map
    - put all the elements present in the Adjacency list in the queue if they are not visited
    - iterate until the queue is empty
*/

void bfs(int node, vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans){
    queue<int> q;
    q.push(node);

    while(!q.empty()) {
        int currNode = q.front();
        q.pop();
        
        if(visited[currNode] == false){
            ans.push_back(currNode);
            visited[currNode] = true;
        }

        for(int i: adj[currNode]){
            if(visited[i] == false)
                q.push(i);
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int, bool> visited;

    // If the graph is disconnected then to do a BFS traversal in the entire graph, 
    // we have to go through each node and check whether it's visited or not
    for(int i=0; i<adj.size(); i++){
        if(!visited[i])
            bfs(i, adj, visited, ans);
    }
    return ans;
}

void printVector(vector<int> &ans){
    for(auto &i: ans){
        cout << i << " ";
    } cout << endl;
}

int main(){
    vector<vector<int>> adj{{1,2,3},{4},{5},{},{},{}};
    vector<int> ans = bfsTraversal(adj.size(), adj);
    printVector(ans);
}