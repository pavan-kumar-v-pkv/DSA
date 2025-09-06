// Given an undirected graph with V vertices labeled from 0 to V-1. The graph 
// is represented using an adjacency list where adj[i] lists all nodes 
// connected to node. Determine if the graph is bipartite or not.

// A graph is bipartite if the nodes can be partitioned into two independent 
// sets A and B such that every edge in the graph connects a node in set A and 
// a node in set B.
// 👉 A graph is bipartite if you can split all the nodes into two groups such 
// that:
// Every edge goes from one group to the other.
// No edge stays inside the same group.
// 💡 Think of it like a party:
// You separate people into Group A and Group B.
// Friendships (edges) are only allowed between people in different groups.
// If two friends are in the same group, then it’s not bipartite.

#include<bits/stdc++.h>
using namespace std;

// BFS method:
// time: O(V+E)
// space: O(V)
class Solution{
private:
    bool bfs(int start, int V, vector<int> adj[], int color[]){
        // queueu for BFS traversal
        queue<int> q;

        // add initial node to queue
        q.push(start);
        color[start] = 0; // mark it with a color

        // while queue is not empty
        while(!q.empty()){
            // get the node
            int node = q.front();
            q.pop();

            // traverse it neighbours
            for(auto it : adj[node]){
                // if not already colored
                if(color[it] == -1){
                    // color it with opposite color
                    color[it] = !color[node];
                    // push the node in queue
                    q.push(it);
                }
                // else if the neighbour has same color as node
                else if(color[it] == color[node]){
                    // return false, as the component is not bipartite
                    return false;
                }
            }
        }
        // return true if the componenet is bartite
        return true;
    }
public:
    bool isBipartite(int V, vector<int> adj[]){
        // to store the colour of nodes, where each node is uncoloured initiallu
        int color[V];
        for(int i=0;i<V;i++)
            color[i] = -1;

        // traverse all the nodes
        for(int i=0;i<V;i++){
            // if not colored, start the traversal
            if(color[i] == -1){
                // return false if graph is not bipartite
                if(!bfs(i, V, adj, color))
                    return false;
            }
        }

        // return true if every component is bipartite
        return true;
    }
};

// DFS traversal
// time: O(V + E)
// space: O(V)
class Solution2{
    bool dfs(int node, int col, vector<int>& color, vector<int> adj[]){
        // color the current node
        color[node] = col;

        // traverse the adjacent node
        for(auto it: adj[node]){
            // if uncolored
            if(color[it] == -1){
                if(dfs(it, !col, color, adj) == false)
                    return false;
            }
            // else if previously coloured and have the same colour
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(int V, vector<int> adj[]){
        // to store the color of nodes, where each node is uncolored initially
        vector<int> color(V, -1);

        for(int i=0;i<V;i++){
            // if a node is not colored, a new component is found
            if(color[i] == -1){
                // start dfs traversal
                if(dfs(i, 0, color, adj) == false)
                    return false;
            }
        }

        return true;
    }
};

