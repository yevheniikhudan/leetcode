#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

/*
 C++ skeleton for LeetCode 2013 - Detect Squares

 Conventions:
 - This file contains only the Solution signature and test scaffolding.
 - Methods intentionally have no implementation (TODO).
 - Tests print results in the format: actual | expected | PASS/FAIL
*/

class DetectSquares {
    unordered_map<int, unordered_map<int, int>> ptsCount;

public:
    DetectSquares() {}

    void add(vector<int> point) {
        ptsCount[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1 = point[1];

        for (auto &[y2, cnt] : ptsCount[x1]) {
            int side = y2 - y1;
            if (side == 0) continue;

            int x3 = x1 + side, x4 = x1 - side;
            res += cnt * ptsCount[x3][y1] * ptsCount[x3][y2];
            res += cnt * ptsCount[x4][y1] * ptsCount[x4][y2];
        }

        return res;
    }
};

// Helper function to format output
static string point_to_str(const vector<int>& p) {
    return "[" + to_string(p[0]) + "," + to_string(p[1]) + "]";
}

int main() {
    // Test 1: Simple square detection
    DetectSquares ds1;
    ds1.add({3, 10});
    ds1.add({11, 20});
    ds1.add({3, 20});
    int actual1 = ds1.count({11, 10});
    int expected1 = 1;
    cout << actual1 << " | " << expected1 << " | " << (actual1 == expected1 ? "PASS" : "FAIL") << "\n";

    // Test 2: No square formed
    DetectSquares ds2;
    ds2.add({1, 0});
    ds2.add({0, 1});
    int actual2 = ds2.count({1, 1});
    int expected2 = 0;
    cout << actual2 << " | " << expected2 << " | " << (actual2 == expected2 ? "PASS" : "FAIL") << "\n";

    // Test 3: Multiple points, one square
    DetectSquares ds3;
    ds3.add({0, 0});
    ds3.add({1, 1});
    ds3.add({0, 1});
    ds3.add({1, 0});
    int actual3 = ds3.count({1, 1});
    int expected3 = 1;
    cout << actual3 << " | " << expected3 << " | " << (actual3 == expected3 ? "PASS" : "FAIL") << "\n";

    // Test 4: Empty structure
    DetectSquares ds4;
    int actual4 = ds4.count({0, 0});
    int expected4 = 0;
    cout << actual4 << " | " << expected4 << " | " << (actual4 == expected4 ? "PASS" : "FAIL") << "\n";

    // Test 5: Single point added
    DetectSquares ds5;
    ds5.add({5, 5});
    int actual5 = ds5.count({5, 5});
    int expected5 = 0;
    cout << actual5 << " | " << expected5 << " | " << (actual5 == expected5 ? "PASS" : "FAIL") << "\n";

    // Test 6: Multiple squares with shared corners
    DetectSquares ds6;
    ds6.add({0, 0});
    ds6.add({1, 0});
    ds6.add({0, 1});
    ds6.add({1, 1});
    ds6.add({2, 0});
    ds6.add({2, 1});
    int actual6 = ds6.count({2, 0});
    int expected6 = 0;  // No complete square with (2,0) as corner yet
    cout << actual6 << " | " << expected6 << " | " << (actual6 == expected6 ? "PASS" : "FAIL") << "\n";

    return 0;
}
