// Given a sorted dictionary of an alien language having N words and K 
// starting alphabets of a standard dictionary. Find the order of characters
//  in the alien language.

// There may be multiple valid orders for a particular test case, thus you 
// may return any valid order as a string. The output will be True if the 
// order returned by the function is correct, else False denoting an incorrect 
// order. If the given arrangement of words is inconsistent with any possible 
// letter ordering, return an empty string "".
#include<bits/stdc++.h>
using namespace std;

// intuition:
// How this problem can be identified as a Graph problem?
// The problem suggests that there exists the ordering of different words
// based on the alien dictionary. Also, it is asked to find out the ordering 
// of letters based on the dictionary. The concept of ordering of nodes can 
// be solved using Topological sort which comes under the topic of Graphs.

// Follow-up question for interview:

// When is the ordering of letters not possible:
// * If every character matches and the largest word appears before the 
// shortest word: For example, if “abcd” appears before “abc”, we can say the 
// ordering is not possible.
// * If there exists a cyclic dependency between the characters: For example, 
// in the dictionary: dict: {“abc”, “bat”, “ade”} there exists a cyclic 
// dependency between 'a' and 'b' because the dictionary states 'a' < 'b' < 
// 'a', which is not possible.

//time: O(K+N), k-> no. of nodes, N -> no. of edges
// space: O(K+N)
class Solution{
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indegree(V, 0);

        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        vector<int> ans;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return ans;
    }
    string findOrder(string dict[], int N, int K){
        // initialise a graph of K nodes
        vector<int> adj[K];
        // compare the consecutive words
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            // compare the pair of strings letter by letter to identify 
            // the differentiating letter
            for(int ptr=0; ptr<len;ptr++){
                // if the differentiating letter is found
                if(s1[ptr] != s2[ptr]){
                    // add the edge to the graph
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }

        // get the topological sort of the graph formed
        vector<int> topo = topoSort(K, adj);

        // to store the answer
        string ans;
        for(int i=0;i<topo.size();i++){
            // add the letter to the result
            ans.push_back('a' + topo[i]);
            ans.push_back(' ');
        }
        return ans;
    }
};