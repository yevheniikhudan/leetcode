#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 C++ skeleton for LeetCode 66 - Plus One

 Conventions:
 - This file contains only the Solution signature and test scaffolding.
 - The method `plusOne` intentionally has no implementation (TODO).
 - Tests print results in the format: actual | expected | PASS/FAIL
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> result(n + 1);
        result[0] = 1;
        return result;
    }
};

static string vec_to_str(const vector<int>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += to_string(v[i]);
        if (i + 1 < v.size()) s += ",";
    }
    s += "]";
    return s;
}

int main() {
    Solution sol;

    vector<pair<vector<int>, vector<int>>> tests = {
        {{1,2,3}, {1,2,4}},
        {{4,3,2,1}, {4,3,2,2}},
        {{9}, {1,0}},
        {{9,9}, {1,0,0}},
        {{0}, {1}},
        // extra cases
        {{1,9,9}, {2,0,0}}
    };

    for (const auto &tc : tests) {
        vector<int> inp = tc.first;
        vector<int> expected = tc.second;

        vector<int> actual = sol.plusOne(inp);

        cout << vec_to_str(actual)
             << " | " << vec_to_str(expected)
             << " | " << (actual == expected ? "PASS" : "FAIL")
             << "\n";
    }

    return 0;
}
