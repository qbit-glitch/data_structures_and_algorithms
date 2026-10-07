/** Code360 : Creating and Printing Graph
 * Link : https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551
*/

#include <iostream>
#include <vector>
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector<vector< int >> &edges) {
    
    // To store the edges of a particular  node
    vector<int> ans[n];

    for(int i=0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    // Now to return the result as the output format we have to show the output in a particular format
    // output format : u, nodes connected to u, in a single vector
    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);

        for(int j=0; j < ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main(){
    int n=4, m=3;
    vector<vector<int>> edges{{1,2},{0,3},{2,3}};

    vector<vector<int>> adjacencyList = printAdjacency(n,m,edges);

    for(auto &i: adjacencyList){
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
}