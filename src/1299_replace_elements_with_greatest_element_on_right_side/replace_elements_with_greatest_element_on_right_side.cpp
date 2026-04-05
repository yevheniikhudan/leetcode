#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int rightMax = -1;

        for (int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = rightMax;
            rightMax = max(temp, rightMax);
        }
        return arr;
    }
};


void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]";
}

void testReplaceElements() {
    Solution solution;

    // Test 1: Example from problem
    vector<int> arr1 = {17, 18, 5, 4, 6, 1};
    vector<int> result1 = solution.replaceElements(arr1);
    vector<int> expected1 = {18, 6, 6, 6, 1, -1};
    printVector(result1);
    cout << " | ";
    printVector(expected1);
    cout << " | " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test 2: Single element
    vector<int> arr2 = {400};
    vector<int> result2 = solution.replaceElements(arr2);
    vector<int> expected2 = {-1};
    printVector(result2);
    cout << " | ";
    printVector(expected2);
    cout << " | " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test 3: Strictly increasing
    vector<int> arr3 = {1, 2, 3, 4, 5};
    vector<int> result3 = solution.replaceElements(arr3);
    vector<int> expected3 = {5, 5, 5, 5, -1};
    printVector(result3);
    cout << " | ";
    printVector(expected3);
    cout << " | " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test 4: Strictly decreasing
    vector<int> arr4 = {5, 4, 3, 2, 1};
    vector<int> result4 = solution.replaceElements(arr4);
    vector<int> expected4 = {4, 3, 2, 1, -1};
    printVector(result4);
    cout << " | ";
    printVector(expected4);
    cout << " | " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test 5: All same elements
    vector<int> arr5 = {3, 3, 3, 3};
    vector<int> result5 = solution.replaceElements(arr5);
    vector<int> expected5 = {3, 3, 3, -1};
    printVector(result5);
    cout << " | ";
    printVector(expected5);
    cout << " | " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

int main() {
    testReplaceElements();
    return 0;
}
