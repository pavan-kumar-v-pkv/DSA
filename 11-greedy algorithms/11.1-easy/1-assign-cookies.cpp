// Consider a scenario where a teacher wants to distribute cookies to students, 
// with each student receiving at most one cookie.
// Given two arrays, Student and Cookie, the ith value in the Student array 
// describes the minimum size of cookie that the ith student can be assigned. 
// The jth value in the Cookie array represents the size of the jth cookie. If 
// Cookie[j] >= Student[i], the jth cookie can be assigned to the ith student. 
// Maximize the number of students assigned with cookies and output the maximum 
// number.
#include<bits/stdc++.h>
using namespace std;

// time: O(NlogN + MlogM + M) where N is the lngth of student arrat and M is the length of cookies array
// space: O(1) since we are using a constant amount of extra space
int findMaximumCookies(vector<int>& students, vector<int>& cookies){
    int n = students.size();
    int m = cookies.size();

    int l=0, r=0;
    sort(students.begin(), students.end());
    sort(cookies.begin(), cookies.end());

    while(l < n && r < m){
        // if the current cookies can satisfy the current student, move to the next student
        if(cookies[r] >= students[l]){
            l++;
        }
        r++;
    }
    return l; // l will be the count of students who got cookies
}