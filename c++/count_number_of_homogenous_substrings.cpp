#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    int countHomogenous(string s) {
        int MOD = (int)1e9 + 7;

        int ans = 0;
        int streak = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                streak += 1;
            } else {
                streak = 1;
            }

            ans = (ans + streak) % MOD;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.countHomogenous("abbcccaa") == 13);
    assert(sol.countHomogenous("xy") == 2);
    assert(sol.countHomogenous("zzzzz") == 15);
    cout << "All test cases passed!" << endl;
    return 0;
}
