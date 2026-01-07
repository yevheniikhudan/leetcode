#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }

   private:
    void backtrack(vector<string>& res, string s, int left, int right, int n) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (left < n) backtrack(res, s + '(', left + 1, right, n);
        if (right < left) backtrack(res, s + ')', left, right + 1, n);
    }
};

// Test scaffolding
int main() {
    Solution sol;
    vector<string> e1 = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    vector<string> r1 = sol.generateParenthesis(3);
    sort(r1.begin(), r1.end());
    sort(e1.begin(), e1.end());
    cout << (r1 == e1 ? "PASS" : "FAIL") << endl;
    vector<string> e2 = {"()"};
    vector<string> r2 = sol.generateParenthesis(1);
    sort(r2.begin(), r2.end());
    sort(e2.begin(), e2.end());
    cout << (r2 == e2 ? "PASS" : "FAIL") << endl;
    cout << (sol.generateParenthesis(4).size() == 14 ? "PASS" : "FAIL") << endl;
    return 0;
}
