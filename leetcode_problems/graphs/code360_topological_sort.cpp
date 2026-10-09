/** Code360: Topological Sort
 * Link: https://www.naukri.com/code360/problems/topological-sort_982938
 * Status: very very important
*/


#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

/* 
- NOTE: Applicable only for Directed Acyclic Graph (not cyclic graph)
- def: Linear ordering of vertices such that for every edge u -> v, u always appears before v
*/

void dfs(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, stack<int> &topoSortRes){
    visited[node] = true;
    for(int &neighbour: adjList[node]){
        if(!visited[neighbour]){
            dfs(neighbour, adjList, visited, topoSortRes);
        }
    }
    topoSortRes.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // build the adjacency list
    unordered_map<int, list<int>> adjList;
    for(int i=0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> topoSortRes;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, adjList, visited, topoSortRes);
        }
    }

    vector<int> ans;
    while(!topoSortRes.empty()){
        ans.push_back(topoSortRes.top());
        topoSortRes.pop();
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