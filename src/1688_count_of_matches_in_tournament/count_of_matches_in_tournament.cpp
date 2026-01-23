#include <iostream>

using namespace std;

class Solution {
   public:
    int numberOfMatches(int n) { return n - 1; }
};

// Test helper
void testNumberOfMatches() {
    Solution solution;

    // Test case 1: Example 1
    int n1 = 7;
    int expected1 = 6;
    int actual1 = solution.numberOfMatches(n1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    int n2 = 14;
    int expected2 = 13;
    int actual2 = solution.numberOfMatches(n2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: n=1
    int n3 = 1;
    int expected3 = 0;
    int actual3 = solution.numberOfMatches(n3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: n=2
    int n4 = 2;
    int expected4 = 1;
    int actual4 = solution.numberOfMatches(n4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: n=3
    int n5 = 3;
    int expected5 = 2;
    int actual5 = solution.numberOfMatches(n5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: n=4
    int n6 = 4;
    int expected6 = 3;
    int actual6 = solution.numberOfMatches(n6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testNumberOfMatches();
    return 0;
}
