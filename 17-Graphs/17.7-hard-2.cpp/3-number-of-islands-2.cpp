// Given n, m denoting the row and column of the 2D matrix, and an array A of size k denoting the number of 
// operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 
// which means there is no land in the matrix. The array has k operator(s) and each operator has two integers 
// A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how 
// many islands are there in the matrix after each operation.
// The answer array will be of size k.

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(K*4ɑ)
// Each operation involves converting the sea cell to land cell and merging the nodes (if possible) taking an 
// overall O(4ɑ) time. Since, there are a total of K operations, the overall time complexoty is O(K*4ɑ).

// Space Complexity: O(K) + O(N*M)
// The result list takes O(K) space. The visited array takes O(N*M) space and the Disjoint set uses parent and 
// rank/size array storing all N*M nodes taking O(N*M) space.

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
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};

    bool isValid(int &i, int &j, int &n, int &m){
        //return false if pixel is invalid
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;

        // return true if pixel is invalid
        return true;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& A){
        // disjoint set data structure
        DisjointSet ds(n * m);
        // visited array
        int vis[n][m];
        memset(vis, 0, sizeof vis);

        // to store the count of islands
        int cnt = 0;
        // to store the result
        vector<int> ans;

        // perform each operation
        for(auto it: A){
            int row = it[0];
            int col = it[1];

            // if already a land cell, no new islands will be formed
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            // make the cell as land
            vis[row][col] = 1;
            // increment the count considering the land cell was alone
            cnt++;
            // check all the neighbours
            for(int i=0;i<4;i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                // if the cell is a valid land cell
                if(isValid(nr, nc, n, m) && vis[nr][nc] == 1){
                    // get the node and adjacent node number
                    int nodeNo = row*m + col;
                    int adjNodeNo = nr*m+nc;
                    // if not already connected, perform the union
                    if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                        // decrement count
                        cnt--;
                        // perform the union
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
            // store the number of islands after the current operation in the result list
            ans.push_back(cnt);
        }
        return ans;
    }
};