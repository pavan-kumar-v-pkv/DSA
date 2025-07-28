// Given a circular integer array arr, return the next greater element for every 
// element in arr.
// The next greater element for an element x is the first element greater than 
// x that we come across while traversing the array in a clockwise manner.
// If it doesn't exist, return -1 for that element element.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2), where N is the size of the array, using 2 nested for loops to find the NGE
// space: O(N), the space required to store the answer is O(N)
vector<int> nextGreaterElement(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n, -1);

    for(int i=0;i<n;i++){
        int currEle = arr[i];
        for(int j=1;j<n;j++){
            // getting the hypothetical index
            int ind = (j+i) % n;
            // if the next greater element is found
            if(arr[ind] > currEle){
                arr[i] = arr[ind];
                break;
            }
        }
    }
    return ans;
}

// optimal approach using monotonic stack
// Time Complexity: O(N) (where N is the size of the array)
// Traversing on the array takes O(N) time and traversing the stack will take overall O(N) time as all the elements are pushed in the stack once.

// Space Complexity: O(N)
// The answer array takes O(N) space and the space used by stack will be O(N) in the worst case.

vector<int> nextGreaterElements(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=2*n-1;i>=0;i--){
        // get the actual index
        int ind = i%n;
        // get the current element
        int currEle = arr[ind];
        // pop the elements in the stack until the stack is not empty
        // and the top element is not the greater element
        while(!st.empty() && st.top() <= currEle){
            st.pop();
        }

        // store the answer second half
        if(i < n){
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
        }
        st.push(currEle);
    }
    return ans;
}

