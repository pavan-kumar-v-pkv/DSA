// Given an array of non-negative integers, height representing the elevation 
// of ground. Calculate the amount of water that can be trapped after rain.
#include<bits/stdc++.h>
using namespace std;

// brute force approach
// Time Complexity: O(N) (where N is the size of given array)
// Calculating the Prefix and Suffix Maximum Arrays take O(N) time each.
// Traversing on the given array once takes O(N) time.

// Space Complexity: O(N)
// Storing the Prefix and Suffix Maximum Arrays takes O(N) space each.
vector<int> findPrefixMax(vector<int>& arr, int n){
    vector<int> prefixMax(n);
    prefixMax[0] = arr[0];

    for(int i=0;i<n;i++){
        prefixMax[i] = max(prefixMax[i-1], arr[i]);
    }
    return prefixMax;
}
vector<int> findSuffixMax(vector<int>& arr, int n){
    vector<int> suffixMax(n);
    suffixMax[n-1] = arr[n-1];

    for(int i=n-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i+1], arr[i]);
    }
    return suffixMax;
}
int trap(vector<int>& height){
    int n = height.size();
    // to store the total trapped rainwater
    int total = 0;
    // calcaulate prefix maximum array and suffix maximum array
    vector<int> leftMax = findPrefixMax(height, n);
    vector<int> rightMax = findSuffixMax(height, n);

    for(int i=0;i<n;i++){
        // if there are higher grounds on both sides to hold water
        if(height[i] < leftMax[i] && height[i] < rightMax[i]){
            // add up the water on top of current height
            total += (min(leftMax[i], rightMax[i]) - height[i]);
        }
    }
    return total;
}

// Intuition:
// In earlier solution, storing the prefix and suffix maximums was taking extra 
// space. However, at a particular height, only the minimum height (out of the 
// left maximum height and right maximum height) was considered. This simply 
// means that at a particular moment either the left maximum height or the 
// right maximum height was useful.

// Understanding:
// It is impossible to find out the left and right barriers beforehand, but a 
// clever way to traverse the array is by traversing it from both ends. The 
// left and right maximum heights (barriers) can be maintained and based on 
// these values the water on top of current height can be calculated using the 
// formula:
//         water = min(leftMax, rightMax) - height,
// where height is the height of current ground.
// This gives an idea of using two pointers that start from both ends of the 
// array while maintaining the left and right barriers (maximum heights). Since,
// only the lower barrier (minimum height) is considered, out of the two 
// pointers, only one (having minimum height) will move at a time which ensures 
// that no potential taller height is missed.

// optimal approach using 2 pointers
// time: O(N) (where N is the size of given array)
// The left and right pointers will traverse the whole array in total taking O(N) time.

// Space Complexity: O(1)
// Using only a couple of variables.
int trap2(vector<int>& height){
    int n = height.size();
    int total = 0;

    // to store the maximums on both sides
    int leftMax = 0, rightMax = 0;
    // left and right pointers
    int left = 0, right = n-1;

    while(left < right){
        // if the left height is smaller or equal
        if(height[left] <= height[right]){
            // if water can be stored
            if(leftMax > height[left]){
                // update total water
                total += leftMax - height[left];
            }
            else{
                // update maximum height on left
                leftMax = height[left];
            }
            left = left + 1;
        }
        else{
            // else if the right height is smaller
            if(rightMax > height[right]){
                total += rightMax - height[right];
            }
            else{
                rightMax = height[right];
            }
            right = right - 1;
        }
    }
    return total;
}