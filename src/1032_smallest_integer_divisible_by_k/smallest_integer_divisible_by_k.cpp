#include <cassert>
#include <iostream>

using namespace std;

class Solution {
   public:
    /**
     * Find the length of the smallest number made of 1's divisible by k.
     *
     * @param k Positive integer
     * @return Length of the smallest number, or -1 if no such number exists
     */
    int smallestRepunitDivByK(int k) {
        if (k == 1) {
            return 1;
        }
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int remainder = 0;
        for (int i = 1; i < k + 1; i++) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return i;
            }
        }

        return -1;
    }
};

void test_smallest_integer_divisible_by_k() {
    Solution solution;

    // // Test case 1: k = 1
    // int k1 = 1;
    // int result1 = solution.smallestRepunitDivByK(k1);
    // cout << "Test 1: k = " << k1 << ", Output = " << result1 << endl;
    // assert(result1 == 1);

    // // Test case 2: k = 2 (no solution - even number)
    // int k2 = 2;
    // int result2 = solution.smallestRepunitDivByK(k2);
    // cout << "Test 2: k = " << k2 << ", Output = " << result2 << endl;
    // assert(result2 == -1);

    // Test case 3: k = 3
    int k3 = 3;
    int result3 = solution.smallestRepunitDivByK(k3);
    cout << "Test 3: k = " << k3 << ", Output = " << result3 << endl;
    assert(result3 == 3);

    // Test case 4: k = 7
    int k4 = 7;
    int result4 = solution.smallestRepunitDivByK(k4);
    cout << "Test 4: k = " << k4 << ", Output = " << result4 << endl;
    assert(result4 == 6);

    // Test case 5: k = 5 (no solution - divisible by 5)
    int k5 = 5;
    int result5 = solution.smallestRepunitDivByK(k5);
    cout << "Test 5: k = " << k5 << ", Output = " << result5 << endl;
    assert(result5 == -1);

    // Test case 6: k = 9
    int k6 = 9;
    int result6 = solution.smallestRepunitDivByK(k6);
    cout << "Test 6: k = " << k6 << ", Output = " << result6 << endl;
    assert(result6 == 9);

    // Test case 7: k = 17
    int k7 = 17;
    int result7 = solution.smallestRepunitDivByK(k7);
    cout << "Test 7: k = " << k7 << ", Output = " << result7 << endl;
    assert(result7 == 16);

    cout << "All test cases passed!" << endl;
}

int main() {
    test_smallest_integer_divisible_by_k();
    return 0;
}
