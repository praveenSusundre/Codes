#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    bool bipartite_bfs(int s, vector<int> &visited, vector<int> &color, vector<int> adj[]){
        queue<int> q;                               // create queue with current and parent node
        q.push(s);                                  // for first node, parent is none
        color[s] = 0;                               // initial node colour
        
        while(!q.empty()){
            int node = q.front();                   // current node
            q.pop();

            for(auto it : adj[node]){               // for all its adjacent nodes
                if(color[it] == -1){                // if color is -1 i.e not visited
                    q.push(it);
                    color[it] = 1 - color[node];    // give opposite color to adjacent node
                }
                else if(color[it] == color[node]){  // if already visited and color is same, no bipartite
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                    // create visited array
        vector<int> color(V,-1);
        
        for(int i = 0; i < V; i++){
            if(color[i] == -1){                          // for each connected component run bfs
                if(!bipartite_bfs(i, visited, color, adj)){ // if any component is not bipartite, return false
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
