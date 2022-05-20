#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    // if not weighted. set the weights to 1
    // start from single source, pop the start node from queue
    // and traverse the BFS code.
    // update the shortest dist for all the adj node, if less than prev value
    // if dist is updated, then push the node into queue.
    // continue this, until the queue is empty

    void shortestPath_bfs(int V, vector<int> adj[]){
        vector<int> dist(V, INT_MAX);
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        for(auto it : dist) cout << it << " "; cout << endl;
    }
    
};

int main(){
    
    
    int V, E;
    cin >> V >> E;                    // input 1 -> 2 integers representing vertices and edges
    vector<int>adj[V];
    for(int i = 0; i < E; i++){       // input 2 -> all the egdes 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;

    // vector<int> tr = obj.dfs(V, adj);
    // for(auto it : tr) cout << " " << it;
    // cout << endl;
    bool ans = obj.shortestPath_bfs(V, adj);
    if(ans)
        cout << "Yes\n";
    else cout << "No\n";
    // obj.topological(V,adj);

    return 0;
}


/*

input:

5 6  
0 1
0 2
1 2
2 3
3 4
2 4
*/
