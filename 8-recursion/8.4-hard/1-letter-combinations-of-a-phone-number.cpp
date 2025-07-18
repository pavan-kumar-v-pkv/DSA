// Given a string consisting of digits from 2 to 9 (inclusive). Return all 
// possible letter combinations that the number can represent.
// Mapping of digits to letters is given in first example.
#include<bits/stdc++.h>
using namespace std;    

// Function to find all possible letter combinations for a given digit string4
// time: O(4^n) where n is the length of the digit string, as each digit can map to 3 or 4 letters
// space: O(n) for the recursion stack and storing the current combination
void func(int ind, string digits, string s, vector<string>& ans, string combos[]){
    // base case: if index reaches the end of digits
    if(ind == digits.size()){
        ans.push_back(s);
        return;
    }
    // convert the current character to an integer
    int num = digits[ind] - '0';
    // iterate through the characters corresponding to the current digit
    for(int i=0;i<combos[num].size();i++){
        // recursively call function with next index 
        // add current character to the string
        s.push_back(combos[num][i]);
        func(ind+1, digits, s, ans, combos);
        // backtrack: remove the last character from the string
        s.pop_back();
    }
}
vector<string> letterCombination(string digits){
    // mapping digits to corresponding characters
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string s = "";
    func(0, digits, s, ans, combos);
    return ans;
}