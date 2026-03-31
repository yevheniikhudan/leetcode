#include <iostream>
#include <string>
#include <vector>
using namespace std;

// C++ implementation for LeetCode 202 - Happy Number
// Uses Floyd's cycle detection (tortoise and hare) and includes
// test scaffolding that prints results in the format:
// actual | expected | PASS (if actual == expected) or FAIL

class Solution {
public:
    // Determine whether n is a happy number.
    bool isHappy(int n) {
        if (n <= 0) return false;

        auto sumOfSquares = [](int x) {
            int res = 0;
            while (x > 0) {
                int d = x % 10;
                res += d * d;
                x /= 10;
            }
            return res;
        };

        int slow = sumOfSquares(n);
        int fast = sumOfSquares(sumOfSquares(n));

        while (slow != fast) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }

        return slow == 1;
    }
    private:
    int sumOfSquares(int n) {
        int res = 0;
        while (n > 0) {
            int digit = n % 10;
            res += digit * digit;
            n /= 10;
        }

        return res;
    }
};

// Helper to format boolean output as "true"/"false"
static string bool_to_str(bool b) {
    return b ? "true" : "false";
}

// Test scaffolding with 5+ test cases.
// Prints results in the required format:
// actual | expected | PASS (if actual == expected) or FAIL
int main() {
    Solution solution;

    vector<pair<int, bool>> tests = {
        {19, true},    // example: happy
        {2, false},    // example: not happy
        {1, true},     // trivial happy
        {7, true},     // known happy number
        {116, false},  // known non-happy
        {100, true},   // additional case
        {4, false}     // known unhappy cycle starter
    };

    for (const auto &tc : tests) {
        int input = tc.first;
        bool expected = tc.second;

        bool actual = solution.isHappy(input);

        cout << bool_to_str(actual)
             << " | " << bool_to_str(expected)
             << " | " << (actual == expected ? "PASS" : "FAIL")
             << "\n";
    }

    return 0;
}
