#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            } else if (ch == ')') {
                low = max(0, low - 1);
                high--;
            } else {
                low = max(0, low - 1);
                high++;
            }

            if (high < 0) return false;
        }

        return low == 0;
    }
};

int main() {
    Solution sol;

    cout << (sol.checkValidString("()") ? "true" : "false") << " | True" << endl;
    cout << (sol.checkValidString("(*)") ? "true" : "false") << " | True" << endl;
    cout << (sol.checkValidString("(*))") ? "true" : "false") << " | True" << endl;
    cout << (sol.checkValidString("***") ? "true" : "false") << " | True" << endl;
    cout << (sol.checkValidString(")((") ? "true" : "false") << " | False" << endl;

    return 0;
}
