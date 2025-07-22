// Given a string nums representing a non-negative integer, and an integer k, 
// find the smallest possible integer after removing k digits from num.
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) (where N is the length of the given number)
// Traversing the given string takes O(N) time.
// Each element is pushed onto and popped from the stack at most once in worst-case taking o(N) time.
// Removing the remaining digits (if k > 0) takes O(k) time which can go upto O(N) in worst-case.
// Forming the result, trimming the zeros and reversing the digits takes O(N) time.

// Space Complexity: O(N)
// The stack space can be O(N) in the worst-case.
// The space required to store the result is O(N) in worst-case.

string removeKdigits(string nums, int k){
    stack<char> st;

    for(int i=0;i<nums.size();i++){
        // current digit
        char digit = nums[i];
        // pop last digits (when possible), if a smaller digit is found
        while(!st.empty() && k > 0 && st.top() > digit){
            st.pop();
            k--;
        }
        // push the current digit
        st.push(digit);
    }

    // if more digits can be removed
    while(!st.empty() && k > 0){
        st.pop();
        k--;
    }

    // handling edge cases, if K == N, where N is the length of the given string
    if(st.empty())
        return "0";

    string res = "";
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    // trimming the zeros at the back
    while(res.size() > 0 && res.back() == '0'){
        res.pop_back();
    }
    // reverse to get the actual number
    reverse(res.begin(), res.end());
    // edge case
    if(res.empty())
        return "0";

    return res;
}
