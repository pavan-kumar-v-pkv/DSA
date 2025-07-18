// Given a string s and an integer k.Find the length of the longest substring 
// with at most k distinct characters.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2) where N is the length of the string
// space: O(1) for constant space usage
int kDistinctCharacters(string s, int k){
    int maxlen = 0;
    int n = s.size();
    unordered_map<char, int> mpp;

    for(int i=0;i<n;i++){
        mpp.clear();
        for(int j=i;j<n;j++){
            mpp[s[j]]++;

            if(mpp.size() <= k){
                maxlen = max(maxlen, j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxlen;
}

// time: O(2N), where N is the size of the array
// space: O(k), as at most the map data structure is holding k+1 elements
int kDistinctChar2(string& s, int k){
    int l = 0, r = 0, maxlen = 0;
    int n = s.size();
    unordered_map<char, int> mpp;

    while(r < n){
        mpp[s[r]]++;

        while(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l++;
        }

        if(mpp.size() <= k)
            maxlen = max(maxlen, r-l+1);

        r++;
    }
    return maxlen;
}

// optimal approach
// time: O(N) where N is the size of the array
// space: O(k) as at most the map data structure is holding k elements.
int kDistinctChar(string& s, int k){
    int n = s.size();
    int l = 0, r = 0, maxlen = 0;
    unordered_map<char, int> mpp;

    while(r < n){
        mpp[s[r]]++;

        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0)
                mpp.erase(s[l]);
            l++;
        }

        if(mpp.size() <= k)
            maxlen = max(maxlen, r-l+1);

        r++;
    }
    return maxlen;
}


