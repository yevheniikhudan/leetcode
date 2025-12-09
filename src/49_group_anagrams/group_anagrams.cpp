#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};

void printResult(vector<vector<string>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution s;
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result1 = s.groupAnagrams(strs1);
    printResult(result1);

    vector<string> strs2 = {""};
    auto result2 = s.groupAnagrams(strs2);
    printResult(result2);

    vector<string> strs3 = {"a"};
    auto result3 = s.groupAnagrams(strs3);
    printResult(result3);

    return 0;
}
