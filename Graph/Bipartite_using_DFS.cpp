#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    bool bipartite_dfs(int s, vector<int> &color, vector<int> adj[]){
        if(color[s] == -1) color[s] = 0;                 // if not visited, set initial colour
        
        for(auto it : adj[s]){                           // for all its adjacent nodes
            if(color[it] == -1){                         // if color is -1 i.e not visited
                color[it] = 1 - color[s];                
                if(!bipartite_dfs(it, color, adj)){      // check bipartite_dfs for each adjacent
                    return false;
                }
            }
            else if(color[it] == color[s]){    // if already visited and color is same, no bipartite
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[]){
        vector<int> color(V,-1);                   // no need for visited array
        
        for(int i = 0; i < V; i++){
            if(color[i] == -1){                    // for each connected component run dfs
                if(!bipartite_dfs(i, color, adj)){ // if any component is not bipartite, return false
                    return false;
                }
            }
        }
        return true;
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

    // vector<int> tr = obj.dfs(V, adj);
    // for(auto it : tr) cout << " " << it;
    // cout << endl;
    bool ans = obj.isBipartite(V, adj);
    if(ans)
        cout << "Yes\n";
    else cout << "No\n";

    return 0;
}


/*

input:

7 7  
0 6
1 2
2 3
2 4
4 5
3 5
1 4
*/
