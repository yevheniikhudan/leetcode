#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * Determine if the given number is a confusing number.
     *
     * A confusing number becomes a different number when rotated 180 degrees.
     * Valid rotations: 0→0, 1→1, 6→9, 8→8, 9→6
     *
     * @param n Integer to check (0 <= n <= 10^9)
     * @return true if n is a confusing number, false otherwise
     */
    bool confusingNumber(int n) {
        unordered_map<int, int> invertMap = {{0, 0}, {1, 1}, {8, 8}, {6, 9}, {9, 6}};
        int invertNumber = 0;
        int nCopy = n;

        while (nCopy > 0) {
            int temp = nCopy % 10;

            if (!invertMap.count(temp)) return false;

            invertNumber = invertNumber * 10 + invertMap[temp];
            nCopy /= 10;
        }

        return invertNumber != n;
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

    // Test Case 1: Single digit confusing (6 -> 9)
    int n1 = 6;
    bool result1 = solution.confusingNumber(n1);
    bool expected1 = true;
    printResult(result1, expected1);

    // Test Case 2: Multi-digit confusing (89 -> 68)
    int n2 = 89;
    bool result2 = solution.confusingNumber(n2);
    bool expected2 = true;
    printResult(result2, expected2);

    // Test Case 3: Palindromic rotation (11 -> 11)
    int n3 = 11;
    bool result3 = solution.confusingNumber(n3);
    bool expected3 = false;
    printResult(result3, expected3);

    // Test Case 4: Contains invalid digit (25)
    int n4 = 25;
    bool result4 = solution.confusingNumber(n4);
    bool expected4 = false;
    printResult(result4, expected4);

    // Test Case 5: Zero (0 -> 0, not confusing)
    int n5 = 0;
    bool result5 = solution.confusingNumber(n5);
    bool expected5 = false;
    printResult(result5, expected5);

    // Test Case 6: Confusing with valid digits (96 -> 96, not confusing)
    int n6 = 96;
    bool result6 = solution.confusingNumber(n6);
    bool expected6 = false;
    printResult(result6, expected6);

    return 0;
}
