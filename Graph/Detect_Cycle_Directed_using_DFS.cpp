#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

// for each connected component, visit the source first
// push it into path_elements
// check the cycle_detection for all its unvisited adjacent nodes
// if already visited, then cycle exist return true.
// before backtracking, make sure you remove the node from path_elements.

    bool cycle_dir_dfs(int s, vector<int> &visited, vector<int> &path_elements, vector<int> adj[]){
        visited[s] = 1;                            
        path_elements[s] = 1;                      

        for(auto it : adj[s]){                // for all its adjacent nodes            
            if(!visited[it]){                      
                if(cycle_dir_dfs(it, visited, path_elements, adj))
                    return true;
            }
            else if(path_elements[it]){            
                return true;
            }
        }
        path_elements[s] = 0;                 // before backtracking     
        return false;
    }

    bool iscycle_dir(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                // to maintain the visited node list
        vector<int> path_elements(V, 0);          // to maintain the path elements to check cycle

        for(int i = 0; i < V; i++){
            if(!visited[i]){                      // for all connected components
                if(cycle_dir_dfs(i, visited, path_elements, adj))
                    return true;
            }
        }
        return false;
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
        //adj[v].push_back(u);
    }
    Solution obj;

    // vector<int> tr = obj.dfs(V, adj);
    // for(auto it : tr) cout << " " << it;
    // cout << endl;
    bool ans = obj.iscycle_dir(V, adj);
    if(ans)
        cout << "Yes\n";
    else cout << "No\n";

    return 0;
}


/*

input:

7 6  
0 6
1 2
2 3
3 4
4 5
2 5 
1 4
*/
