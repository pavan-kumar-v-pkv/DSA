// Given an undirected graph with V vertices labeled from 0 to V-1. The graph 
// is represented using an adjacency list where adj[i] lists all nodes 
// connected to node. Determine if the graph contains any cycles.

// Note: The graph does not contain any self-edges (edges where a vertex is 
//     connected to itself).
#include<bits/stdc++.h>
using namespace std;

// BFS approach
// time: O(V+E)
// V -> number of nodes
// E -> number of edges
// space: O(V), in queue it may store all nodes taking O(V)
class Solution {
private:
    bool bfs(int i, vector<int> adj[], vector<bool>& visited){
        // queue to store {node, parent}
        queue<pair<int, int>> q;

        // push initial node in queue with no one as parent
        q.push({i, -1});

        // mark the node as visited
        visited[i] = true;

        // until the queue is empty
        while(!q.empty()){
            // get the node and its parent
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // traverse all the neighbours
            for(auto it: adj[node]){
                // if not visited
                if(!visited[it]){
                    // marl the node as visited
                    visited[it] = true;
                    // push the new node in queue with curr node as parent
                    q.push({it, node});
                }
                // else if it is visited with some different parent a cycle is detected
                else if(it != parent)
                    return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]){
        // visited array
        vector<bool> visited(V, false);

        // variable to store of there is a cycle detected
        bool ans = false;
        
        // start traversal from every unvisited node
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // start BFS traversal and update result
                ans = bfs(i, adj, visited);
                // break if a cycle is detected
                if(ans) break;
            }
        }

        return ans;
    }
};

// DFS approach
// time: O(V + E)
// space: O(V)
class Solution2{
private:
    bool dfs(int i, vector<int> adj[], vector<bool>& vis, int prev){
        // mark the node as visited
        vis[i] = true;

        // traverse all the neighbours
        for(auto node: adj[i]){
            // if not visited
            if(!vis[node]){
                if(dfs(node, adj, vis, prev))
                    return true;
            }
            // else if it is visited awith some different parent, a cycle is detected
            else if(node != prev){
                return true;
            }
        }
        // return false of no cycle is detected
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]){
        // visited array
        vector<bool> vis(V, false);

        // start the traversal from every unvisited node
        for(int i=0;i<V;i++){
            if(!vis[i]){
                // start DFS traversal, and return true if cycle is found
                if(dfs(i, adj, vis, -1))
                    return true;
            }
        }

        // return false if no cycle is detected
        return false;
    }
};