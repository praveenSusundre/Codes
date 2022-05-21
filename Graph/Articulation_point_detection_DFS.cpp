#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// take 3 vectors-> insertime, lowtime, visited
// for all the connected component run the dfs algo
// in dfs algo, set the inserttime and lowtime as timer
// for all its adjacent call dfs
// after returning from dfs, update the lowtime
// check if adj lowtime is greater or equal to than present nodes inserttime
// if yes, then its a articulation point, else it is not
// if the adj node is visited already, assign its inserttime as present node's lowtime
// last check should be done for root node, check if it has more than 1 child, 
// if yes, then root node is also articulation point, otherwise not

    void dfs_articulate(int s, int timer, int parent, vector<int> &insertTime, vector<int> &lowTime,
                         vector<int> &visited, vector<int> adj[], vector<int> &isArticulate){
        visited[s] = 1;
        insertTime[s] = lowTime[s] = timer++;
        int child = 0;
        for(auto it: adj[s]){
            if(it == parent) continue;
            
            if(!visited[it]){
                dfs_articulate(it, timer, s, insertTime, lowTime, visited, adj, isArticulate);
                lowTime[s] = min(lowTime[s], lowTime[it]);

                if(insertTime[s] <= lowTime[it] && parent != -1) 
                    isArticulate[s] = 1;  // articulation point detected
                child++;
            }else
                lowTime[s] = min(lowTime[s], insertTime[it]);
        }

        if(parent == -1 && child > 1)
            isArticulate[s] = 1;
    }

    void articulation_detection(int V, vector<int> adj[]){
        vector<int> insertTime(V, -1);
        vector<int> lowTime(V, -1);
        vector<int> visited(V, 0);
        vector<int> isArticulate(V,0);
        int timer = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs_articulate(i, timer, -1, insertTime, lowTime, visited, adj, isArticulate);
            }
        }
        for(int i = 0; i < V; i++) if(isArticulate[i]) cout << i << endl;
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
    
    obj.articulation_detection(V,adj);

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
