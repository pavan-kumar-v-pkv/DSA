// Given an array nums of n integers, return the length of the longest sequence of consecutive integers. 
// The integers in this sequence can appear in any order.
#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

// brute force approach
// time: O(N^2), N=size of array
// space: O(1)
bool linearSearch(vector<int>& a, int num){
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>& a){
    int n = a.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        int cnt = 1; // count of consecutive elements
        int num = a[i];
        while(linearSearch(a, num+1)){
            cnt++;
            num++;
        }
        ans = max(ans, cnt);
    }
    return ans;
}

// better approach using sorting
// time: O(N log N)+O(N), N=size of array
// space: O(1), no extra space is used
int longestSuccessiveElements2(vector<int>& a){
    int n = a.size();
    if(n == 0) return 0;
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1; // at least one element is present
    for(int i=0;i<n;i++){
        if(a[i]-1 == lastSmaller){
            // a[i] is consecutive to the last element
            cnt += 1;
            lastSmaller = a[i];
        }
        else if(a[i] != lastSmaller){
            // a[i] is not consecutive to the last element
            cnt = 1; // reset count
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// optimal approach using hashing
// time: O(N), N=size of array
// space: O(N), where N is the number of elements in the array
int longestSuccessiveElements3(vector<int>& a){
    int n = a.size();
    if(n == 0) return 0;

    int longest = 1; // at least one element is present
    unordered_set<int> s(a.begin(), a.end()); // insert all elements in a set
    // find the longest consecutive sequence
    for(auto it: s){
        // if 'it' is a starting number of a sequence
        if(s.find(it-1) == s.end()){
            // find consecutive elements starting from 'it'
            int cnt = 1;
            int x = it;
            while(s.find(x+1) != s.end()){
                x = x+1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;

}

