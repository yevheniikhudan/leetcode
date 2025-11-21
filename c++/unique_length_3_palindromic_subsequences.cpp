#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int countPalindromicSubsequence(string s) {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (first[curr] == - 1) {
                first[curr] = i;
            }
            
            last[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;
            }
            
            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; j++) {
                between.insert(s[j]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    string s1 = "aabca";
    cout << sol.countPalindromicSubsequence(s1) << " 3" << endl;
    string s2 = "adc";
    cout << sol.countPalindromicSubsequence(s2) << " 0" << endl;
    string s3 = "bbcbaba";
    cout << sol.countPalindromicSubsequence(s3) << " 4" << endl;
    return 0;
}
