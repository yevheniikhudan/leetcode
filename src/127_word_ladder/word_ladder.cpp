#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string pattern(const string& word, int i) {
        return word.substr(0, i) + "*" + word.substr(i + 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end() || beginWord == endWord) return 0;
        unordered_map<string, vector<string>> adjList;
        for (const string& word : wordList) {
            for (int i = 0; i < word.length(); ++i) {
                adjList[pattern(word, i)].push_back(word);
            }
        }
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visit;
        visit.insert(beginWord);
        int result = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord) return result;
                for (int j = 0; j < word.length(); ++j) {
                    string pat = pattern(word, j);
                    if (adjList.count(pat)) {
                        for (const string& adj : adjList[pat]) {
                            if (!visit.count(adj)) {
                                q.push(adj);
                                visit.insert(adj);
                            }
                        }
                    }
                }
            }
            result++;
        }
        return 0;
    }
};

// Test scaffolding
void test() {
    Solution sol;
    vector<string> w1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << sol.ladderLength("hit", "cog", w1) << " | 5\n";
    vector<string> w2 = {"hot", "dot", "dog", "lot", "log"};
    cout << sol.ladderLength("hit", "cog", w2) << " | 0\n";
    vector<string> w3 = {"a", "b", "c"};
    cout << sol.ladderLength("a", "c", w3) << " | 2\n";
    vector<string> w4 = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
    cout << sol.ladderLength("red", "tax", w4) << " | 4\n";
}

int main() {
    test();
    return 0;
}
