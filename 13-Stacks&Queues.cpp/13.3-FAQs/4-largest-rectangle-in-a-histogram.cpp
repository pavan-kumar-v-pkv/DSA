// Given an array of integers heights representing the histogram's bar height 
// where the width of each bar is 1 return the area of the largest rectangle in 
// the histogram.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// https://takeuforward.org/plus/dsa/stack-and-queues/faqs/largest-rectangle-in-a-histogram?tab=editorial
// time: O(5N) ~ O(N) (where N is the size of the given array)
// Precomputing PSE and NSE arrays take O(2N) time each.
// Traversing the given histogram once to find the maximum area takes O(N) time.

// Space Complexity: O(N)
// Finding the PSE and NSE arrays uses stack that takes O(N) space each.
// Storing the PSE and NSE arrays take O(N) space each.
vector<int> findNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        arr[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}
vector<int> findPSE(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1;
        // push the index of current element in the stack
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights){
    // determine the next and previous smaller elements
    vector<int> nse = findNSE(heights);
    vector<int> pse = findPSE(heights);

    int largestArea = 0;
    // to store the current area
    int area;

    for(int i=0;i<heights.size();i++){
        // calculate the current area
        area = heights[i] * (nse[i]-pse[i]-1);
        // update the largest area
        largestArea = max(largestArea, area);
    }
    return largestArea;
}

// optimal approach
// In the earlier solution, precomputing the PSE and NSE arrays was contributing to 
// multiple traversals. This can be avoided by finding the PSE on the go. But the 
// question of finding the NSE still remains.

// Handling remaining bars:
// Since the areas of only those rectangles are considered that are popped from the
// stack, to ensure all the possible heights are considered for areas, all the 
// elements must be popped from the stack even after the traversal of the array is 
// complete. For such elements (that remain in the stack after traversal), the index
// of the next smaller element will be set to the size of the array, as there is no 
// next smaller element.

// time: Complexity Analysis:
// Time Complexity: O(N) (where N is the size of the given array)
// Traversing all the elements of array takes O(N) time.
// All the elements are pushed in and popped out from the stack once taking O(N) time.

// Space Complexity: O(N)
// The stack space used to find the previous smaller element during traversal can go up to O(N).
int largestRectangleArea2(vector<int>& heights){
    int n = heights.size();
    stack<int> st;
    int largestArea = 0;
    int area;

    // to store the indices of next and previous smaller element
    int nse, pse;

    for(int i=0;i<n;i++){
        // pop the elements in the stack until the stack is not wmpty
        // and the top elements are not the smaller element
        while(!st.empty() && heights[st.top()] >= heights[i]){
            // get the index of top of stack
            int ind = st.top();
            st.pop();

            // update the index of pse
            pse = st.empty() ? -1 : st.top();
            // nse index for the popped element is current index (i)
            nse = i;

            // calculate the area of popped element
            area = heights[ind] * (nse-pse-1);
            // update the maximum area
            largestArea = max(largestArea, area);
        }
        // push the current index to stack
        st.push(i);
    }

    while(!st.empty()){
        // NSE for such elements is size of the array
        nse = 0;
        // get the index of top of stack
        int ind = st.top();
        st.pop();

        // update pse
        pse = st.empty() ? -1 : st.top();
        area = heights[ind] *  (nse-pse-1);
        largestArea = max(largestArea, area);
    }
    return largestArea;
}