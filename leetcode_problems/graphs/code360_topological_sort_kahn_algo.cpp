/** Code360: Topological Sort using Kahn's Algorithm
 * Link: https://www.naukri.com/code360/problems/topological-sort_982938
*/

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;


/* Algo :
- find indegree of all nodes
- after doing bfs of a node -> decrease the indegree of the children node
- queue me store karna all those nodes whose indegree is 0
*/
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // build the adjacencyList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // build the indegree
    vector<int> indegree(v);
    for(auto &i: adjList){
        for(auto &j: i.second){
            indegree[j]++;
        }
    }

    // build the queue whose indegree is 0
    queue<int> q;
    for(auto i=0;i < indegree.size(); i++)
        if(indegree[i] == 0)
            q.push(i);
        
    vector<int> ans;
    
    // now do the BFS traversal
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(int &i: adjList[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}

void printVector(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}


int main(){
    vector<vector<int>> edges {{1,2},{1,3},{2,4},{3,4},{4,6},{4,5},{5,6}};
    int v = 7, e = edges.size();
    auto ans = topologicalSort(edges, v, e);
    printVector(ans);
}