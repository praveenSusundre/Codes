#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

// take 3 arrays -> PARENT = -1, KEY = max, MSTSET = 0
// start from 0th index, key[0] = 0
// we need to find the min key, and select the node
// start a loop for V-1 times, as MST has V-1 edges, then stops
// find the minKEY vertex who is not selected yet, and mark its MSTSET[u] = 1 (selected)
// for all its adjacent nodes, who is not selected yet
// if the weight is less than its key, update it
// continue the loop

    void prims_MST(int V, vector<pair<int, int>> adj[]){
        vector<int> parent(V,-1);
        vector<int> key(V, INT_MAX);
        vector<int> mstset(V, 0);

        key[0] = 0;  // start node
        
        for(int i = 0; i < V-1; i++){
            
            int minkey = INT_MAX, u;
            for(int j = 0; j < V; j++){     
                if(!mstset[j] && minkey > key[j]){
                    minkey = key[j], u = j;
                }
            }

            mstset[u] = 1;
            for(auto it: adj[u]){
                int v = it.first, w = it.second;
                if(!mstset[v] && w < key[v]){
                    key[v] = w, parent[v] = u;
                }
            }
        }
        for(int i = 0; i < V; i++) cout << parent[i] << "->"<<i << "\n";        
    }
};

int main(){
    
    
    int V, E;
    cin >> V >> E;                    // input 1 -> 2 integers representing vertices and edges
    vector<pair<int, int>> adj[V];
    for(int i = 0; i < E; i++){       // input 2 -> all the egdes 
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Solution obj;

    obj.prims_MST(V,adj);

    return 0;
}


/*

input:

5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7

*/
