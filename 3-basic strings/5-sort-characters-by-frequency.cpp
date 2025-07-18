#include<bits/stdc++.h>
using namespace std;

static bool comp(pair<char, int> a, pair<char, int> b){
    return a.second > b.second; // sort in descending order of frequency
    // if frequencies are equal, sort by character
    if(a.second == b.second)
        return a.first < b.first; // sort in ascending order of character
    return false;
}

vector<char> sortByFrequency(string s){
    unordered_map<char, int> freq;

    // count frequency of each character
    for(char c: s){
        freq[c]++;
    }
    // move into a vector of pairs
    vector<pair<char, int> > charFreq(freq.begin(), freq.end());

    // sort the vector based on frequency
    sort(charFreq.begin(), charFreq.end(), comp);

    vector<char> result;
    for(auto& p : charFreq){
        result.push_back(p.first);
    }

    return result;
}