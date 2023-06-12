#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

class Solution {
public:
    // Bidirectional BFS
    // Two simultaneous BFS. We progress one node at a time from both size and at any point in time 
    // if we find a common node in both the search, we stop the search.
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> head, tail, *phead, *ptail;
        if (!dict.count(endWord)) return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int res = 2;
        while (!head.empty() && !tail.empty()) {
            // interleave forward pass and backward pass
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }

            unordered_set<string> tmp;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string word = *it;
                for (int i = 0; i < word.size(); i++) {
                    char c = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        // termination: word seen by the parallel search
                        if (ptail->count(word)) return res;
                        if (dict.count(word)) {
                            tmp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = c;
                }
            }

            res++;
            phead->swap(tmp);
        }

        return 0;
    }

    // BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int L = beginWord.length();
        while (!q.empty()) {
            pair<string, int> curr = q.front();
            string word = curr.first;
            int depth = curr.second;
            q.pop();

            if (word == endWord) return depth;

            dict.erase(word); 
            for (int i = 0; i < L; i++) {
                char c = word[i];
                for (int j = 0; j < 26; j++) {
                    word[i] = 'a' + j;
                    if (dict.count(word)) q.push({word, depth+1});
                }
                word[i] = c;
            }
        }

        return 0;
    }
};