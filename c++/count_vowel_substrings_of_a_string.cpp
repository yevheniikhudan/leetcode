#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int countVowelSubstrings(std::string word) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int result = 0;
        std::unordered_map<char, int> vowelIds;
        int start = 0;
        int n = word.length();

        for (int i = 0; i < n; i++) {
            char c = word[i];

            if (vowels.find(c) == vowels.end()) {
                vowelIds.clear();
                continue;
            }

            if (vowelIds.empty()) start = i;

            vowelIds[c] = i;

            if (vowelIds.size() == 5) {
                int minIdx = n;
                for (const auto& kv : vowelIds) minIdx = std::min(minIdx, kv.second);
                result += minIdx - start + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    assert(sol.countVowelSubstrings("aeiouu") == 2);
    assert(sol.countVowelSubstrings("unicornarihan") == 0);
    assert(sol.countVowelSubstrings("cuaieuouac") == 7);
    cout << "All test cases passed!" << endl;
    return 0;
}
