// Given an integer array nums of size n, sorted in ascending order with distinct
// values. The array has been right rotated an unknown number of times, between 0
// and n-1 (including). Determine the number of rotations performed on the array.
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// Time Complexity: O(N)
// Space Complexity: O(1)
int findKRotations(vector<int> &arr)
{
    int n = arr.size();
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < ans)
        {
            ans = arr[i];
            index = i;
        }
    }
    return index;
}

// binary search approach
// Time Complexity: O(log N)
// Space Complexity: O(1)
// using the same logic as finding the minimum element in a rotated sorted array
int findKRotations2(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX, index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            // array is not rotated and sorted
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
                break; // exit the loop as we found the minimum
            }
        }
        if (arr[low] <= arr[mid])
        {
            // left part is sorted
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            // eliminate left half and look right
            low = mid + 1;
        }
        else
        {
            // right half is sorted
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            // eliminate right half and look left
            high = mid - 1;
        }
    }
    return index;
}