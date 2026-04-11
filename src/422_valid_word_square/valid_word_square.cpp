#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * Determine if the given array of strings forms a valid word square.
     *
     * A valid word square means that the k-th row and k-th column
     * read the same string for all k.
     *
     * @param words Vector of strings to check
     * @return true if valid word square, false otherwise
     */
    bool validWordSquare(vector<string>& words) {
        for (int wordNum = 0; wordNum < words.size(); wordNum++) {
            for (int chrPos = 0; chrPos < words[wordNum].size(); chrPos++) {
                if (chrPos >= words.size() ||
                    wordNum >= words[chrPos].size() ||
                    words[wordNum][chrPos] != words[chrPos][wordNum]) {
                        return false;
                    }
            }
        }
        return true;
    }
};

// ============================================================================
// Test Helper Functions
// ============================================================================

void printResult(bool actual, bool expected) {
    cout << (actual ? "true" : "false") << " | "
         << (expected ? "true" : "false") << " | "
         << (actual == expected ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// Main Test Function
// ============================================================================

int main() {
    Solution solution;

    // Test Case 1: Valid square with equal length words
    vector<string> words1 = {"abcd", "bnrt", "crmy", "dtye"};
    bool result1 = solution.validWordSquare(words1);
    bool expected1 = true;
    printResult(result1, expected1);

    // Test Case 2: Valid square with unequal length words
    vector<string> words2 = {"abcd", "bnrt", "crm", "dt"};
    bool result2 = solution.validWordSquare(words2);
    bool expected2 = true;
    printResult(result2, expected2);

    // Test Case 3: Invalid square - mismatch in row/column
    vector<string> words3 = {"ball", "area", "read", "lady"};
    bool result3 = solution.validWordSquare(words3);
    bool expected3 = false;
    printResult(result3, expected3);

    // Test Case 4: Single word (always valid)
    vector<string> words4 = {"a"};
    bool result4 = solution.validWordSquare(words4);
    bool expected4 = true;
    printResult(result4, expected4);

    // Test Case 5: Two identical words
    vector<string> words5 = {"ab", "ba"};
    bool result5 = solution.validWordSquare(words5);
    bool expected5 = true;
    printResult(result5, expected5);

    // Test Case 6: Invalid - different characters at symmetric positions
    vector<string> words6 = {"abc", "bda", "cec"};
    bool result6 = solution.validWordSquare(words6);
    bool expected6 = false;
    printResult(result6, expected6);

    return 0;
}
