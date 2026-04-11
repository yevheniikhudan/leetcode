#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> occur;
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            occur[nums[i]].push_back(i);
        }

        for (const auto& [_, indices] : occur) {
            if (indices.size() < 3) {
                continue;
            }

            for (int i = 2; i < indices.size(); i++) {
                res = min(res, indices[i] - indices[i - 2]);
            }
        }

        return res == INT_MAX ? -1 : res * 2;
    }
};

string vectorToString(const vector<int>& vec) {
    string result = "[";
    for (size_t i = 0; i < vec.size(); i++) {
        result += to_string(vec[i]);
        if (i < vec.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}

int main() {
    cout << "================================================================================\n";
    cout << "Testing: Problem 3741 - Minimum Distance Between Three Equal Elements II\n";
    cout << "================================================================================\n";

    Solution solution;
    int passCount = 0;
    int failCount = 0;

    // Test Case 1: All elements are the same
    {
        vector<int> nums = {1, 1, 1, 1, 1};
        int expected = 4;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 1: All elements are the same\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    // Test Case 2: No three equal elements
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        int expected = -1;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 2: No three equal elements\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    // Test Case 3: 1's at indices [0,1,3,4]
    {
        vector<int> nums = {1, 1, 2, 1, 1};
        int expected = 6;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 3: 1's at indices [0,1,3,4]\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    // Test Case 4: Exactly three equal elements
    {
        vector<int> nums = {5, 5, 5};
        int expected = 4;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 4: Exactly three equal elements\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    // Test Case 5: All identical elements
    {
        vector<int> nums = {3, 3, 3, 3, 3};
        int expected = 4;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 5: All identical elements\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    // Test Case 6: Two values with 3+ occurrences
    {
        vector<int> nums = {1, 1, 2, 1, 2, 2, 1, 2};
        int expected = 6;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 6: Two values with 3+ occurrences\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    // Test Case 7: Only two 5's, but 10 has three
    {
        vector<int> nums = {5, 5, 10, 10, 10};
        int expected = 4;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 7: Only two 5's, but 10 has three\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    // Test Case 8: 1's at indices [0,3,6], raw distance = 6, final = 12
    {
        vector<int> nums = {1, 2, 3, 1, 4, 5, 1};
        int expected = 12;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 8: 1's at indices [0,3,6], raw distance = 6, final = 12\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    // Test Case 9: 2's at indices [0, 2, 3], raw distance = 3, final = 6
    {
        vector<int> nums = {2, 1, 2, 2};
        int expected = 6;
        int actual = solution.minimumDistance(nums);
        bool pass = (actual == expected);

        cout << "\nTest Case 9: 2's at indices [0, 2, 3], raw distance = 3, final = 6\n";
        cout << "Input:    " << vectorToString(nums) << "\n";
        cout << actual << " | " << expected << " | " << (pass ? "PASS" : "FAIL") << "\n";

        if (pass) passCount++; else failCount++;
    }

    cout << "\n================================================================================\n";
    cout << "Results: " << passCount << " passed, " << failCount << " failed out of 9 tests\n";
    cout << "================================================================================\n";

    return 0;
}
