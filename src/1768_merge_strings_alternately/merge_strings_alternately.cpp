#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        string res;
        for (int i = 0; i < max(n1, n2); ++i) {
            if (i < n1) res += word1[i];
            if (i < n2) res += word2[i];
        }
        return res;
    }
};

// Test scaffolding
int main() {
    Solution sol;
    cout << sol.mergeAlternately("abc", "pqr") << endl;  // apbqcr
    cout << sol.mergeAlternately("ab", "pqrs") << endl;  // apbqrs
    cout << sol.mergeAlternately("abcd", "pq") << endl;  // apbqcd
    cout << sol.mergeAlternately("a", "z") << endl;      // az
    cout << sol.mergeAlternately("abcde", "") << endl;   // abcde
    return 0;
}
