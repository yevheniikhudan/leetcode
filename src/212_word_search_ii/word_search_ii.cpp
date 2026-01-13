#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    string word;
    TrieNode() : isEnd(false), word("") {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        int rows = board.size(), cols = board[0].size();
        int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
        TrieNode* trie = buildTrie(words);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                dfs(board, trie, row, col, rows, cols, dr, dc, res);
            }
        }
        return vector<string>(res.begin(), res.end());
    }

   private:
    void dfs(vector<vector<char>>& board, TrieNode* node, int row, int col, int rows, int cols,
             int dr[], int dc[], unordered_set<string>& res) {
        char c = board[row][col];
        if (c == '#' || node->children[c - 'a'] == nullptr) return;
        node = node->children[c - 'a'];
        if (node->isEnd) res.insert(node->word);
        board[row][col] = '#';
        for (int d = 0; d < 4; ++d) {
            int nr = row + dr[d], nc = col + dc[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                dfs(board, node, nr, nc, rows, cols, dr, dc, res);
            }
        }
        board[row][col] = c;
    }
    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->children[c - 'a'] == nullptr) node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->isEnd = true;
            node->word = word;
        }
        return root;
    }
};

// Test scaffolding
int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    Solution sol;
    vector<string> result = sol.findWords(board, words);
    for (const string& w : result) cout << w << " ";
    cout << endl;  // eat oath
    return 0;
}
