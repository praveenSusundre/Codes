#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    bool cycle_dfs(int s, vector<int> &visited, int parent, vector<int> adj[]){
        visited[s] = 1;     

        for(auto it : adj[s]){                 // for all its adjacent nodes
            if(!visited[it]){                  // if adjacent node is not visited, run dfs for its adj
                if(cycle_dfs(it, visited, s, adj)){    // keeping parent as current node
                    return true;
                }
            }
            else if(parent != it){         // if already visited, and also not parent, then cycle exist
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                    // create visited array
        for(int i = 0; i < V; i++){
            if(!visited[i]){                          // for each connected component run dfs
                if(cycle_dfs(i, visited, -1, adj)){ // if any component has cycle than return true
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
