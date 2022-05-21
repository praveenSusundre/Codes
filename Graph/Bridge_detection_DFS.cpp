#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// take 3 vectors-> insertime, lowtime, visited
// for all the connected component run the dfs algo
// in dfs algo, set the inserttime and lowtime as timer
// for all its adjacent call dfs
// after returning from dfs, update the lowtime
// check if adj lowtime is greater than present nodes insert time
// if yes, then its a brigde, else it is not a bridge
// if the adj node is visited already, assign its inserttime as present node's lowtime

    void dfs_bridge(int s, int timer, int parent, vector<int> &insertTime, vector<int> &lowTime,
                         vector<int> &visited, vector<int> adj[]){
        visited[s] = 1;
        insertTime[s] = lowTime[s] = timer++;

        for(auto it: adj[s]){
            if(it == parent) continue;
            
            if(!visited[it]){
                dfs_bridge(it, timer, s, insertTime, lowTime, visited, adj);
                lowTime[s] = min(lowTime[s], lowTime[it]);

                if(insertTime[s] < lowTime[it]) 
                    cout << s << "-" << it << endl;  // bridge detected
            }
            lowTime[s] = min(lowTime[s], insertTime[it]);
        }
        
    }

    void bridge_detection(int V, vector<int> adj[]){
        vector<int> insertTime(V, -1);
        vector<int> lowTime(V, -1);
        vector<int> visited(V, 0);

        int timer = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs_bridge(i, timer, -1, insertTime, lowTime, visited, adj);
            }
        }
    }

};


int main(){
    
    
    int V, E;
    cin >> V >> E;                    
    vector<int> adj[V];
    for(int i = 0; i < E; i++){       
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    
    obj.bridge_detection(V,adj);

    return 0;
}


/*

input:

8 9
0 1 
1 2
1 3
2 3
3 4
4 5
4 7
5 6
6 7

*/
