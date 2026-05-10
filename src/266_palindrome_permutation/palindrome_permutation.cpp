#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    bool canPermutePalindrome(string s) {
        // TODO: Implement the solution.
        return false;
    }
};

void runTest(string s, bool expected) {
    Solution solution;
    bool actual = solution.canPermutePalindrome(s);
    string status = actual == expected ? "PASS" : "FAIL";
    cout << boolalpha << actual << " | " << expected << " | " << status << endl;
}

int main() {
    runTest("code", false);
    runTest("aab", true);
    runTest("carerac", true);
    runTest("a", true);
    runTest("abc", false);

    return 0;
}
