// Given an array arr of size n containing elements, find the next greater 
// element for each element in the array in the order of their appearance.
// The next greater element of an element in the array is the nearest element 
// on the right that is greater than the current element.
// If there does not exist a next greater element for the current element, then
// the next greater element for that element is -1.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// time: O(N^2) where N is the size of the array, using nested loop to find the next grrater elements
// space: O(N),  the space required to store the answer is O(N) 
vector<int> nextGreaterElement(vector<int>& arr){
    int n = arr.size();

    vector<int> ans(n, -1);

    for(int i=0;i<n;i++){
        // get the current element
        int curEle = arr[i];
        // nested loop to get the next greater element
        for(int j=i+1;j<n;j++){
            // if the next greater element is found
            if(arr[j] > curEle){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

// optimal approach using monotonic stack
// In order to obtain the next greater element (which will always be on the 
// right side) for a particular element, if we traverse the array from the 
// beginning to the end, it is impossible to know the right elements beforehand
// as they will be unvisited. But if the traversal is done from the end to the 
// beginning of array, it will be easier to find the next greater element cause 
// all the right elements will be already visited(known) to us. Thus, we will 
// start the traversal from back and the whole discussion will be based on the 
// same.

// time: O(N), (where N is the size of the array)
// Traversing on the hypothetical array takes O(2N) time and traversing the stack will take overall O(2N) time as all the elements are pushed in the stack once.

// space: O(N), The answer array takes O(N) space and the space used by stack will be O(N) in the worst case.

vector<int> nextGreaterElement2(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        // get the current element
        int currEle = arr[i];
        // pop the elements in the stack until the stack is not empty and
        // the top element is not the greater element
        while(!st.empty() && st.top() <= currEle){
            st.pop();
        }

        // if the greater element is not found, stack will be empty
        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        // push the current element in the stack maintaining the decreasing order
        st.push(currEle);
    }
    return ans;
}