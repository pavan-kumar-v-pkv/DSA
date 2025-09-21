// Given an undirected connected Graph with V vertices (Numbered from 0 to V-1) and E edges. An edge is represented 
// [ai, bi] denoting that there is an edge from vertex ai to bi . An edge is called a bridge if its removal makes 
// some vertex unable to reach another vertex.
// Return all bridges in the graph in any order.

#include<bits/stdc++.h>
using namespace std;

// time: O(V+E)
// space: O(V)
class Solution{
    // to store the current time during traversal
    int timer = 1;
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges){
        vis[node] = 1;
        // time of insertion and the lowest time of insert for node will be current time
        tin[node] = low[node] = timer;

        // increment the current time
        timer++;

        // traverse all its neighbours
        for(auto it: adj[node]){
            // skip the parent
            if(it == parent) continue;
            // if a neighbour is not visited
            if(!vis[it]){
                // make a DFS call
                dfs(it, node, vis, adj, tin, low, bridges);
                /* Once the recursive DFS call returns, upate
                the lowest time of insertion for the node */
                low[node] = min(low[it], low[node]);
                // if the lowest time of insertion of the node is found to be greater than the time of insertion of the neighbour
                if(low[it] > tin[node]){
                    // the edge is a bridge
                    bridges.push_back({it, node});
                }
            }
            else{
                // if the neighbour is already visited
                // update the lowest time of insetion of the node
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        // adjacency list
        vector<int> adj[n];
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // visited array
        vector<int> vis(n, 0);
        // to store the time of insertion (discovery time) of nodes
        vector<int> tin(n);
        // to store the lowest time of insert of the nodes
        vector<int> low(n);
        // to store the bridges of the graph
        vector<vector<int>> bridges;
        // start a dfs traversal from node 0 with its parent as -1
        dfs(0, -1, vis, adj, tin, low, bridges);
        // returnt he computed result
        return bridges;
    }
};