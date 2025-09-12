#include<bits/stdc++.h>
using namespace std;

class Solution{
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans){
        // mark the node as visited
        vis[node] = 1;
        // add the node to the result;
        ans.push_back(node);
        // traverse all its neighbours
        for(auto it: adj[node]){
            // if the neighbour is not visited
            if(!vis[it]){
                dfs(it, adj, vis, ans);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        vector<int> ans;

        for(int i=0;i<V;i++){
            // if the node is unvisited
            if(vis[i] == 0){
                dfs(i, adj, vis, ans);
            }
        }
        return ans;
    }
};