// Given a Directed Acyclic Graph (DAG) with V vertices labeled from 0 to V-1.
// The graph is represented using an adjacency list where adj[i] lists all 
// nodes connected to node. Find any Topological Sorting of that Graph.
// In topological sorting, node u will always appear before node v if there is 
// a directed edge from node u towards node v(u -> v).
// The Output will be True if your topological sort is correct otherwise it 
// will be False.

#include<bits/stdc++.h>
using namespace std;

// DFS traversal: topological sort
// time: O(V+E)
// space: O(V)

class Solution{
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st){
        // mark the node as visited
        vis[node] = 1;

        // traverse all the neighbours
        for(auto it: adj[node]){
            if(vis[it] == 0)
                dfs(it, adj, vis, st);
        }

        // add the current node to stack once all the nodes connected to it has been processed
        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[]){
        // to store the result
        vector<int> ans;

        // stack to store processed nodes in reverse order
        stack<int> st;

        // visited array
        vector<int> vis(V, 0);

        // traverse the graph
        for(int i=0;i<V;i++){
            // start DFS traversal for unvisited node
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }

        // until the stack is empty
        while(!st.empty()){
            // add the top of stack to result
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// BFS traversal - Kahn's algorithm
class Solution2 {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        // to store the result
        vector<int> ans;
        // to store the in-degree of nodes
        vector<int> inDegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i])
                inDegree[it]++;
        }

        queue<int>q;
        // add the nodes with no in-degree (0) to queue
        for(int i=0;i<V;i++){
            if(inDegree[i] == 0)
                q.push(i);
        }

        // until the queue is empty
        while(!q.empty()){
            int node = q.front();
            // add it to the answer
            ans.push_back(node);
            q.pop();

            // traverse the neighbours
            for(auto it: adj[node]){
                // decrement the in-degree
                inDegree[it]--;
                // add the node to queue of its in-degree becomes 0
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};