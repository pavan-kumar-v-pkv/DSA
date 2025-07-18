// Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and 
// wants to reach at coordinates (n-1, n-1).
// Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1).
// The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left),
// 'R' (right).
// The value 0 in grid denotes that the cell is blocked and rat cannot use that
// cell for travelling, whereas value 1 represents that rat can travel through
// the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any 
// other cell.
#include <bits/stdc++.h>
using namespace std;

// Function to check if the rat can move to the cell (i, j)
// time: O(4^(m*n)) because on every cell we need to try 4 different directions
// space: O(m*n) for the visited array and recursion stack
void solve(int r, int c, vector<vector<int> >& a, int n, vector<string>& ans, string path, vector<vector<int> >& vis, int dr[], int dc[]){
    // if the rat reaches the distination cell (n-1, n-1)
    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }
    string dir = "DRUL"; // down, right, up, left
    for(int ind=0;ind<4;ind++){
        int newr = r + dr[ind];
        int newc = c + dc[ind];
        // check if the new cell is within bounds, not visited, and not blocked
        if(newr >= 0 && newr < n && newc >= 0 && newc < n && a[newr][newc] == 1 && !vis[newr][newc]){
            // mark the cell as visited
            vis[newr][newc] = 1;
            // add the direction to the path
            path.push_back(dir[ind]);
            // recursively call the function for the new cell
            solve(newr, newc, a, n, ans, path, vis, dr, dc);
            // backtrack: unmark the cell and remove the last direction from the path
            vis[newr][newc] = 0;
            path.pop_back();
        }
    }
}
vector<string> findPath(vector<vector<int> >& m, int n){
    vector<string> ans;
    vector<vector<int> > visited(n, vector<int>(n, 0));
    int dr[4] = {1, 0, -1, 0}; // down, right, up, left
    int dc[4] = {0, 1, 0, -1};
    if(m[0][0] == 0 || m[n-1][n-1] == 0){
        return ans; // if the start or end cell is blocked, return empty
    }
    if(m[0][0] == 1 && m[n-1][n-1] == 1){
        visited[0][0] = 1; // mark the start cell as visited
        solve(0, 0, m, n, ans, "", visited, dr, dc);
    }
    return ans;
}


