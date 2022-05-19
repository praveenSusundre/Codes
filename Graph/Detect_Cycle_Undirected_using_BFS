#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    bool cycle_bfs(int s, vector<int> &visited, vector<int> adj[]){
        queue<pair<int, int>> q;                    // create queue with current and parent node
        q.push({s,-1});                             // for first node, parent is none
        visited[s] = 1;                             // mark it as visited

        while(!q.empty()){
            int node = q.front().first;            // current node
            int par = q.front().second;            // its parent node
            q.pop();
            visited[node] = 1;

            for(auto it : adj[node]){              // for all its adjacent nodes
                if(!visited[it]){                  // if adjacent node is not visited, just add it in queue
                    q.push({it, node});
                    visited[it] = 1;
                }
                else if(it != par){                // if already visited, and also not parent, then cycle exist
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                    // create visited array
        for(int i = 0; i < V; i++){
            if(!visited[i]){                          // for each connected component run bfs
                if(cycle_bfs(i, visited, adj)){       // if any component has cycle than return true
                    return true;
                }
            }
        }
        return false;
    }
    
};



int main(){
    // input 1 -> 2 integers representing vertices and edges
    // input 2 -> all the egdes 
    int V, E;
    cin >> V >> E;
    vector<int>adj[V];
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if(ans)
        cout << "Cycle is present\n";
    else cout << "Cycle is not present\n";

    return 0;
}
