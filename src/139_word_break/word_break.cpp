#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) { return false; }
};

// Test helper
void testWordBreak() {
    Solution solution;

    // Test case 1: Example 1
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    bool expected1 = true;
    bool actual1 = solution.wordBreak(s1, wordDict1);
    cout << boolalpha << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    bool expected2 = true;
    bool actual2 = solution.wordBreak(s2, wordDict2);
    cout << boolalpha << actual2 << " | " << expected2 << endl;

    // Test case 3: Example 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    bool expected3 = false;
    bool actual3 = solution.wordBreak(s3, wordDict3);
    cout << boolalpha << actual3 << " | " << expected3 << endl;

    // Test case 4: Single word
    string s4 = "a";
    vector<string> wordDict4 = {"a"};
    bool expected4 = true;
    bool actual4 = solution.wordBreak(s4, wordDict4);
    cout << boolalpha << actual4 << " | " << expected4 << endl;

    // Test case 5: No match
    string s5 = "abc";
    vector<string> wordDict5 = {"d", "e"};
    bool expected5 = false;
    bool actual5 = solution.wordBreak(s5, wordDict5);
    cout << boolalpha << actual5 << " | " << expected5 << endl;

    // Test case 6: Reuse words
    string s6 = "aaaa";
    vector<string> wordDict6 = {"a", "aa"};
    bool expected6 = true;
    bool actual6 = solution.wordBreak(s6, wordDict6);
    cout << boolalpha << actual6 << " | " << expected6 << endl;
}

int main() {
    testWordBreak();
    return 0;
}
