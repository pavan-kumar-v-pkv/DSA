// Given an undirected graph with V vertices. Two vertices u and v belong to a 
// single province if there is a path from u to v or v to u. Find the number of 
// provinces. The graph is given as an n x n matrix adj where adj[i][j] = 1 if 
// the ith city and the jth city are directly connected, and adj[i][j] = 0 
// otherwise.

// A province is a group of directly or indirectly connected cities and no 
// other cities outside of the group.
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E) (where V denotes the number of nodes, E denotes the number of edges)

// Converting adjacency matrix to list takes O(V2) time (equivalent to O(E)).
// Considering overall, all the nodes are visited through traversal techniques which takes O(V+ E) time.
// Space Complexity: O(V + E)

// Storing the adjacency list takes O(E) space.
// Any traversal technique takes O(V) extra space.
class Solution{
    void dfs(int node, vector<int> adjLis[], vector<int>& vis){
        vis[node] = 1;
        for(auto it: adjLis[node]){
            if(!vis[it]){
                dfs(it, adjLis, vis);
            }
        }
    }
    int numProvinces(vector<vector<int> > adj){
        int V = adj.size();
        vector<int> adjLis[V];

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i != j){
                    adjLis[i].push_back(j);
                    adjLis[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0);
        int cnt = 0;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjLis, vis);
            }
        }
        return cnt;
    }
};