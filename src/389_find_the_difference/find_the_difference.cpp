#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    char findTheDifference(string s, string t) {
        int sSum = 0, tSum = 0;
        for (size_t i = 0; i < t.size(); ++i) {
            if (i < t.size() - 1) {
                sSum += s[i];
            }
            tSum += t[i];
        }
        return char(tSum - sSum);
    }
};

int main() {
    Solution sol;
    cout << sol.findTheDifference("abcd", "abcde") << " | e" << endl;
    cout << sol.findTheDifference("", "y") << " | y" << endl;
    cout << sol.findTheDifference("a", "aa") << " | a" << endl;
    cout << sol.findTheDifference("ae", "aea") << " | a" << endl;
    cout << sol.findTheDifference("xyz", "xzyq") << " | q" << endl;
    return 0;
}
