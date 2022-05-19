#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    void bfs_traversal(int s, vector<int> &visited, vector<int> adj[], vector<int> &traversal){
        queue<int> q;                        // create a queue
        q.push(s);                           // insert start node into queue
        visited[s] = 1;                      // mark it as visited

        while(!q.empty()){                   // till all the elements in component is over
            int node = q.front();            // take a node from queue using FCFS
            q.pop();
            traversal.push_back(node);       // push it in traversal list

            for(auto it : adj[node]){        // push all the unvisited adjacent nodes in queue
                if(!visited[it]){
                    q.push(it);        
                    visited[it] = 1;         // and mark them as visited
                }
            }
        }
    }

    vector<int> bfs(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                    // create visited array
        vector<int> traversal;                        // final traversal list
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){                          // for each connected component run dfs
                bfs_traversal(i, visited, adj, traversal);    // call bfs
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

    vector<int> tr = obj.bfs(V, adj);
    for(auto it : tr) cout << " " << it;
    cout << endl;

    return 0;
}
