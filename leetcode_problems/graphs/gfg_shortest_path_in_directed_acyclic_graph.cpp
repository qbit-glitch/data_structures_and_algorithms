/** GFG : Shortest Path in Directed Acyclic Graph
 * Link: https://www.geeksforgeeks.org/problems/shortest-path-in-directed-acyclic-graph/1
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
  public:
    void topoSortDFS(int node, unordered_map<int, list<pair<int, int>>> &adjList, stack<int> &st, vector<int> &visited){
        visited[node] = true;

        for(auto &neighbour: adjList[node]){
            if(!visited[neighbour.first]){
                topoSortDFS(neighbour.first, adjList, st, visited);
            }
        }
        st.push(node);
    }
  
  
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // prepare the adjacency list along with the weights
        unordered_map<int, list<pair<int,int>>> adjList;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adjList[u].push_back({v,w});
        }

        // apply topological sorting
        stack<int> st;      // topological sort will be stored in this 
        vector<int> visited(V);

        for(int i=0; i<V; i++){
            if(!visited[i])
                topoSortDFS(0, adjList, st, visited);
        }


        // now compute the distances from the source node to each node
        int src = 0;
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;

        while(!st.empty()){
            int top = st.top();
            st.pop();

            if(distance[top] != INT_MAX){
                for(auto &neighbour: adjList[top]){
                    if(distance[top] + neighbour.second < distance[neighbour.first])
                        distance[neighbour.first] = distance[top] + neighbour.second;
                }
            }
        }
        
        // to remove infinity from the final distance array
        for(int &i: distance){
            if(i == INT_MAX)
                i = -1;
        }

        return distance;
    }
};

void printVector(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}


int main(){
    vector<vector<int>> edges {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    Solution sol;
    int V = 6;
    vector<int> ans = sol.shortestPath(V, edges);
    printVector(ans);
}
