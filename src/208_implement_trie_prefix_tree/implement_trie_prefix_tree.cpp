// src/208_implement_trie_prefix_tree/implement_trie_prefix_tree.cpp
// LeetCode 208. Implement Trie (Prefix Tree)
// C++ solution skeleton, workspace style
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
public:
    Trie() : is_end(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->is_end;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
    
    ~Trie() {
        for (auto& p : children) {
            delete p.second;
        }
    }
private:
    unordered_map<char, Trie*> children;
    bool is_end;
};

// Test scaffolding
void test(const string& test_name, Trie& trie, const vector<pair<string, string>>& ops, const vector<string>& args, const vector<string>& expected) {
    cout << test_name << ":\n";
    for (size_t i = 0; i < ops.size(); ++i) {
        string op = ops[i].first;
        string arg = args[i];
        if (op == "insert") {
            trie.insert(arg);
            cout << "insert(" << arg << ") | expected: null" << endl;
        } else if (op == "search") {
            bool res = trie.search(arg);
            cout << "search(" << arg << ") = " << (res ? "true" : "false") << " | expected: " << expected[i] << endl;
        } else if (op == "startsWith") {
            bool res = trie.startsWith(arg);
            cout << "startsWith(" << arg << ") = " << (res ? "true" : "false") << " | expected: " << expected[i] << endl;
        }
    }
    cout << endl;
}

int main() {
    Trie trie;
    vector<pair<string, string>> ops = {{"insert", "apple"}, {"search", "apple"}, {"search", "app"}, {"startsWith", "app"}, {"insert", "app"}, {"search", "app"}};
    vector<string> args = {"apple", "apple", "app", "app", "app", "app"};
    vector<string> expected = {"null", "true", "false", "true", "null", "true"};
    test("Test1", trie, ops, args, expected);
    // Add more test cases as needed
    return 0;
}
