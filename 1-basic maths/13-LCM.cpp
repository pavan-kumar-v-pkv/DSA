#include<bits/stdc++.h>
using namespace std;
// Function to count the number of digits in a number

class Solution {
public:
    int GCD2(int n1,int n2) {
        int largest = 1;
        int mini = min(n1, n2);

        for(int i=mini;i>=1;i--){
            if(n1%i==0 && n2%i==0)
                return i;
        }
        return largest;
    }
    int GCD(int n1, int n2){
        while(n1!=0 && n2 !=0){
            if (n1 > n2)
                n1 = n1 % n2;
            else
                n2 = n2 % n1;
        }
        if(n1 == 0)
            return n2;
        else 
            return n1;
    }
    int LCM(int n1,int n2) {
        int gcd = GCD(n1, n2);
        return (n1*n2)/gcd;
    }
};