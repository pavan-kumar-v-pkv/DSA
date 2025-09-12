// Given two distinct words startWord and targetWord, and a list denoting 
// wordList of unique words of equal lengths. Find all shortest transformation 
// sequence(s) from startWord to targetWord. You can return them in any order 
// possible.
// In this problem statement, we need to keep the following conditions in mind:
// * A word can only consist of lowercase characters.
// * Only one letter can be changed in each transformation.
// * Each transformed word must exist in the wordList including the targetWord.
// * startWord may or may not be part of the wordList.
// * Return an empty list if there is no such transformation sequence.
#include<bits/stdc++.h>
using namespace std;

// time: O(N*M*26)
// space: O(N*M)
class Solution{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList){
        vector<vector<string>> ans;
        // queue to store sequences of tranformations
        queue<vector<string>> q;
        // add all the words to a hashset
        unordered_set<string> st(wordList.begin(), wordList.end());

        // add the sequence containing starting word to queue
        q.push({beginWord});
        // erase starting word from set if it exists
        st.erase(beginWord);
        // set to store the words that must be deleted after traversal of a level is complete
        unordered_set<string> toErase;

        // until the queue is empty
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                // sequence
                vector<string> seq = q.front();
                // last added word in sequence
                string word = seq.back();
                q.pop();

                // if the last word is same as end word
                if(word == endWord){
                    // add the sequence to the answer
                    if(ans.empty()){
                        ans.push_back(seq);
                    }
                    else if(ans.back().size() == seq.size()){
                        ans.push_back(seq);
                    }
                }

                // iterate on every character
                for(int pos=0;pos<word.length();pos++){
                    char orig = word[pos];
                    for(char ch='a';ch<='z';ch++){
                        word[pos] = ch;
                        if(st.find(word) != st.end()){
                            seq.push_back(word);
                            q.push(seq);
                            toErase.insert(word);
                            // backtracking step
                            seq.pop_back();
                        }
                    }
                    // update the original letter back
                    word[pos] = orig;
                }
            }
            // erase all the words in set after traversal of a level is completed
            for(auto it: toErase) st.erase(it);
            toErase.clear();
            // if answer is found, break
            if(!ans.empty())
                break;
        }
        return ans;
    }
};