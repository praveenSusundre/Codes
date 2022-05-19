#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    void dfs_traversal(int s, vector<int> &visited, vector<int> adj[], vector<int> &traversal){
        visited[s] = 1;                      // mark source as visited
        traversal.push_back(s);              // push it in traversal list

        for(auto it : adj[s]){               // call dfs for each adjacent
            if(!visited[it]){
                dfs_traversal(it, visited, adj, traversal);
            }
        }
    }

    vector<int> dfs(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                    // create visited array
        vector<int> traversal;                        // final traversal list
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){                          // for each connected component run dfs
                dfs_traversal(i, visited, adj, traversal);    // call bfs
            }
        }
        return traversal;
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

    vector<int> tr = obj.dfs(V, adj);
    for(auto it : tr) cout << " " << it;
    cout << endl;
  

    return 0;
}
