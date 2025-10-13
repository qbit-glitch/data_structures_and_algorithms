/**
 * GFG: M-Coloring Problem
 * Link: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

// Function declarations
vector<int> findConnectedNodes(vector<vector<int>> &edges, int node);
bool isColoringPossible(vector<int> &connectedNodes, int color, vector<int> &colorMap);
bool func(int node, vector<int> &colorMap, vector<vector<int>> &edges, int v, int m);
bool graphColoring(int v, vector<vector<int>> &edges, int m);


// Function Defintions

/** Thought Process:
 * 1. Since we have to check for all possible combinations, we shall use recursion
 * 2. Recursively iterate through each node
 * 3. Each node will have `m` possible options for coloring
 * 4. check if coloring of `color` is possible at that particular nodes
 *      i. To check if coloring with color c is possible at a node
 *      ii. Find all connected nodes to that node
 *      iii. if color of any of connected node = c  ==> return false i.e. coloring not possible
 *      iv. If any of the recursive function call returns true, then return true from the recursive function and end the loop. 
 * 
 */
bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    vector<int> colorMap(v, -1);

    return func(0, colorMap, edges,v , m);
}




vector<int> findConnectedNodes(vector<vector<int>> &edges, int node){
    vector<int> connectedNodes;
    for(auto &i: edges){
        int v1 = i[0];
        int v2 = i[1];
        if(node == v1)
            connectedNodes.push_back(v2);
        if(node == v2)
            connectedNodes.push_back(v1);
    }
    return connectedNodes;
}


bool isColoringPossible(vector<int> &connectedNodes, int color, vector<int> &colorMap){
    for(auto &i: connectedNodes){
        if(colorMap[i] == color)
            return false;
    }
    return true;
}


bool func(int node, vector<int> &colorMap, vector<vector<int>> &edges, int v, int m) {
    if(node == v){
        cout << "Color Possible" << endl;
        return true;
    }

    vector<int> connectedNodes = findConnectedNodes(edges, node);
    
    for(int color = 0; color < m; color++){
        if(isColoringPossible(connectedNodes, color, colorMap)){
            colorMap[node] = color;
            cout << node  << " , " << color << endl;
            if(func(node+1, colorMap, edges, v, m))
                return true;
            colorMap[node] = -1;
        }
    }
    return false;
}



int main(){
    vector<vector<int>> edges {{0,1}, {1,3}, {2,3}, {3,0}, {0,2}};
    int nodes = 4;
    int m = 3;
    cout << graphColoring(nodes,edges,m) << endl;
}