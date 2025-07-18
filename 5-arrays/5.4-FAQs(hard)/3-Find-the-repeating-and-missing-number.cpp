// Given an integer array nums of size n containing values from [1, n] and 
// each value appears exactly once in the array, except for A, which appears 
// twice and B which is missing.
// Return the values A and B, as an array of size 2, where A appears in the 
// 0-th index and B in the 1st index.
#include<bits/stdc++.h>
using namespace std;    

// brute force approach
// time: O(N^2), where N is the number of elements in the array
// space: O(1), no extra space is used
vector<int> findMissingRepeatingNumbers(vector<int> a){
    int n = a.size();
    int repeating = -1, missing = -1;
    // find thr reapeating number and missing number
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(a[j] == i) cnt++;
        }

        if(cnt == 2) repeating = i;
        else if(cnt == 0) missing = i;

        if(repeating != -1 && missing != -1) break;
    }
    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}

// better approach using hashing
// time: O(2N), where N is the number of elements in the array
// space: O(N), where N is the number of elements in the array
vector<int> findMissingRpeatingNumbers2(vector<int> a){
    int n = a.size();
    vector<int> hash(n+1, 0); // hash array to track the frequency of numbers
    
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    // find the repeating and missing numbers
    int repeating = -1, missing = -1;
    for(int i=1;i<=n;i++){
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;

        if(repeating != -1 && missing != -1)
            break;
    }
    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}

// optimal approach using mathematical properties
// time: O(N), where N is the number of elements in the array
// space: O(1), no extra space is used
// Approach 
// First, find out the values of S and Sn, where S is the sum of all the elements of the array and Sn is the sum of natural numbers from 1 to N. Then calculate S - Sn and S - Sn = X - Y, 
// where X is repeating number and Y is the missing number.
// Next, find the values of S2 and S2n , where S2 is the summation of squares of all the elements in the given array and S2n is summation of squares of the first N numbers((N*(N+1)*(2N+1))/6). Then calculate S2 - S2n and S2 - S2n = X2 - Y2.
// From the above steps X+Y = (S2 - S2n) / (X-Y)
// After performing steps 1 and 2, we will be having the values of X + Y and X - Y. Now, by substitution of values, we can easily find the values of X and Y. Finally, return X and Y.
vector<int> findMissingRepeatingNumbers3(vector<int> a){
    long long n = a.size();
    // Find Sn and S2n
    long long Sn = (n * (n+1))/2;
    long long S2n = (n * (n+1) * (2*n+1)) / 6;
    // calculate S and S2
    long long S = 0, S2 = 0;
    for(int i=0;i<n;i++){
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    // S-Sn = X - Y
    long long val1 = S - Sn; // X - Y
    // S2 - S2n = x2 - Y2
    long long val2 = S2 - S2n;
    // X2 - Y2 = (X + Y)(X - Y)
    long long val3 = val2 / val1; // X + Y
    // Now we have val1 = X - Y and val3 = X + Y
    long long X = (val1 + val3) / 2; // repeating number
    long long Y = X - val1; // missing number
    vector<int> ans;
    ans.push_back(X);
    ans.push_back(Y);
    return ans;

}

// optimal approach using XOR
// time: O(N), where N is the number of elements in the array
// space: O(1), no extra space is used
// approach: https://takeuforward.org/plus/dsa/arrays/faqs-hard/find-the-repeating-and-missing-number?tab=editorial
vector<int> findMissingRepeatingNumbers4(vector<int> a){
    int n = a.size();
    int xr = 0;
    // step 1: find XOR of all elements
    for(int i=0;i<n;i++){
        xr = xr ^ a[i];
        xr = xr ^ (i+1);
    }
    // step 2: find the differentiating bit number
    int number = (xr & ~(xr - 1)); // rightmost set bit
    // step 3: group the elements based on the differentiating bit
    int zero = 0;
    int one = 0;
    for(int i=0;i<n;i++){
        // part of 1 group:
        if((a[i] & number) != 0){
            one = one ^ a[i];
        }
        // part of 0 group 
        else{
            zero = zero ^ a[i];
        }
    }   
    for(int i=0;i<n;i++){
        // part of 1 group:
        if((i+1 & number) != 0){
            one ^= (i+1);
        }
        else{
            zero = zero ^ (i+1);
        }
    }
    // last step: find the repeating and missing numbers
    vector<int> ans;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] == zero)cnt++;
    }
    if(cnt==2)
        ans.push_back(zero), ans.push_back(one);
    else
        ans.push_back(one), ans.push_back(zero);
    return ans;

}