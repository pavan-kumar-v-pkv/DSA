// You are given a matrix mat of size N x M where each cell contains either 'O'
// or 'X'.

// Your task is to replace all 'O' cells that are completely surrounded by 'X'
// with 'X'.

// Rules:
// * An 'O' (or a group of connected 'O's) is considered surrounded if it is not 
// connected to any border of the matrix.
// * Two 'O' cells are considered connected if they are adjacent horizontally or 
// vertically (not diagonally).
// * A region of connected 'O's that touches the border (i.e., first row, last 
// row, first column, or last column) is not surrounded and should not be 
// changed.

#include<bits/stdc++.h>
using namespace std;

// BFS or DFS can be applied
// DFS
// time: O(N*M)
// space: O(N*M)

class Solution {
    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};
    void dfs(int row, int col, vector<vector<bool> >& vis, vector<vector<char> >& mat, int n, int m){
        vis[row][col] = true;

        for(int i=0;i<4;i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 'O'){
                dfs(nr, nc, vis, mat, n, m);
            }
        }
    }
    vector<vector<char> > fill(vector<vector<char> > mat){
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool> > vis(n, vector<bool>(m, false));

        // traverse the boundaries to check for 'O'
        // traversal for boundary rows
        for(int j=0;j<m;j++){
            // check for unvisited 'O's in boundary rows
            // first row
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0, j, vis, mat, n, m);
            }

            // last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1, j, vis, mat, n, m);
            }
        }

        // traversal for boundary columns
        for(int i=0;i<n;i++){
            // check for unvisted 'O's in boundary columns
            // first column
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i, 0, vis, mat, n, m);
            }

            // last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, vis, mat, n, m);
            }
        }

        // traverse the matrix and convert the unvisited 'O's into 'X'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // check for unvisited Os
                if(mat[i][j] == 'O' && !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};


