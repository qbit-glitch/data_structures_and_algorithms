/** Code360: Dijkstras Shortest Path
 * Link: https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469
*/

#include <limits.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
using namespace std;

class comparator{
    public:
    bool operator()(pair<int, int>a, pair<int, int> b){
        return a.first > b.first;
    }
};


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // prepare the adjacency list
    unordered_map<int, list<pair<int,int>>> adjList;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    // data structure to store the minimum weights with the nodes from the source
    priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> pq;        // {distance, node}
    vector<int> distance(vertices, INT_MAX);

    distance[source] = 0;

    pq.push({distance[source], source});

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        for(auto &i: adjList[top.second]){
            if(distance[top.second] + i.second < distance[i.first]){
                distance[i.first] = distance[top.second] + i.second;
                pq.push({i.second, i.first});
            }
        }
    }

    return distance;
}


void printVector(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<vector<int>> vec {
        {0,1,7},
        {0,2,1},
        {0,3,2},
        {1,2,3},
        {1,3,5},
        {1,4,1},
        {3,4,7}
    };

    int vertices = 5, edges = 7, source = 0;
    vector<int> ans = dijkstra(vec, vertices, edges, source);
    printVector(ans);
}