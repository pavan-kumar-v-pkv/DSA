// Given a weighted, undirected graph of V vertices, numbered from 0 to V-1, 
// and an adjacency list adj where adj[i] represents all edges from vertex i.
// Each entry in adj[i] is of the form [to, weight], where:
// * to → the neighboring vertex connected to i,
// * weight → the weight of the edge between i and to.

// Given a source node S. Find the shortest distance of all the vertex from the 
// source vertex S. Return a list of integers denoting shortest distance 
// between each node and source vertex S. If a vertex is not reachable from 
// source then its distance will be 109.
#include<bits/stdc++.h>
using namespace std;


class Solution{
// Implementation: Using Min-Heap
// time: O(ElogV)
// space: O(V)
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        //priority queue
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        //distance array
        vector<int> dist(1e9);
        // distance of source node from itself is 0
        dist[S] = 0;
        // add the source node to the priority queue
        pq.push({0, S});
        
        // until the priority queue is empty
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // traverse all its neighbours
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];

                // if the tentative distance to reach adjacent node is smaller
                // than the known distance
                if(dis + edgeWt < dist[adjNode]){
                    // update the known distance
                    dist[adjNode] = dis + edgeWt;
                    // push the new pai in priority queue
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

// Implementation: Using Set
// time: O(ElogV)
// space: O(V)
    vector<int> dijkstra2(int V, vector<vector<int>> adj[], int S){
        // set to store {dist, node}
        set<pair<int, int>> st;
        // distance array
        vector<int> dist(V, 1e9);
        // distamce of source node from itself is 0
        dist[S] = 0;
        // adding the source node to set
        st.insert({0, S});

        while(!st.empty()){
            int dis = st.begin()->first;
            int node = st.begin()->second;
            st.erase(st.begin());

            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWt =it[1];

                // if the tentative distance to reach adjacent node is smaller than the known distance
                if(dis + edgeWt < dist[adjNode]){
                    // if another longer distance (other than 1e9) is found
                    // erase it from the set
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};