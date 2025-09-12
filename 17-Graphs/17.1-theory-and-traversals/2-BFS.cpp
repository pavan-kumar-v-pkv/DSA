#include<bits/stdc++.h>
using namespace std;

// time: O(V+E)
// space: O(V)
class Solution{
    private:
    void bfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans){
        queue<int> q;
        vis[node] = 1;
        // push the starting node
        q.push(node);
        // until the queue is empty
        while(!q.empty()){
            // get the node
            int node = q.front();
            q.pop();

            // add the node to answer
            ans.push_back(node);

            // traverse for all its neighbours
            for(auto it: adj[node]){
                // if the neighbour has previously not been visited, store in Q and mark as visited
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return;
    }
    public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        // visited array
        vector<int> vis(V, 0);
        // to store the result 
        vector<int> ans;
        // traverse all the nodes
        for(int i=0;i<V;i++){
            // if the node is unvisited
            if(vis[i]==0){
                // mark the node as visited
                vis[i] = 1;
                // call the BFS from that node
                bfs(i, adj, vis, ans);
            }
        }
        return ans;
    }
};