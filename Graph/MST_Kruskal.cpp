#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int w;
    node(int u1, int v1, int w1){u = u1, v = v1, w = w1;}
};

class Solution {
public:

    int findpar(int u, vector<int> &parent){
        if(parent[u] == u) return u;
        return     findpar(parent[u], parent);
    }

    void unionEdge(int u, int v, vector<int> &rank, vector<int> &parent){
        u = findpar(u, parent);
        v = findpar(v, parent);
        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[v] > rank[u]) parent[u] = v;
        else parent[v] = u, rank[u]++;
    }


// take a structure for edges {u, v, w}
// take the input and sort according to weights
// take 2 vectors -> parents and rank = 0
// initialize all the parents to itself
// start a loop for all the edges in ascending order
// if their parents are diff, union them, and include them in mst
// otherwise ignore the edge
// write function for union, findpar

    void kruskal(int V, vector<node> &edges){
        vector<int> parent(V);
        vector<int> rank(V,0);
        for(int i = 0; i < V; i++) parent[i] = i;

        vector<pair<int, int>> mstEdges;
        int mstCost = 0;

        for(auto it : edges){
            if(findpar(it.u, parent) != findpar(it.v, parent)){
                mstCost += it.w;
                mstEdges.push_back({it.u, it.v});
                unionEdge(it.u, it.v, rank, parent);
            }
        }
        cout << mstCost << "\n";
        for(auto it: mstEdges) cout << it.first << "->" << it.second << "\n";
    }
};

bool compWeights(node n1, node n2){ return n1.w < n2.w; }

int main(){
    
    
    int V, E;
    cin >> V >> E;                    
    vector<node> edges;
    for(int i = 0; i < E; i++){       
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(node(u, v, w));
    }
    Solution obj;
    sort(edges.begin(), edges.end(), compWeights);
    obj.kruskal(V,edges);

    return 0;
}


/*

input:

5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7

*/
