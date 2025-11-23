#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int counters[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            counters[s[i] - 'a'] += 1;
            counters[t[i] - 'a'] -= 1;
        }

        for (int count : counters) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "anagram", t1 = "nagaram";
    cout << (sol.isAnagram(s1, t1) ? "true" : "false") << " true" << endl;
    string s2 = "rat", t2 = "car";
    cout << (sol.isAnagram(s2, t2) ? "true" : "false") << " false" << endl;
    return 0;
}
