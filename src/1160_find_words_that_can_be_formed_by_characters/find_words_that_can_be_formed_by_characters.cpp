#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26, 0);
        for (char c : chars) {
            counts[c - 'a']++;
        }
        int result = 0;
        for (string word : words) {
            vector<int> wordCounts(26, 0);
            for (char c : word) {
                wordCounts[c - 'a']++;
            }
            bool canForm = true;
            for (int i = 0; i < 26; i++) {
                if (wordCounts[i] > counts[i]) {
                    canForm = false;
                    break;
                }
            }
            if (canForm) {
                result += word.length();
            }
        }
        return result;
    }
};

// Test helper
void testCountCharacters() {
    Solution solution;

    // Test case 1: Example 1
    vector<string> words1 = {"cat", "bt", "hat", "tree"};
    string chars1 = "atach";
    int expected1 = 6;
    int actual1 = solution.countCharacters(words1, chars1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    vector<string> words2 = {"hello", "world", "leetcode"};
    string chars2 = "welldonehoneyr";
    int expected2 = 10;
    int actual2 = solution.countCharacters(words2, chars2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: No good words
    vector<string> words3 = {"abc", "def"};
    string chars3 = "xyz";
    int expected3 = 0;
    int actual3 = solution.countCharacters(words3, chars3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: All words good
    vector<string> words4 = {"a", "b"};
    string chars4 = "ab";
    int expected4 = 2;
    int actual4 = solution.countCharacters(words4, chars4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Words with duplicates
    vector<string> words5 = {"aa", "bb"};
    string chars5 = "aab";
    int expected5 = 2;
    int actual5 = solution.countCharacters(words5, chars5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: Single word
    vector<string> words6 = {"test"};
    string chars6 = "tset";
    int expected6 = 4;
    int actual6 = solution.countCharacters(words6, chars6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testCountCharacters();
    return 0;
}
