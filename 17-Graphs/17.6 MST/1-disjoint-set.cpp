// Design a disjoint set (also called union-find) data structure that supports the following operations:
// DisjointSet(int n) initializes the disjoint set with n elements.
// void unionByRank(int u, int v) merges the sets containing u and v using the rank heuristic.
// void unionBySize(int u, int v) merges the sets containing u and v using the size heuristic.
// bool find(int u, int v) checks if the elements u and v are in the same set and returns true if they are, otherwise false.
#include<bits/stdc++.h>
using namespace std;

// disjoint set union by rank & size
// Rank: The rank of a node refers to the distance (the number of nodes 
// including the leaf node) between the furthest leaf node and the current node. Rank includes all nodes beneath the current node.
// time: O(1)
// space: O(2N)

class DisjointSet{
private:
    // to store the rank of each node
    vector<int> rank;
    // to store the size of components that each node belongs to
    vector<int> size;
    // to store the ultimate parent of each node
    vector<int> parent;

public:
    // constructor
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        // initialise each node with its own value
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    // function to find the ultimate parent along with path compression
    int findUParent(int node){
        // base case
        if(node == parent[node])
            return node;

            // backtracking step for path compression
        return parent[node] = findUParent(parent[node]);
    }

    // function to determine if 2 nodes are in the same component or not
    bool find(int u, int v){
        // return true if both have same ultimate parent
        return (findUParent(u) == findUParent(v));
    }

    // function to perform union of 2 nodes based on ranks
    void unionByRank(int u, int v){
        // get the ultimate parents of both nodes
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        // return if nodes already belong to the same component
        if(ulp_u == ulp_v) return;

        // otherwise, join the node to the other node having higher ranks among the two
        if(rank[ulp_u] < rank[ulp_v]){
            // update the parent
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            // update the parent
            parent[ulp_v] = ulp_u;
        }
        // if both have sam rank, join any node to the other
        // ans increment the rank of the parent node
        else{
            // update the parent
            parent[ulp_u] = ulp_v;
            // update the rank
            rank[ulp_v]++;
        }
    }
    // function to perform union of 2 nodes based on ranks
    void unionBySize(int u, int v){
        // get the ultimate parents of both node
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        // return if nodes already belong to the same component
        if(ulp_u == ulp_v) return;

        // otherwise, join the node belonging to the smaller component to the node belonging
        // to bigger component
        if(size[ulp_u] < size[ulp_v]){
            // update the parent
            parent[ulp_u] = ulp_v;
            // update the size
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
