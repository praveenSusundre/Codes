#include<bits/stdc++.h>
using namespace std;

struct node{
    int u, v, w;
    node(int u1, int v1, int w1){
        u = u1, v = v1, w = w1;
    }
};

class Solution {
public:

// initializes distances to all vertices as infinite and to the source as 0
// do the relaxation(Updating dist) V-1 times for all the edges
// after V-1, do it one more time, to check if negative cycle
// if Vth time also, any edge dist is updated, then negative cycle exist
// otherwise we get the shortest distance for all the nodes from source
 
    void bellmanFord(int V, vector<node> edge){
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        for(int i = 1; i <= V-1; i++){
            for(auto it: edge){
                if(dist[it.u] + it.w < dist[it.v])
                    dist[it.v] = dist[it.u] + it.w;
            }
        }

        int negcycle = 0;
        for(auto it: edge){
            if(dist[it.u] + it.w < dist[it.v]){
                cout << "negative cycle detected\n";
                negcycle = 1;
                break;
            }
        }

        if(!negcycle){
            for(auto it:dist) cout << it << " "; cout << endl;
        }
    }
};


int main(){
    
    
    int V, E;
    cin >> V >> E;                    
    vector<node> edge;
    for(int i = 0; i < E; i++){       
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back(node(u, v, w));
    }
    Solution obj;
    
    obj.bellmanFord(V,edge);

    return 0;
}


/*

input:

5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

*/
