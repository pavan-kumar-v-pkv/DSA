// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string longestCommonPrefix(vector<string>& str){
		if(str.empty()) return "";
        // sort the strings in ascending order
        sort(str.begin(), str.end());
        string first = str[0];
        string last = str[str.size()-1];
        int minLength = min(first.length(), last.length());
        string ans = "";
        for(int i=0;i<minLength;i++){
            if(first[i] != last[i])
                return ans;
            ans += first[i];
        }
        return ans;

	}
};

// int main(){
//     Solution solution;
//     vector<string> input = {"flower", "flow", "flight"};
//     string result = solution.longestCommonPrefix(input);
//     cout << "Longest Common Prefix: " << result << endl;
//     return 0;
// }