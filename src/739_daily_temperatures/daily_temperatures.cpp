/*
739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return
an array answer such that answer[i] is the number of days you have to wait after
the ith day to get a warmer temperature. If there is no future day for which this
is possible, keep answer[i] == 0 instead.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Find number of days until a warmer temperature for each day.
     *
     * @param temperatures Vector of daily temperatures
     * @return Vector of days to wait for warmer temperature (0 if none)
     *
     * Time Complexity: O(n) where n = temperatures.size()
     * Space Complexity: O(n) for the stack
     */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int stackIndex = stk.top();
                stk.pop();
                result[stackIndex] = i - stackIndex;
            }

            stk.push(i);
        }

        return result;
    }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]";
}

void runTests() {
    Solution solution;

    // Test case 1: Example 1
    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result1 = solution.dailyTemperatures(temps1);
    cout << "Test 1: ";
    printVector(result1);
    cout << " (expected: [1, 1, 4, 2, 1, 1, 0, 0])\n";

    // Test case 2: Example 2
    vector<int> temps2 = {30, 40, 50, 60};
    vector<int> result2 = solution.dailyTemperatures(temps2);
    cout << "Test 2: ";
    printVector(result2);
    cout << " (expected: [1, 1, 1, 0])\n";

    // Test case 3: Example 3
    vector<int> temps3 = {30, 60, 90};
    vector<int> result3 = solution.dailyTemperatures(temps3);
    cout << "Test 3: ";
    printVector(result3);
    cout << " (expected: [1, 1, 0])\n";

    // Test case 4: All decreasing
    vector<int> temps4 = {100, 90, 80, 70};
    vector<int> result4 = solution.dailyTemperatures(temps4);
    cout << "Test 4: ";
    printVector(result4);
    cout << " (expected: [0, 0, 0, 0])\n";

    // Test case 5: All increasing
    vector<int> temps5 = {30, 40, 50, 60, 70};
    vector<int> result5 = solution.dailyTemperatures(temps5);
    cout << "Test 5: ";
    printVector(result5);
    cout << " (expected: [1, 1, 1, 1, 0])\n";

    // Test case 6: Single day
    vector<int> temps6 = {75};
    vector<int> result6 = solution.dailyTemperatures(temps6);
    cout << "Test 6: ";
    printVector(result6);
    cout << " (expected: [0])\n";

    // Test case 7: All same temperatures
    vector<int> temps7 = {70, 70, 70, 70};
    vector<int> result7 = solution.dailyTemperatures(temps7);
    cout << "Test 7: ";
    printVector(result7);
    cout << " (expected: [0, 0, 0, 0])\n";

    // Test case 8: Spike pattern
    vector<int> temps8 = {30, 100, 30, 100, 30};
    vector<int> result8 = solution.dailyTemperatures(temps8);
    cout << "Test 8: ";
    printVector(result8);
    cout << " (expected: [1, 0, 1, 0, 0])\n";

    // Test case 9: Valley pattern
    vector<int> temps9 = {90, 30, 90, 30, 90};
    vector<int> result9 = solution.dailyTemperatures(temps9);
    cout << "Test 9: ";
    printVector(result9);
    cout << " (expected: [0, 1, 0, 1, 0])\n";

    // Test case 10: Mixed pattern
    vector<int> temps10 = {55, 38, 53, 81, 61, 93, 97, 32, 43, 78};
    vector<int> result10 = solution.dailyTemperatures(temps10);
    cout << "Test 10: ";
    printVector(result10);
    cout << " (expected: [3, 1, 1, 2, 1, 1, 0, 1, 1, 0])\n";
}

int main() {
    runTests();
    return 0;
}
