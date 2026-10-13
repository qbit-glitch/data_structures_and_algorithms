/** Code360: Shortest Path in Undirected Graph
 * Link: https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297
*/

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <iostream>
using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){

    // prepare the adjacency list
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // build the parent array
    unordered_map<int, bool> visited(n+1);
    unordered_map<int, int> parent(n+1);

    queue<int> q;

    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int &i: adjList[front]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                parent[i] = front;
            }
        }
    }

    // now traverse through the parent array to get the shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void printVector(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<pair<int, int>> edges {{1,2},{1,3},{1,4},{2,5},{4,6},{3,8},{5,8},{6,7},{7,8}};
    int n = 8, m = edges.size();
    auto ans = shortestPath(edges, n,m,1,8);
    printVector(ans);
}
