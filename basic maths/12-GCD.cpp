#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(min(N1, N2)) – where N1 and N2 are given numbers. Iterating from 1 to min(N1, N2) and performing constant time operations in each iteration.
// Space Complexity: O(1) – Using a couple of variables i.e., constant space.
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
    // Using Euclidean Algorithm
    // time
    int GCD2(int n1, int n2){
        while(n1!=0 && n2!=0){
            if(n1 > n2)
                n1 = n1 - n2;
            else
                n2 = n2 - n1;
        }
        if(n1 == 0)
            return n2;
        else
            return n1;
    }
    // Using Euclidean Algorithm with modulo
    // time: O(log(min(N1, N2)))
    // space: O(1)
    int GCD3(int n1, int n2){
        while(n1!=0 && n2!=0){
            if(n1 > n2)
                n1 = n1 % n2;
            else
                n2 = n2 % n1;
        }
        if(n1 == 0)
            return n2;
        else
            return n1;
    }
};