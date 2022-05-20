#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

// take 3 arrays -> PARENT = -1, KEY = max, MSTSET = 0
// also take one priority queue to get the minkey vertex 
// start from 0th index, key[0] = 0, push the pair {key, vertex}
// start a loop for V-1 times, as MST has V-1 edges, then stops
// get the minkey vertex using PQ, in logN time, and mark it MSTSET[u] = 1 (selected)
// for all its adjacent nodes, who is not selected yet
// if the weight is less than its key, update it, also push the key into PQ
// continue the loop

    void prims_MST(int V, vector<pair<int, int>> adj[]){
        vector<int> parent(V,-1);
        vector<int> key(V,INT_MAX);
        vector<int> mstset(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});  // start node
        key[0] = 0;
        
        for(int i = 0; i < V-1; i++){
            
            int u = pq.top().second;
            pq.pop();
            mstset[u] = 1;
            
            for(auto it: adj[u]){
                int v = it.first, w = it.second;
                if(!mstset[v] && w < key[v]){
                    pq.push({w,v}), parent[v] = u, key[v] = w;
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
