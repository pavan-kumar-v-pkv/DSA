// There is only one row of fruit trees on the farm, oriented left to right. 
// An integer array called fruits represents the trees, where fruits[i] denotes 
// the kind of fruit produced by the ith tree.
// The goal is to gather as much fruit as possible, adhering to the owner's 
// stringent rules:
// 1) There are two baskets available, and each basket can only contain one 
// kind of fruit. The quantity of fruit each basket can contain is unlimited.
// 2) Start at any tree, but as you proceed to the right, select exactly one 
// fruit from each tree, including the starting tree. One of the baskets must 
// hold the harvested fruits.
// 3) Once reaching a tree with fruit that cannot fit into any basket, stop.
// Return the maximum number of fruits that can be picked.
#include<bits/stdc++.h>
using namespace std;

// nrute force approach
// time: O(N^2) where N is the length of the array
// space: O(3) at most the set data structure is holding 3 elements
int totalFruits(vector<int>& fruits){
    int n = fruits.size();
    int maxFruits = 0;

    for(int i=0;i<n;i++){
        unordered_set<int> baskets;
        for(int j=i;j<n;j++){
            baskets.insert(fruits[j]);
            if(baskets.size() <= 2)
                maxFruits = max(maxFruits, j-i+1);
            else
                break; // if more than 2 types of fruits, stop
        }
    }
    return maxFruits;
}

// better approach using sliding window technique
// time: O(2N) where N is the length of the array
// space: O(3) at most the set data structure is holding 3 elements
int totalFruits2(vector<int>& fruits){
    int n = fruits.size();
    int maxlen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mpp;

    while(r < n){
        mpp[fruits[r]]++;

        if(mpp.size() > 2){
            while(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }
        }
        // if number of different fruits is at most 2, update maxlen
        if(mpp.size() <= 2){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen; // return the maximum length found
}

// optimal approach using sliding window technique with two pointers
// time: O(N) where N is the length of the array
// space: O(3) at most the set data structure is holding 3 elements
int totalFruits3(vector<int>& fruits){
    int n = fruits.size();
    int maxlen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mpp;

    while(r < n){
        mpp[fruits[r]]++;

        if(mpp.size() > 2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]);
            l++;
        }
        if(mpp.size() <= 2){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen; // return the maximum length found
}