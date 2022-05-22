#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

// keep a single parent variable for every node while calling dfs_cycle function
// check the cycle for all its unvisited adj nodes, 
// if cycle exist for any adj node, then return true
// else for visited adj and not its parent, then also return true
// return false if all adjacents are covered.

    bool cycle_dfs(int s, vector<int> &visited, int parent, vector<int> adj[]){
        visited[s] = 1;     

        for(auto it : adj[s]){                 
            if(!visited[it]){                 
                if(cycle_dfs(it, visited, s, adj)){   
                    return true;
                }
            }
            else if(parent != it){         
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                    
        for(int i = 0; i < V; i++){
            if(!visited[i]){                          
                if(cycle_dfs(i, visited, -1, adj)){
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
