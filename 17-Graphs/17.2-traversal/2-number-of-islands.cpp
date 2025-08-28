// Given a grid of size N x M (N is the number of rows and M is the number of 
//     columns in the grid) consisting of '0's (Water) and ‘1's(Land). Find the 
//     number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands 
// horizontally or vertically or diagonally i.e., in all 8 directions.
#include<bits/stdc++.h>
using namespace std;

// time: O(N*M)
// space: O(N*M)
class Solution{
    private:
    void bfs(int i, int j, vector<vector<bool> >& vis, vector<vector<char> >& grid){
        // mark the node as visited
        vis[i][j] = true;
        queue<pair<int, int> > q;
        q.push({i, j});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse the 8 neighbours
            for(int delRow = -1;delRow<=1;delRow++){
                for(int delCol = -1;delCol<=1;delCol++){
                    int nrow = row + delRow;
                    int ncol = col + delCol;

                    if(nrow < n && nrow > 0 && ncol < m && ncol > 0 && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    public:
    int numIslands(vector<vector<char> >& grid){
        int n = grid.size();
        int m = grid[0].size();

        //visited array
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;i<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};