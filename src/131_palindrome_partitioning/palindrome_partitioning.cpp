#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    string s;
    vector<vector<string>> result;
    vector<string> part;

   public:
    vector<vector<string>> partition(string s) {
        result.clear();
        part.clear();
        this->s = s;

        dfs(0);

        return result;
    }

   private:
    void dfs(int start) {
        if (start == s.size()) {
            result.push_back(part);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(start, end)) {
                part.push_back(s.substr(start, end - start + 1));
                dfs(end + 1);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    struct Test {
        string s;
        vector<vector<string>> expected;
    } tests[] = {
        {"aab", {{"a", "a", "b"}, {"aa", "b"}}},
        {"a", {{"a"}}},
        {"racecar",
         {{"r", "a", "c", "e", "c", "a", "r"},
          {"r", "a", "cec", "a", "r"},
          {"r", "aceca", "r"},
          {"racecar"}}},
        {"abba", {{"a", "b", "b", "a"}, {"a", "bb", "a"}, {"abba"}}},
        {"abc", {{"a", "b", "c"}}},
    };
    for (int i = 0; i < 5; ++i) {
        vector<vector<string>> result = sol.partition(tests[i].s);
        cout << "Test " << (i + 1) << ": [";
        for (const auto& part : result) {
            cout << "[";
            for (const auto& str : part) cout << str << ",";
            cout << "] ";
        }
        cout << "] | [";
        for (const auto& part : tests[i].expected) {
            cout << "[";
            for (const auto& str : part) cout << str << ",";
            cout << "] ";
        }
        cout << "]" << endl;
    }
    return 0;
}
