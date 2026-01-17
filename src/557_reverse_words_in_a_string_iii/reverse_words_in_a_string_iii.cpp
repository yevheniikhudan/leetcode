#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, res;
        vector<string> words;
        while (getline(ss, word, ' ')) {
            reverse(word.begin(), word.end());
            words.push_back(word);
        }
        for (int i = 0; i < words.size(); ++i) {
            res += words[i];
            if (i < words.size() - 1) res += " ";
        }
        // Handle trailing spaces in input
        if (!s.empty() && s.back() == ' ') {
            int trailing = 0;
            for (int i = s.size() - 1; i >= 0 && s[i] == ' '; --i) ++trailing;
            res += string(trailing, ' ');
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseWords("Let's take LeetCode contest") << " | s'teL ekat edoCteeL tsetnoc"
         << endl;
    cout << sol.reverseWords("God Ding") << " | doG gniD" << endl;
    cout << sol.reverseWords("a b c") << " | a b c" << endl;
    cout << sol.reverseWords("  hello world  ") << " |   olleh dlrow  " << endl;
    cout << sol.reverseWords("") << " | " << endl;
    return 0;
}
