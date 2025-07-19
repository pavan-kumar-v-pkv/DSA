// Given two strings s and t. Find the smallest window substring of s that 
// includes all characters in t (including duplicates) , in the window. Return 
// the empty string "" if no such substring exists.
#include<bits/stdc++.h>
using namespace std;

// time: O(n^2) where n is the size of the string, the outer loop runs for n time 
// and for each character the inner loop also runs for n times
// space: O(256), hash array to store frequency of all characters
string minWindow(string s, string t){
    int minLen = INT_MAX;
    int sIndex = -1;

    for(int i=0;i<s.size();i++){
        int hash[256] = {0};

        // count the frequencies of characters in t.
        for(char c: t){
            hash[c]++;
        }
        int cnt = 0;
        // iterate through the current window
        for(int j=i;j<s.size();j++){
            if(hash[s[j]] > 0){
                cnt++;
            }
            hash[s[j]]--;
            // if all characters from t are found in currrent window
            if(cnt == t.size()){
                if(j-i+1<minLen){
                    minLen = j-i+1;
                    sIndex = i;
                }
                break;
            }
        }
    }
    return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
}

// optimal approach using sliding window and 2 pointers
// time: O(2N + M), where N is the size of string s and M is the size of the string t
// space: O(256), hash array ti store frequency of all the characters
string minWindow2(string s, string t){
    int minLen = INT_MAX;
    int sIndex = -1;
    int hash[256] = {0};

    for(char c : t){
        hash[c]++;
    }
    int cnt = 0;
    int l = 0, r = 0;

    while(r < s.size()){
        if(hash[s[r]] > 0){
            cnt++;
        }
        hash[s[r]]--;

        // if all the characters from t are found in current window
        while (cnt == t.size()){
            if(r-l+1 < minLen){
                minLen = r-l+1;
                sIndex = l;
            }
            // remove the leftmost character from window
            hash[s[l]]++;
            if(hash[s[l]] > 0){
                cnt--;
            }
            l++;
        }
        r++;
    }
    return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
}


