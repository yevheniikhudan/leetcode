#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    int numSub(string s) {
        int MOD = pow(10, 9) + 7;
        int consecutive = 0;
        long long ans = 0;

        for (char ch : s) {
            if (ch == '1') {
                consecutive += 1;
            } else {
                ans += consecutive * ((long long)consecutive + 1) / 2;
                consecutive = 0;
            }
        }

        ans += consecutive * ((long long)consecutive + 1) / 2;
        ans %= MOD;

        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.numSub("0110111") == 9);
    assert(sol.numSub("101") == 2);
    assert(sol.numSub("1111") == 10);
    cout << "All test cases passed!" << endl;
    return 0;
}
