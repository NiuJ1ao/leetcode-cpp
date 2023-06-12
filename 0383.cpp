#include <string>
#include <unordered_map>
using namespace std;

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Initialize an array of count with the size 26...
        int counter[26] = {0};
        // Traverse a loop through the entire String of magazine where char ch stores the char at the index of magazine...
        for(char ch : magazine)
            counter[ch - 'a']++;
        // Run another for loop for ransomNote...
        for(char ch : ransomNote)
            // If the charachter doesn't exists in magazine for ransomNote, we return false...
            if(counter[ch - 'a']-- <= 0)
                return false;
        return true;        // If nothing goes wrong, return true...
    }
    
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (char c: magazine) {
            mp[c]++;
        }

        for (char c: ransomNote) {
            if (--mp[c] < 0) return false;
        }

        return true;
    }
};
