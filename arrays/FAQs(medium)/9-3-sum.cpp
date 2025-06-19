// Given an integer array nums. Return all triplets such that:
// i != j, i != k, and j != k
// nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. The output and the triplets can be returned in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // brute force approach
    // time: O(N^3), where N is the number of elements in the array
    // space: O(2*no. of unique triplets), no extra space is used
    vector<vector<int> > triplet(int n, vector<int>& arr){
        set<vector<int> > st;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++)
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
        vector<vector<int> > ans(st.begin(), st.end());
        return ans;
    }

    // better approach
    // time: O(N^2*logN), where N is the number of elements in the array
    // space: O(2*no. of unique triplets), no extra space is used
    // using hashing
    // we can use a set to store the unique triplets
    vector<vector<int> > triplet2(int n, vector<int>& arr){
        set<vector<int> > st;

        for(int i=0;i<n;i++){
            set<int> hashset;
            for(int j=i+1;j<n;j++){
                int third = -(arr[i] + arr[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(third);
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[j]);
            }
        }
        vector<vector<int> > ans(st.begin(), st.end());
        return ans;
    }
    // optimized approach
    // time: O(NlogN + N^2), where N is the number of elements in the array
    // space: O(no. of quadraplets), no extra space is used
    vector<vector<int> > triplet3(int n, vector<int>& arr){
        vector<vector<int> > ans;
        sort(arr.begin(), arr.end());

        for(int i=0;i<n;i++){
            // remove duplicates for the first element
            if(i != 0 && arr[i] == arr[i-1]) continue;
            // two pointers approach
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum < 0){
                    j++;
                }
                
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                    j++;
                    k--;
                    
                    // remove duplicates for the second element
                    while(j < k && arr[j] == arr[j+1]) j++;
                    // remove duplicates for the third element
                    while(j < k && arr[k] == arr[k-1]) k--;
                    
                    
                }
            }
        }
        return ans;
    }
};