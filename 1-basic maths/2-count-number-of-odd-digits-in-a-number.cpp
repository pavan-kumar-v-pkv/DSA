#include<bits/stdc++.h>
using namespace std;

// time: O(digits of n)
// space: O(1)
class Solution {
public:
    int countOddDigit(int n) {
        int cnt = 0;
        while(n > 0){
            int lastDigit = n%10;
            if(lastDigit%2 == 1)
                cnt++;
            n /= 10;
        }
        return cnt;
    }
};