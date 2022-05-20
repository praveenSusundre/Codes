#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    // calculate indegrees of all the nodes
    // for all connected component do, initialise a counter
    // push all the nodes in a queue whose indegree is 0
    // start with 1st element from queue using FCFS
    // increase the counter
    // check all the adj nodes, and subtract 1 indegree from all the adjacent nodes
    // if indegree of any of the adjacent node becomes 0, push it into queue
    // continue this, until the queue is empty
    // if counter is equal to number of vertices, then no cycle exist, else exist

    bool cycle_dir_bfs(int V, vector<int> adj[]){
        vector<int> indegree(V, 0);      
        int cnt = 0;
        queue<int> q;

        for(int i = 0; i < V; i++){        // calculate indegree
            for(auto it: adj[i])
                indegree[it]++;
        }

        for(int i = 0; i < V; i++){       // push nodes whose indegree is 0
            if(!indegree[i])                    
                q.push(i);
        }

        while(!q.empty()){                // bfs algo for topological sort
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(cnt == V) return false;
        return true;
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
    bool ans = obj.cycle_dir_bfs(V, adj);
    if(ans)
        cout << "Yes\n";
    else cout << "No\n";
    // obj.topological(V,adj);

    return 0;
}


/*

input:

6 6  
0 3
1 0
1 5
3 2
4 0
2 0 
*/
