#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string largestGoodInteger(string num) {
        char maxDigit = '\0';

        for (int i = 2; i < num.length(); i++) {
            if (num[i - 2] == num[i - 1] && num[i - 1] == num[i]) {
                maxDigit = max(maxDigit, num[i]);
            }
        }
        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};

// Test helper
void testLargestGoodInteger() {
    Solution solution;

    // Test case 1: Example 1
    string num1 = "6777133339";
    string expected1 = "777";
    string actual1 = solution.largestGoodInteger(num1);
    cout << actual1 << " | " << expected1 << endl;

    // Test case 2: Example 2
    string num2 = "2300019";
    string expected2 = "000";
    string actual2 = solution.largestGoodInteger(num2);
    cout << actual2 << " | " << expected2 << endl;

    // Test case 3: Example 3
    string num3 = "42352338";
    string expected3 = "";
    string actual3 = solution.largestGoodInteger(num3);
    cout << actual3 << " | " << expected3 << endl;

    // Test case 4: All same
    string num4 = "111";
    string expected4 = "111";
    string actual4 = solution.largestGoodInteger(num4);
    cout << actual4 << " | " << expected4 << endl;

    // Test case 5: Multiple, choose largest
    string num5 = "999888";
    string expected5 = "999";
    string actual5 = solution.largestGoodInteger(num5);
    cout << actual5 << " | " << expected5 << endl;

    // Test case 6: No good
    string num6 = "123456";
    string expected6 = "";
    string actual6 = solution.largestGoodInteger(num6);
    cout << actual6 << " | " << expected6 << endl;
}

int main() {
    testLargestGoodInteger();
    return 0;
}
