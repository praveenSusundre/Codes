#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

// make a priority queue, min heap of {shortestDist, node}
// keep a distance vector, for final shortest dist
// start from the source node, add it to PQ
// start a while loop till the PQ is empty
// for each min node, taken from PQ, take its adjacenet nodes
// check if the dist can be updated of adj node, 
// if dist updated, add those nodes into PQ
// continue the loop

    void dijikstra(int V, vector<pair<int, int>> adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            int minDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                if(dist[it.first] > minDist + it.second){
                    dist[it.first] = minDist + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        for(auto it:dist) cout << it << " "; cout << endl;
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

    obj.dijikstra(V,adj);

    return 0;
}


/*

input:

5 6
0 1 2
0 3 1
1 2 4
1 4 5
2 3 3
2 4 1

*/
