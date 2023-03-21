#include <unordered_map>
#include <string>
using namespace std;

/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.
*/

class WordDictionary {
private:
    unordered_map<char, WordDictionary*> next = {};
    bool isword = false;

public:
    WordDictionary() {}
    
    void addWord(string word) {
        WordDictionary* x = this;
        for (char c: word) {
            if (!x->next.count(c)) {
                x->next[c] = new WordDictionary();
            }
            x = x->next[c];
        }
        x->isword = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0);
    }

    bool searchHelper(string word, int idx) {
        WordDictionary* x = this;
        for (int i = idx; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto it = x->next.begin(); it != x->next.end(); it++) {
                    if (it->second->searchHelper(word, i + 1)) return true;
                }
                return false;
            } else {
                if (!x->next.count(c)) { return false; }
                x = x->next[c];
            }
        }
        return x->isword;
    }
};

// resursive search is faster for some reason.
class WordDictionary {
private:
    unordered_map<char, WordDictionary*> next = {};
    bool isword = false;

public:
    WordDictionary() {}
    
    void addWord(string word) {
        WordDictionary* x = this;
        for (char c: word) {
            if (!x->next.count(c)) {
                x->next[c] = new WordDictionary();
            }
            x = x->next[c];
        }
        x->isword = true;
    }
    
    bool search(string word) {
        return searchHelper(this, word, 0);
    }

    bool searchHelper(WordDictionary* node, string& word, int index) {
        if (index == word.length()) {
            return node->isword;
        }
        char c = word[index];
        if (c == '.') {
            for (auto& p : node->next) {
                if (searchHelper(p.second, word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->next.count(c)) { return false; }
            WordDictionary* child = node->next[c];
            return searchHelper(child, word, index + 1);
        }
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */