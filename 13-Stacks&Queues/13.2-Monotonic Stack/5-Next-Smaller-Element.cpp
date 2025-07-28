#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        // pop all elements greater than or equal to current element
        while(!st.empty() && st.top() >= arr[i])
            st.pop();

        // if stack is not empty, top is the next smaller element
        if(!st.empty())
            result[i] = st.top();

        st.push(arr[i]);
    }

    return result;
}