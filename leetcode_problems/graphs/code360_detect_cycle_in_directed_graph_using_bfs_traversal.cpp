/** Code360: Detect Cycle in Directed graph using BFS
 * Link: https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // build the adjacency list
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
    }

    /* Kahn Algo :
        - We calculate the indegree for each vertex
        - We place elements whose indegree is 0 in a Queue
        - as we move elements from the queue, we reduce the indegree of each element until the queue is empty
    */
    vector<int> indegree(n+1,0);

    for(auto &i: adjList){
        for(auto &j: i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=1; i<indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto &neighbour: adjList[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if(ans.size() != n)
        return true;
    else
        return false;
}

int main(){
    vector<pair<int, int>> edges{{1,2},{3,1},{2,3}};
    cout << detectCycleInDirectedGraph(3, edges) << endl;
}