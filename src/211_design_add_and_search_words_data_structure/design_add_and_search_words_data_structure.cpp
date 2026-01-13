#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class WordDictionary {
   public:
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    bool search(string word) { return searchHelper(word, 0, root); }

   private:
    TrieNode* root;
    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (index == word.size()) return node->isEnd;
        char c = word[index];
        if (c != '.') {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            return searchHelper(word, index + 1, node->children[idx]);
        } else {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && searchHelper(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        }
    }
};

// Test scaffolding
int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << boolalpha;
    cout << wd.search("pad") << endl;  // false
    cout << wd.search("bad") << endl;  // true
    cout << wd.search(".ad") << endl;  // true
    cout << wd.search("b..") << endl;  // true
    return 0;
}
