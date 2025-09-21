// There are n stones at integer coordinate points on a 2D plane, with at most one stone per coordinate point. 
// Some stones need to be removed.A stone can be removed if it shares the same row or the same column as another 
// stone that has not been removed.
// Given an array of stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, 
// return the maximum possible number of stones that can be removed.

// problem: https://takeuforward.org/plus/dsa/graph/hard-problems-ii/most-stones-removed-with-same-row-or-column

#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N) The given stones array is traversed multiple times. Traversing the hashset will also take O(N) time.
// Space Complexity: O(Max Row number + Max Column number)

class DisjointSet{
    public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
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
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution{
public:
    int maxRemove(vector<vector<int>>& stones, int n){
        // to store the maximum row and column having a stone
        int maxRow = 0;
        int maxCol = 0;

        //iterate on all nodes
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // disjoint set data structure
        DisjointSet ds(maxRow + maxCol + 1);

        // to store the nodes having a stone in Disjoint Set
        unordered_map<int, int> stoneNodes;

        // iterate on all stones
        for(auto it: stones){
            // row number
            int nodeRow = it[0];
            // converted column number
            int nodeCol = it[1] + maxRow + 1;
            // add the nodes to the map
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        // to store the number of connected components
        int k = 0;

        // iterate on the set
        for(auto it: stoneNodes){
            // increment the count if a new component is found
            if(ds.findUPar(it.first) == it.first)
                k++;
        }

        return n-k;
    }
};