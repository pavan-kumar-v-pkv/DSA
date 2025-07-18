// Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. 
// The output can be returned in any order.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2), where N is the number of elements in the array
// space: O(1), no extra space is used
vector<int> majorityElement(vector<int>& v){
    int n = v.size();
    vector<int> ans;

    for(int i=0;i<n;i++){
        // selct the current element
        // checking if v[i] is not already in the ans vector
        if(ans.size() == 0 || ans[0] != v[i]){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(v[j] == v[i])cnt++;
            }
            if(cnt > (n/3))
                ans.push_back(v[i]);
        }
        if(ans.size() == 2) break; // since we can have at most 2 majority elements
    }
    return ans;
}

// better approach using hashing
// time: O(N), where N is the number of elements in the array
// space: O(N), where N is the number of elements in the array
vector<int> majorityElement2(vector<int> v){
    int n = v.size();
    vector<int> ans;
    unordered_map<int, int> mpp;

    int mini = int(n/3) + 1; // since we need to find elements which appear more than n/3 times
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
        // checking if v[i] is the majority element
        if(mpp[v[i]] == mini){
            ans.push_back(v[i]);
        }
        if(ans.size() == 2) break;
    }
    return ans;
}

// optimal approach using Boyer-Moore Voting Algorithm
// time: O(N), where N is the number of elements in the array
// space: O(1), no extra space is used
// Approach 
// Initialize 4 variables: cnt1 & cnt2 for tracking the counts of elements and el1 & el2 for storing the majority of elements.
// Traverse through the given array. If cnt1 is 0 and the current element is not el2 then store the current element of the array as el1 along with increasing the cnt1 value by 1.
// If cnt2 is 0 and the current element is not el1 then store the current element of the array as el2 along with increasing the cnt2 value by 1.
// If the current element and el1 are the same increase the cnt1 by 1 and if the current element and el2 are the same increase the cnt2 by 1.
// Other than all the above cases decrease cnt1 and cnt2 by 1. The integers present in el1 & el2 should be the result we are expecting. So, using another loop, to manually check their counts if they are greater than the floor(N/3).
vector<int> majorityElement3(vector<int>& v){
    int n = v.size();
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;
    int el1, el2;
    for(int i=0;i<n;i++){
        if(cnt1 == 0 && v[i] != el2){
            cnt1 = 1;
            el1 = v[i];
        }
        else if(cnt2 == 0 && v[i] != el1){
            cnt2 = 1;
            el2 = v[i];
        }
        else if(v[i] == el1){cnt1++;}
        else if(v[i] == el2){cnt2++;}
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for(int i=0;i<n;i++){
        if(v[i] == el1)cnt1++;
        if(v[i] == el2)cnt2++;
    }
    int mini = int(n/3)+1;
    if(cnt1 >= mini) ans.push_back(el1);
    if(cnt2 >= mini) ans.push_back(el2);
    return ans;
}