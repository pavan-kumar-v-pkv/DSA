// Given a list of accounts where each element account [i] is a list of strings, where the first element account 
// [i][0] is a name, and the rest of the elements are emails representing emails of the account.
// Now, merge these accounts. Two accounts definitely belong to the same person if there is some common email to 
// both accounts. Note that even if two accounts have the same name, they may belong to different people as people 
// could have the same name. A person can have any number of accounts initially, but all of their accounts 
// definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is 
// the name, and the rest of the elements are emails in sorted order.
#include<bits/stdc++.h>
using namespace std;

// To identify if two accounts have a common email, iterating over two accounts of the same name and checking 
// each email can be costly.
// A more efficient way involves visualizing the set of emails of each account as a graph, forming various 
// connected components. Set of emails belonging to a person form a single node. Each mail can be placed under 
// a set representing that the email belongs to that person. If an email is found to be already associated with 
// some other person, a common email is found, which means all the emails in both the sets belong to a single 
// person and thus, merging of accounts(sets) must be done.

// Time Complexity: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) (where E = no. of emails)
// Visiting all the emails takes O(N+E) time.
// In the worst case, all the accounts can be merged taking O(E*4ɑ) time.
// All the emails to the result list and Sorting the emails take O(N*(ElogE + E)) times.

// Space Complexity: O(N+E)
// The hashmap will store all the emails taking O(E) space.
// The disjoint set data structure uses parent and size/rank arrays taking O(N) space.
// The resulting list will take up O(E) space.

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
    // function to merge the accounts
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts){
        int n = accounts.size(); // number of accounts
        // disoint set data structure
        DisjointSet ds(n);
        // hashmap to store the pair: {mails, node}
        unordered_map<string, int> mapMailNode;
        // iterate on all the accounts
        for(int i=0;i<n;i++){
            // iterate on all the mails of each account, 
            // start itertion on index 1 as index 0 has account user name
            for(int j=1;j<accounts[i].size();j++){
                // get the mail
                string mail = accounts[i][j];
                // if this mail was not alrady existing in the map in some other account
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    // add it to the hashmap
                    mapMailNode[mail] = i;
                }
                // otherwise join it with the previous component
                else{
                    // unite the components
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // to store the merged mail
        vector<string> mergedMail[n];
        // iterate on the hashmap
        for(auto it: mapMailNode){
            string mail = it.first; 
            int node = ds.findUPar(it.second); 

            // add the merged mail to the list
            mergedMail[node].push_back(mail);
        }
        // to return the result
        vector<vector<string>> ans;
        // iterate on all list of merged mail
        for(int i=0;i<n;i++){
            // if a person has no mail, skip the iteration
            if(mergedMail[i].size() == 0)
                continue;
            // otherwise, add all the merged mails of person
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


