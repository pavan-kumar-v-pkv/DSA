// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and
// a 2D Integer array edges, where there is a directed edge from vertex 
// edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.
// Find the shortest path from source vertex to all the vertices and if it is 
// impossible to reach any vertex, then return -1 for that vertex. The source 
// vertex is assumed to be 0.
#include<bits/stdc++.h>
using namespace std;

// Intuition:
// Finding the shortest path to a node is easy if the shortest paths to all the
// nodes that can precede it are known. Processing the nodes in topological 
// order ensures that by the time a node is reached, all the nodes that can 
// precede have already been processed, reducing the computation time 
// significantly.
// Thus, for the solution, the nodes will be traversed sequentially according 
// to their reachability from the source.

// Once the topological ordering is obtained, all the nodes can be processed 
// one by one. For every vertex being processed, we update the distances of 
// its adjacent using the distance of the current vertex.

// time: O(N+M)
// space: O(N+M)
class Solution{
    void topoSort(int node, vector<pair<int, int>> adj[], vector<bool>& vis, stack<int>& st){
        vis[node] = 1;

        for(auto it: adj[node]){
            int v = it.first; // node
            // if not visited, perform DFS
            if(!vis[v]){
                topoSort(v, adj, vis, st);
            }
        }

        // add the current node to stack once all the nodes connected to it have been processed
        st.push(node);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
        // to store the graph
        vector<pair<int, int>> adj[N];
        // add the edges to the graph
        for(int i=0;i<M;i++){
            int u = edges[i][0]; // node 1
            int v = edges[i][1];
            int wt = edges[i][2];

            // add the weighted edge
            adj[u].push_back({v, wt});
        }

        // visited array
        vector<bool> vis(N, false);

        // stack to facilitate topological sort using DFS
        stack<int> st;
        // get the topological ordering
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }

        // distance array to store the shortest paths
        vector<int> dist(N, 1e9);
        // distance of source node to itself is zero
        dist[0] = 0;
        // until the stack is empty
        while(!st.empty()){
            int node = st.top();
            st.pop();
            // update the distances of adjacent nodes
            for(auto it: adj[node]){
                int v = it.first; //adjacent node
                int wt = it.second; // edge weight
                // relaxing the edge, i.e. if a shorted path is found, 
                // update its distance to new shorter distance
                if(dist[node] + wt < dist[v]){
                    dist[v] = wt + dist[node];
                }
            }
        }
        // if a node is unreachable, updating its distance to -1
        for(int i=0;i<N;i++){
            if(dist[i]==1e9)
                dist[i] = -1;
        }

        return dist;
    }
};

