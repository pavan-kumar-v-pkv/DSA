// Given a directed graph with V vertices labeled from 0 to V-1. The graph is 
// represented using an adjacency list where adj[i] lists all nodes connected 
// to node. Determine if the graph contains any cycles.
#include<bits/stdc++.h>
using namespace std;

// DFS approach
// time: O(V+E)
// space: O(V)
class Solution {
    bool dfs(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& pathVisited){
        // mark the node as path visited
        pathVisited[node] = true;
        // mark the node as visited
        visited[node] = true;

        // traverse all the neighbours
        for(auto it: adj[node]){
            // if the neighbour is already visited in the path, a cycle is detected
            if(pathVisited[it])
                return true;

            // else if the node is unvisited, perform DFS from this node
            else if(!visited[it]){
                // if the cycle is detected, return true
                if(dfs(it, adj, visited, pathVisited))
                    return true;
            }
        }
        // remove the node from path
        pathVisited[node] = false;

        // return false if no cycle is detected
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]){
        //visted array
        vector<bool> visited(V, false);
        // array to mark nodes that are visited in a particular path
        vector<bool> pathVisited(V, false);

        // traverse the graph
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // if a cycle is found, return true
                if(dfs(i, adj, visited, pathVisited))
                    return true;
            }
        }
        // return false if no cycle if detected in any component
        return false;
    }
};

// BFS method --> use kahn's algo
// if a topological sort array length not equal to number of vertices, then there is cycle
class Solution2 {
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> ans;
        vector<int> inDegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i])
                inDegree[it]++;
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }

        return ans;
    }
    bool isCyclic(int V, vector<int> adj[]){
        // to store the topological ordering
        vector<int> topo;
        topo = topoSort(V, adj);
        // if the topological sort doesn't include all node,
        // the graph is cyclic in nature
        if(topo.size() < V) return true;

        return false;
    }
};