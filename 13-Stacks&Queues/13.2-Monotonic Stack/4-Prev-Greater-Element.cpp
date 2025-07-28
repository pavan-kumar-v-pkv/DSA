#include<bits/stdc++.h>
using namespace std;

vector<int> prevGreater(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i=0;i<n;i++){
        int currEle = arr[i];
        // pop all elements smaller than or equal to current element
        while(!st.empty() && st.top() <= currEle)
            st.pop();

        // if stack is not empty, top is the previous greater element
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(currEle);
    }
    return ans;
}