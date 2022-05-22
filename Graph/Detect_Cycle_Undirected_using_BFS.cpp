#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

// create a queue of pairs, {current_node, parent_node}
// for source, parent will -1, push the source into queue, mark it visited
// start a while loop till the queue is empty
// take 1st node from queue, pop it from the queue
// push all the unvisited adjacent nodes with its parent, into queue
// if the adjacent node is visited and that is not parent, then cycle exist
// if q is empty, then cycle did not exist.

    bool cycle_bfs(int s, vector<int> &visited, vector<int> adj[]){
        queue<pair<int, int>> q;                    
        q.push({s,-1});                           
        visited[s] = 1;                            

        while(!q.empty()){
            int node = q.front().first;           
            int par = q.front().second;           
            q.pop();
            visited[node] = 1;

            for(auto it : adj[node]){              
                if(!visited[it]){                  
                    q.push({it, node});
                    visited[it] = 1;
                }
                else if(it != par){                
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                    
        for(int i = 0; i < V; i++){
            if(!visited[i]){                          
                if(cycle_bfs(i, visited, adj)){       
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
