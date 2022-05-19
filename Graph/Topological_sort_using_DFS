#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    // start from 1st node
    // go to the deep, explore adjacent nodes
    // while coming back, insert nodes into stack
    // pop the stack, will give the topological order

    void topological_dfs(int s, vector<int> &visited, stack<int> &order, vector<int> adj[]){
        visited[s] = 1;                            

        for(auto it : adj[s]){
            if(!visited[it]){
                topological_dfs(it, visited, order, adj);
            }
        }
        order.push(s);
    }


    void topological(int V, vector<int> adj[]){
        vector<int> visited(V, 0);                // to maintain the visited node list
        stack<int> order;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){                      // for all connected components
                topological_dfs(i, visited, order, adj);
            }
        }

        while(!order.empty()){
            cout << order.top() << " ";
            order.pop();
        }
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
    // bool ans = obj.iscycle_dir(V, adj);
    // if(ans)
    //     cout << "Yes\n";
    // else cout << "No\n";
    obj.topological(V,adj);

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
4 2 
*/
