// Given a boolean 2D matrix grid of size N x M. Find the number of distinct 
// islands where a group of connected 1s (horizontally or vertically) forms an 
// island. Two islands are considered to be same if and only if one island is 
// equal to another (not rotated or reflected).

#include<bits/stdc++.h>
using namespace std;

// time: O(N*M*log(N*M)), dfs call -> O(N*M), set will store O(N*M) takes log(N*M)
// space: O(N*M)

class Solution{
    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int, int>>& path, int& base_row, int& base_col){
        int n = grid.size();
        int m = grid[0].size();

        // add relative position of current cell wrt base cell
        path.push_back({row - base_row, col - base_col});

        // traverse the 4 neighbours
        for(int i=0;i<4;i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]){
                vis[nr][nc] = true;
                dfs(nr, nc, grid, vis, path, base_row, base_col);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool> > vis(n, vector<bool>(m, false));

        // set to store traversal of unique islands
        set<vector<pair<int, int> > > st;

        // traverse the grid
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // start BFS traversal if an unvisited land cell is found
                if(grid[i][j] == 1 && !vis[i][j]){
                    vis[i][j] = true;
                    // to store the path of cell
                    vector<pair<int, int> > path;

                    dfs(i, j, grid, vis, path, i, j);
                    //  add the path of explored island to the set
                    st.insert(path);
                }
            }
        }
        return st.size();
    }
};
