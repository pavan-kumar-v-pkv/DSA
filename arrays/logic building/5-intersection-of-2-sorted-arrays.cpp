// Given two sorted arrays, nums1 and nums2, 
//return an array containing the intersection of these two arrays.
// Each element in the result must appear as many times as it appears in both arrays.
// The intersection of two arrays is an array where all values are present in both arrays.

#include <bits/stdc++.h>
using namespace std;    

class Solution{
    public:
    // time: O(N*M), where N and M are the sizes of nums1 and nums2 respectively.
    // space: O(N), where N is the size of the nums2 array.
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        vector<int> visited(nums2.size(), 0);

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                // if nums1[i] is equal to nums2[j] and nums2[j] is not visited
                // then add nums2[j] in ans and mark nums2[j] as visited
                if(nums1[i] == nums2[j] && !visited[j]){
                    ans.push_back(nums2[j]);
                    visited[j] = 1;
                    break; // break the inner loop to avoid duplicates in ans
                }
                else if(nums1[i] < nums2[j]){
                    break; // since both arrays are sorted, we can break the loop
                }
            }
        }
        return ans;
    }

    // optimized version
    vector<int> intersectionArray2(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        int i=0, j=0;
         
        while(i < nums1.size() && nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{ //nums1[i] == nums2[j]
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};