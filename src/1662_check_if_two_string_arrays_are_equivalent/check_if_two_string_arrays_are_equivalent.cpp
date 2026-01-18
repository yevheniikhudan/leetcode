#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (const auto& w : word1) s1 += w;
        for (const auto& w : word2) s2 += w;
        return s1 == s2;
    }
};

int main() {
    Solution sol;
    vector<string> t1a = {"ab", "c"}, t1b = {"a", "bc"};
    cout << boolalpha << sol.arrayStringsAreEqual(t1a, t1b) << " | True" << endl;
    vector<string> t2a = {"a", "cb"}, t2b = {"ab", "c"};
    cout << boolalpha << sol.arrayStringsAreEqual(t2a, t2b) << " | False" << endl;
    vector<string> t3a = {"abc", "d", "defg"}, t3b = {"abcddefg"};
    cout << boolalpha << sol.arrayStringsAreEqual(t3a, t3b) << " | True" << endl;
    vector<string> t4a = {""}, t4b = {""};
    cout << boolalpha << sol.arrayStringsAreEqual(t4a, t4b) << " | True" << endl;
    vector<string> t5a = {"a", "b", "c"}, t5b = {"abc"};
    cout << boolalpha << sol.arrayStringsAreEqual(t5a, t5b) << " | True" << endl;
    return 0;
}
