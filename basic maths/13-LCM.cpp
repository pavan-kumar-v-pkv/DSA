#include<bits/stdc++.h>
using namespace std;
// Function to count the number of digits in a number

class Solution {
public:
    int GCD(int n1,int n2) {
        int largest = 1;
        int mini = min(n1, n2);

        for(int i=mini;i>=1;i--){
            if(n1%i==0 && n2%i==0)
                return i;
        }
        return largest;
    }
    int LCM(int n1,int n2) {
        int gcd = GCD(n1, n2);
        return (n1*n2)/gcd;
    }
};