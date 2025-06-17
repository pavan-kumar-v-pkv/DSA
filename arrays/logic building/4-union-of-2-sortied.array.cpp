// Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays.
// The elements in the union must be in ascending order.
// The union of two arrays is an array where all values are distinct and are present in either the first array,
// the second array, or both.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time: O((N+M)log(N+M)), where N and M are the sizes of nums1 and nums2 respectively.
    // space: O(N+M), where N and M are the sizes of nums1
    vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s;
        vector<int> result;
        for (int num : nums1)
        {
            s.insert(num);
        }
        for (int num : nums2)
        {
            s.insert(num);
        }
        for (int num : s)
        {
            result.push_back(num);
        }
        return result;
    }
    // optimized version
    vector<int> unionArray2(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        vector<int> result;
        int n = nums1.size();
        int m = nums2.size();

        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                if(result.empty() || result.back() != nums1[i])
                    result.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                if(result.empty() || result.back() != nums2[j])
                    result.push_back(nums2[j]);
                j++;
            }
            else{ // nums1[i] == nums2[j]
                if(result.empty() || result.back() != nums1[i])
                    result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        while(i < n){
            if(result.empty() || result.back() != nums1[i])
                result.push_back(nums1[i]);
            i++;
        }
        while(j < m){
            if(result.empty() || result.back() != nums2[j])
                result.push_back(nums2[j]);
            j++;
        }
        return result;
    }
};
