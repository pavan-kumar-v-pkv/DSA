#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isomorphicString(string s, string t) {
    	if(s.length() != t.length()) return false;
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for(int i=0;i<s.size();++i){
            char c1 = s[i], c2 = t[i];
            // check if mapping already exists and is consistent
            if((mapST.count(c1) && mapST[c1] != c2) ||
               (mapTS.count(c2) && mapTS[c2] != c1)) {
                return false;
            }
            // create the mapping if it doesn't exist
            mapST[c1] = c2;
            mapTS[c2] = c1;
        }
        return true;

        
    }
};