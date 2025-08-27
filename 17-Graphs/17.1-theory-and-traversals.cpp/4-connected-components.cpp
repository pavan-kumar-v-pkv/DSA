// Given a undirected Graph consisting of V vertices numbered from 0 to V-1 and 
// E edges. The ith edge is represented by [ai,bi], denoting a edge between 
// vertex ai and bi. We say two vertices u and v belong to a same component if 
// there is a path from u to v or v to u. Find the number of connected 
// components in the graph.
// A connected component is a subgraph of a graph in which there exists a path 
// between any two vertices, and no vertex of the subgraph shares an edge with 
// a vertex outside of the subgraph.
#include<bits/stdc++.h>
using namespace std;

class Solution{
    void bfs(int node, vector<int> adjLs[], vector<int>& vis){
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int i = q.front();
            q.pop();

            for(auto it: adjLs[i]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    void dfs(int node, vector<int> adjLs[], vector<int>& vis){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it])
                dfs(it, adjLs, vis);
        }
    }
    public:
    int findNumberOfComponents(int V, vector<vector<int> >& edges){
        int E = edges.size();
        vector<int> adjLs[V];

        for(int i=0;i<E;i++){
            adjLs[edges[i][0]].push_back(edges[i][1]);
            adjLs[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(V, 0);
        int cnt = 0;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                bfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};