#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) – Iterating N times, and performing constant time operations in each pass.
// Space Complexity: O(sqrt(N)) – A number N can have at max 2*sqrt(N) divisors, which are stored in the array.
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(n%i==0)
                ans.push_back(i);
        }
        return ans;
    }
};




