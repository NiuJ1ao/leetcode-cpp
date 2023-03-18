#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
*/

struct TrieNode {
    string val;
    bool isTerminal;
    vector<TrieNode*> next;
    TrieNode() : val(""), isTerminal(false), next(vector<TrieNode*>(26)) {}
    TrieNode(string x) : val(x), isTerminal(false), next(vector<TrieNode*>(26)) {}
};

class Trie {

TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* x = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!x->next[idx]) {
                x->next[idx] = new TrieNode();
            } 
            x = x -> next[idx];
        }
        x -> val = word;
        x -> isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* x = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!x->next[idx]) {
                return false;
            } 
            x = x -> next[idx];
        }
        return x -> isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* x = root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if (!x->next[idx]) {
                return false;
            } 
            x = x -> next[idx];
        }
        return true;
    }
};

/*
 * Map solution
 */
class Trie {

private:
    unordered_map<char, Trie*> next = {};
    bool isword = false;

public:
    Trie() {}
    
    void insert(string word) {
        Trie* x = this;
        for (char c: word) {
            if (!x->next.count(c)) {
                x->next[c] = new Trie();
            }
            x = x->next[c];
        }
        x->isword = true;
    }
    
    bool search(string word) {
        Trie* x = this;
        for (char c : word) {
            if (!x->next.count(c)) { return false; }
            x = x->next[c];
        }
        return x->isword;
    }
    
    bool startsWith(string prefix) {
        Trie* x = this;
        for (char c : prefix) {
            if (!x->next.count(c)) { return false; }
            x = x->next[c];
        }
        return true;
    }
};