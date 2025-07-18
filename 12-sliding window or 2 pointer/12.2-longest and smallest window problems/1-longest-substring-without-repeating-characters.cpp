// Given a string, S. Find the length of the longest substring without repeating
// characters.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2) where N is the length of the string
// space: O(256) for storing all the characters
int longestNonRepeatingSubstring(string &s){
    int n = s.size();
    int maxLen = 0;

    for(int i=0;i<n;i++){
        // hash to track characters in the current window
        vector<int> hash(256, 0);
        for(int j=i;j<n;j++){
            if(hash[s[j]] == 1) break; // if character is already present, break the loop
            int len = j-i+1; // calculate the length of the current substring
            maxLen = max(maxLen, len); // update the maximum length
        }
    }
    return maxLen;
}

// optimal approach using sliding window technique
// time: O(N) where N is the length of the string
// space: O(256) for storing all the characters
int longestNonRepeatingSubstringOptimal(string &s){
    int n = s.size();
    int hash[256] = {-1};

    int l=0, r=0, maxLen = 0;
    while(r < n){
        // if current character s[r] is already in the substring
        if(hash[s[r]] != 0){
            // move the left pointer to the right of the last occurence of s[r]
            l = max(l, hash[s[r]]+1);
        }
        int len = r-l+1; // calculate the length of the current substring
        maxLen = max(maxLen, len);
        hash[s[r]] = r; // update the last occurence of s[r]
        r++;
    }
    return maxLen; // return the maximum length found
}
