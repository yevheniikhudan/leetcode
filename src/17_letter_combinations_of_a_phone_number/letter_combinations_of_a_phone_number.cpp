#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        unordered_map<char, string> numbersToLetters = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                                        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                                        {'8', "tuv"}, {'9', "wxyz"}};
        string path;
        backtrack(digits, 0, path, res, numbersToLetters);
        return res;
    }

   private:
    void backtrack(const string& digits, int index, string& path, vector<string>& res,
                   const unordered_map<char, string>& map) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        for (char c : map.at(digits[index])) {
            path.push_back(c);
            backtrack(digits, index + 1, path, res, map);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    struct Test {
        string digits;
        vector<string> expected;
    } tests[] = {
        {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
        {"", {}},
        {"2", {"a", "b", "c"}},
        {"7", {"p", "q", "r", "s"}},
        {"9", {"w", "x", "y", "z"}},
    };
    for (int i = 0; i < 5; ++i) {
        vector<string> result = sol.letterCombinations(tests[i].digits);
        sort(result.begin(), result.end());
        sort(tests[i].expected.begin(), tests[i].expected.end());
        cout << "Test " << (i + 1) << ": [";
        for (const auto& s : result) cout << s << ",";
        cout << "] | [";
        for (const auto& s : tests[i].expected) cout << s << ",";
        cout << "]" << endl;
    }
    return 0;
}
