#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) – Iterating once from 1 to N.
// Space Complexity: O(1) – Using a couple of variables i.e., constant space.
class Solution {
public:
    int factorial(int n) {
        if(n == 1 || n == 0)
            return 1;

        int ans = 1;
        for(int i=1;i<=n;i++){
            ans *= i;
        }
        return ans;
    }
};
