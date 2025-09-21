// Given an n x n binary matrix grid, it is allowed to change at most one 0 to 1. A group of connected 1s forms an 
// island, where two 1s are connected if they share one of their sides.
// Return the size of the largest island in the grid after applying this operation.
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N2) Using nested loops, and within the loops, all the operations take constant time.

// Space Complexity: O(N2) The Disjoint set storing N2 nodes (cells) will take up 2*N2 space due to parent and size 
// arrays.
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
    private:
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    // function to add initial islands to the disjoint set data structure
    void addInitialIslands(vector<vector<int>> grid, DisjointSet& ds, int n){
        //traverse all the cell in the grid
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                // if the cell is not land, skip
                if(grid[row][col] == 0) continue;
                // traverse on all the neighbours
                for(int i=0;i<4;i++){
                    // get the coordinates of neighbor
                    int nr = row + delrow[i];
                    int nc = col + delcol[i];

                    // if the cell is valid and a land cell
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        // get the number for node
                        int nodeNo = row*n+col;
                        // get the number for neighbour
                        int adjNodeNo = nr*n+nc;
                        // take union of both nodes as they are part of the same island
                        ds.unionBySize(nodeNo, adjNodeNo);

                    }
                }
            }
        }
    }
    public:
    int largestIsland(vector<vector<int>>& grid){
        // dimensions of grid
        int n = grid.size();
        // disjoint set data structure
        DisjointSet ds(n*n);
        // function call to add initial inslands in the disjoint set
        addInitialIslands(grid, ds, n);

        // to store the answer
        int ans = 0;

        // traverse the grid
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                // if the cell is a land cell, skip
                if(grid[row][col] == 1) continue;
                // set to store the ultimate parent of neighbouring islands
                set<int> components;
                // traverse on all its neighbours
                for(int i=0;i<4;i++){
                    int nr = row + delrow[i];
                    int nc = col + delcol[i];

                    if(nr >= 0 && nr < n && nc >=0 && nc < n && n && grid[nr][nc] == 1){
                        // perform union and store ultimate parent in the set
                        int nodeNo = nr*n + nc;
                        components.insert(ds.findUPar(nodeNo));
                    }
                }
                // to store the size of current largest island
                int sizeTotal = 0;
                // iterate on all the neighbouring ultimate parents
                for(auto it: components){
                    // update the sizze
                    sizeTotal += ds.size[it];
                }
                // store the maximum size of island
                ans = max(ans, sizeTotal+1);
            }
        }
        // edge case
        for(int cellNo = 0;cellNo<n*n;cellNo++){
            // keep the answer update
            ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }
        return ans;
    }
};