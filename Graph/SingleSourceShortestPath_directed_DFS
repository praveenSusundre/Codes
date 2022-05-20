#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    

    void topological_dfs(int s, vector<pair<int, int>> adj[], stack<int> &topo_order, vector<int> &visited){
        visited[s] = 1;
        for(auto it: adj[s]){
            if(!visited[it.first])
                topological_dfs(it.first, adj, topo_order, visited);
        }
        topo_order.push(s);
    }

    // first find the topological order using dfs
    // using that order, start calculating distance from 1st node
    // pop the node from stack
    // do nothing, if the chosen node is having dist infinite
    // else if, update the adjacent node's dist if less than prev value
    // continue this till the stack is empty
    void shortestPath_directed(int V, vector<pair<int, int>> adj[]){
        vector<int> dist(V, INT_MAX);
        vector<int> visited(V,0); 
        stack<int> topo_order;
        
        for(int i = 0; i < V; i++)
            if(!visited[i])
                topological_dfs(i, adj, topo_order, visited);
        
        dist[topo_order.top()] = 0;
        
        while(topo_order.empty() == 0){
            int node = topo_order.top();
            topo_order.pop();
            if(dist[node] != INT_MAX){
                for(auto it : adj[node]){
                    if(dist[it.first] > dist[node] + it.second){
                        dist[it.first] = dist[node] + it.second;
                    }
                }
            }
        }
        for(auto it : dist) cout << it << " "; cout << endl;
    }
    
};

int main(){
    
    
    int V, E;
    cin >> V >> E;                    // input 1 -> 2 integers representing vertices and edges
    vector<pair<int, int>> adj[V];
    for(int i = 0; i < E; i++){       // input 2 -> all the egdes 
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back(u);
    }
    Solution obj;

    // vector<int> tr = obj.dfs(V, adj);
    // for(auto it : tr) cout << " " << it;
    // cout << endl;
    // bool ans = obj.shortestPath_bfs(V, adj);
    // if(ans)
    //     cout << "Yes\n";
    // else cout << "No\n";
    obj.shortestPath_directed(V,adj);

    return 0;
}


/*

input:

6 7
0 1 2
0 4 1
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1
*/
