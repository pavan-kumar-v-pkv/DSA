// Given a graph with n vertices and m edges. The graph is represented by an array Edges, where Edge[i] = [a, b] indicates an edge between vertices a and b. One edge can be removed from anywhere and added between any two vertices in one operation. Find the minimum number of operations that will be required to make the graph connected. If it is not possible to make the graph connected, return -1.
#include<bits/stdc++.h>
using namespace std;

// Intuition: disjoint set
// The problem involves removing an edge and adding it between two other nodes, indicating that the graph is updating continuously. This gives the idea of using the Disjoint Set Data Structure.

// Now, to make the graph connected, all the different components of the graphs must be connected to each other (directly or indirectly). The minimum number of edges required to connect all the components is always one lesser than the number of components. Hence, the problem boils down to finding the number of components in the given graph. Once found, the minimum number of edges to connect the graph can be found. If the number of edges present in the graph is less than that required to connect the graph, it is impossible to connect the graph and thus -1 can be returned.

// time: O(N+M)
// space: O(N)

class DisjointSet{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
public:
    int solve(int n, vector<vector<int>> &Edge){
        // get the number of edges
        int size = Edge.size();
        // return -1 if connecting all vertices is not possible
        if(size < n-1) return -1;
        // disjoint set data structure
        DisjointSet ds(n);
        // add all the edges in the set
        int cntExtras = 0;
        for(int i=0;i<size;i++){
            int u = Edge[i][0];
            int v = Edge[i][1];
            if(ds.findUPar(u) == ds.findUPar(v))
                cntExtras++;
            else
                ds.unionByRank(Edge[i][0], Edge[i][1]);
        }
        // to store the count of reuired edges
        int count = 0;
        // find the number of componenets
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i)count++;
        }
        int ans = count-1;
        if(cntExtras>=ans) return ans;
        return -1;
    }
};

