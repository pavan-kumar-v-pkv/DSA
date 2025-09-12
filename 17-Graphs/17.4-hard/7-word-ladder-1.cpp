// Given are the two distinct words startWord and targetWord, and a list of 
// size N, denoting wordList of unique words of equal size M. Find the length 
// of the shortest transformation sequence from startWord to targetWord.

// Keep the following conditions in mind:
// * A word can only consist of lowercase characters.
// * Only one letter can be changed in each transformation.
// * Each transformed word must exist in the wordList including the targetWord.
// * startWord may or may not be part of the wordList

// Note: If there’s no possible way to transform the sequence from startWord 
// to targetWord return 0.
#include<bits/stdc++.h>
using namespace std;

// how is this a graph problem ?
// beginWord = "hit"  
// endWord   = "cog"  
// wordList  = ["hot","dot","dog","lot","log","cog"]  

// Output: 5  
// (hit → hot → dot → dog → cog)
// Think of each word as a node (vertex) in a graph.
// There is an edge between two words if they differ by exactly one letter.
// So in the above example:
// * "hit" is connected to "hot"
// * "hot" is connected to "dot" and "lot"
// * "dot" is connected to "dog", etc.
// Once you model it this way, the problem becomes:
// 👉 Find the shortest path in an unweighted graph from beginWord to endWord.

// What Graph Algorithm to use?
// Since edges are unweighted (changing one letter has the same cost), the correct choice is:
// *Breadth-First Search (BFS)
// BFS ensures that the first time you reach the endWord, it’s via the shortest path (minimum transformations).

// time: O(N*M*26)
// space: O(N)
class Solution{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList){
        // queue to store pair {"word", steps to reach reach that "word"}
        queue<pair<string, int>> q;

        // add the starting word to queue
        q.push({startWord, 1});

        // add all the words to a hashset
        unordered_set<string> st(wordList.begin(), wordList.end());
        // if target word is not there in word list, return 0 as it is not possible to transform
        if(st.find(targetWord) == st.end())
            return 0;

        // erase the starting word from set (if it exists)
        st.erase(startWord);

        while(!q.empty()){
            // get the word form queue
            string word = q.front().first;
            // get the steps from queue
            int steps = q.front().second;
            q.pop();

            // reuturn steps if target word is achieved
            if(word == targetWord)
                return steps;

            // iterate on every character
            for(int i=0;i<word.size();i++){
                // store the orginal letter
                char original = word[i];
                // replacing current character with letter from 'a' to 'z' to
                // match any possible word from set
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    // check if it exists in the set
                    if(st.find(word) != st.end()){
                        //erase the word from set
                        st.erase(word);
                        // add the transition to the queue
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};