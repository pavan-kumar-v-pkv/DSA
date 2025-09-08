// Given a directed graph with V vertices labeled from 0 to V-1. The graph is 
// represented using an adjacency list where adj[i] lists all nodes adjacent to 
// node i, meaning there is an edge from node i to each node in adj[i]. A node 
// is a terminal node if there are no outgoing edges. A node is a safe node if 
// every possible path starting from that node leads to a terminal node. 
// Return an array containing all the safe nodes of the graph in ascending 
// order.
#include<bits/stdc++.h>
using namespace std;

// intuition
// It can be observed that all possible paths starting from a node are going 
// to end at some terminal node unless there exists a cycle and the paths return 
// back to themselves.
// In order to find the safe nodes, the unsafe nodes can be detected by 
// checking if they exist or point to a cycle.

// a cycle detection technique: detect cycles in a Directed graph (Using DFS).
// Approach: https://takeuforward.org/plus/dsa/graph/hard-problems/find-eventual-safe-states?tab=editorial

// DFS: approach: detect nodes in cycle and nodes leading to cycle
// time: O(V+E)
// space: O(V)
class Solution{
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& check){
        // mark the node as visited
        vis[node]=1;
        // add the node to current path
        pathVis[node] = 1;
        // mark the node as potentially unsafe
        check[node] = 0;

        // traverse for adjacent nodes
        for(auto it: adj[node]){
            // when the node is not visited
            if(!vis[it]){
                // perform DFS recursively and if a cycle if found, return false
                if(dfs(it, adj, vis, pathVis, check)){
                    // return true since a cycle was detected
                    return true;
                }
            }
            // else if the node has been previously visited in the same path
            else if(pathVis[it]){
                // return true since a cycle was detected
                return true;
            }
        }

        // if the current node neither exist in a cycle nor points to a cycle, 
        // it can be marked as a safe node
        check[node] = 1;
        // remove the node from the current path
        pathVis[node] = 0;
        // return false since no cycle was found
        return false;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        // visited array
        vector<int> vis(V, false);
        // path visited array
        vector<int> pathVis(V, false);
        // to keept a check of safe node
        vector<int> check(V, false);

        // traverse the graph and check for safe nodes
        for(int i=0;i<V;i++){
            if(!vis[i]){
                // start DFS traversal
                dfs(i, adj, vis, pathVis, check);
            }
        }

        // to store the result
        vector<int> ans;
        // add the safe nodes to the result
        for(int i=0;i<V;i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// BFS approach
// In order to find the safe nodes, the unsafe nodes can be detected by 
// checking if they exist or point to a cycle. Now, to solve this using BFS 
// traversal technique, the topological sorting (Kahn's Algorithm) can be 
// used. The topological sort algorithm will automatically exclude the nodes 
// which are either forming a cycle or connected to a cycle.

// The node with outdegree 0 is considered as terminal node but the 
// topological sort algorithm deals with the indegrees of the nodes. So, to 
// use the topological sort algorithm, we will reverse every edge of the graph.

// time: O(V+E) + O(V*logV)
// * Reversing the graph takes O(E) time.
// * Finding topological sort using Kahn's algorithm takes O(V+E) time.
// * Sorting the nodes takes O(N*logN) time (where N is the number of safe nodes,
// which can go up to V in worst-case).
// space: O(V+E)
class Solution2{
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        vector<int> ans;
        queue<int> q;
        // add the nodes with in-degree 0 to queue
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            // traverse the neighbours
            for(auto it: adj[node]){
                // decrement the in-degree
                indegree[it]--;
                // add the node to queue of its in-degree becomes zero
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        // to store the reverse graph
        vector<int> adjRev[V];
        // reversing the edges
        for(int i=0;i<V;i++){
            // i->it
            // it->i
            for(auto it: adj[i]){
                adjRev[it].push_back(i);
            }
        }
        // returnt the topological sort of the graph
        vector<int> result = topoSort(V, adjRev);

        // sort the result
        sort(result.begin(), result.end());
        return result;
    }
};