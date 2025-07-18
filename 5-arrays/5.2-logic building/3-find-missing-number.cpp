#include<bits/stdc++.h>
using namespace std;
// Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.

class Solution {
    int missingNumber(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<=n;i++){
            // flag to check if an element is found
            bool flag = false;
            // use linear search
            for(int j=0;j<n;j++){
                if(nums[j] == i){
                    flag = true; // element found
                    break;
                }
            }
            // if the element is not found, return it
            if(!flag){
                return i;
            }
        }
        return -1; // should never reach here if input is valid
    }
    // time: O(N) + O(N) = O(N)
    // space: O(N) for the frequency array
    int missingNumber2(vector<int>& nums){
        int n = nums.size();
        vector<int> freq(n+1, 0); // frequency array to track presence of numbers
        for(int num : nums){
            freq[num] = 1; // mark the number as present
        }
        for(int i=0;i<=n;i++){
            if(freq[i] == 0){
                return i;
            }
        }
        return -1;
    }
    // optimal approach
    int missingNumber3(vector<int>& nums){
        int n = nums.size();
        int sum1 = (n * (n + 1)) / 2; // sum of first n natural numbers
        int sum2 = 0; // sum of elements in the array
        for(int num : nums){
            sum2 += num;
        }
        int missingNum = sum1 - sum2; // the missing number is the difference between the two sums
        return missingNum;
    }
    // optimal approach using XOR
    int missingNumber4(vector<int>& nums){
        int xor1 = 0, xor2 = 0;

        for(int i=0;i<nums.size();i++){
            xor1 ^= nums[i];
            xor2 ^= (i+1);
        }
        return (xor1^xor2);
    }
};
