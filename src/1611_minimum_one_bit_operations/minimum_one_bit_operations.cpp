#include <cassert>
#include <iostream>
using namespace std;

class Solution {
   public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int k = 0;
        int mask = 1;

        while (mask <= n) {
            if ((n & mask) != 0) {
                ans = (1 << (k + 1)) - 1 - ans;
            }

            mask <<= 1;
            k++;
        }

        return ans;
    }
};

void test_minimum_one_bit_operations() {
    Solution s;

    // Test case 1: n = 3
    assert(s.minimumOneBitOperations(3) == 2);
    cout << "✓ Test case 1 passed" << endl;

    // Test case 2: n = 6
    assert(s.minimumOneBitOperations(6) == 4);
    cout << "✓ Test case 2 passed" << endl;

    // Test case 3: n = 0
    assert(s.minimumOneBitOperations(0) == 0);
    cout << "✓ Test case 3 passed" << endl;

    // Test case 4: n = 1
    assert(s.minimumOneBitOperations(1) == 1);
    cout << "✓ Test case 4 passed" << endl;

    cout << "All test cases passed!" << endl;
}

int main() {
    test_minimum_one_bit_operations();
    return 0;
}
