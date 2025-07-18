#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log10(N)) – N is being divided by 10 until it becomes zero resulting in log10(N) iterations and in each iteration constant time operations are performed.
// Space Complexity: O(1) – Using a couple of variables i.e., constant space, regardless of the size of the input.
class Solution {
public:
    bool isArmstrong(int n) {
        int sum = 0;
        int cnt = log10(n)+1;
        int temp = n;
        while(n > 0){
            int lastDigit = n%10;
            sum += pow(lastDigit, cnt);
            n /= 10;
        }
        return sum==temp;
    }
};