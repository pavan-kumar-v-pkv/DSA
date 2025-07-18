// Given an integer k and a string s, any character in the string can be 
// selected and changed to any other uppercase English character. This 
// operation can be performed up to k times. After completing these steps, 
// return the length of the longest substring that contains the same letter.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N2), where N is the size of the array. Iterating the array twice using two for loops.
// Space Complexity: O(26) . Hash array to store the frequencies of the capital letters.
int characterReplacement(string s, int k){
    int maxlen = 0;
    // variable to track the maximum frequency of any
    // single character in the current window
    int maxFreq = 0;

    for(int i=0;i<s.size();i++){
        int hash[26] = {0};
        for(int j=i;j<s.size();j++){
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            // calculate the number of changes needed to make
            int changes = (j-i+i) - maxFreq;
            if(changes <= k){
                maxlen = max(maxlen, j-i+1);
            }
            else break;
        }
    }
    return maxlen;
}

// better approach using sliding window 2 pointers
// time: O((N+N) * 26), where N is the size of the array. 
// The right pointer runs for N times and the left pointer runs for N times throughout. The for loop takes extra O(26) to claculate the maximum frequency.
// Space Complexity: O(26) . Hash array to store all the characters.
int characterReplacement2(string s, int k){
    int maxlen = 0;
    int maxFreq = 0;
    int l = 0, r = 0;
    int hash[26] = {0};

    while(r < s.size()){
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r]]-'A');

        while((r-l-1)-maxFreq > k){
            hash[s[l]-'A']--;
            // recalculate maxFreq for current window
            maxFreq = 0;
            for(int i=0;i<26;i++){
                maxFreq = max(maxFreq, hash[i]);
            }
            l++;
        }
        if((r-l+1) - maxFreq <= k)
            maxlen = max(maxlen, r-l+1);
        r++;
    }

    return maxlen;
}

// optimal approach using sliding window and 2 pointers
// Time Complexity:O(N), where N is the size of the array. The right pointer runs for N times.
// Space Complexity: O(26) . Hash array to store all the characters.
int characterReplacement3(string s, int k){
    int maxlen = 0;
    int maxFreq = 0;
    int l = 0, r = 0;
    int hash[26] = {0};

    while(r < s.size()){
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq, hash[s[r]]-'A');

        if((r-l+1) - maxFreq > k){
            hash[s[l]-'A']--;
            l++;
        }
        if((r-l+1) - maxFreq <= k)
            maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}

