/** Code360: Prim's MST
 * Link: https://www.naukri.com/code360/problems/prim-s-mst_1095633
*/


#include <vector>
#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    // prepare the adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    // Make the key, mst and the parent data structure
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    // Let's start the algo
    key[1] = 0;
    parent[1] = -1;
    
    for(int i=1; i<=n; i++){
        // find the node with min val from the key
        // mark the mst as true for that node
        // iterate towards all the adjacent nodes and update the key if the distance is less than what is present
        // update the parent of those nodes as well
        
        
        // finding the min node
        int mini = INT_MAX, u;
        for(int v=1; v <= n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        // mark the min node as true
        mst[u] = true;

        // check it's adjacent nodes
        for(auto &i: adjList[u]){
            int v = i.first;
            int w = i.second;

            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int,int>, int>> result;
    for(int i=2; i<=n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

void printVector(vector<pair<pair<int,int>, int>> &a){
    for(auto &i: a){
        cout << i.first.first << ", " << i.first.second << ", " << i.second << endl;
    }
}

int main(){
    vector<pair<pair<int, int>, int>> edges {
        {{1,2},21}, {{1,4},16}, {{2,1},12}, {{2,3},13}, {{2,4},18}, {{2,5},15},
        {{3,2},13}, {{3,5},17}, {{4,1},16}, {{4,2},18}, {{4,5},19}, {{5,1},18},
        {{5,2},15}, {{5,3},17}, {{5,4},19}
    };
    auto ans = calculatePrimsMST(5, 15, edges);
    printVector(ans);
}

