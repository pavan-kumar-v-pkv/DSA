#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
public:
    int minSpanningTree(int V, vector<vector<int>> adj[]){
        // to store the edges
        vector<pair<int, pair<int, int>>> edges;
        // getting all edges from adjacency list
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int v = it[0];
                int wt = it[1];
                int u = i;
                edges.push_back({wt, {u, v}});
            }
        }

        // creating a disjoing set of V vertices
        DisjointSet ds(V);

        // sorting the edges based on their weights
        sort(edges.begin(), edges.end());

        int sum = 0;

        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            // join the nodes if not in the same set
            if(ds.findUPar(u) != ds.findUPar(v)){
                sum += wt;
                ds.unionBySize(u, v);
            }
        }
        return sum;
    }
};