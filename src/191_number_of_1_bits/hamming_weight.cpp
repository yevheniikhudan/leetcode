#include <iostream>
#include <vector>
#include <cstdint>
#include <utility>

class Solution {
public:
    // Count the number of '1' bits in the 32-bit representation of n.
    // Skeleton: no implementation provided.
    int hammingWeight(uint32_t n) {
        int res = 0;

        while (n != 0) {
            n &= n - 1;
            res += 1;
        }

        return res;
    }
};

static void print_result(int actual, int expected) {
    std::cout << actual << " | " << expected << " | " << (actual == expected ? "PASS" : "FAIL") << "\n";
}

int main() {
    Solution sol;

    // Test cases: {input (uint32_t), expected count}
    std::vector<std::pair<uint32_t,int>> tests = {
        {0b00000000000000000000000000001011u, 3}, // 11 -> 3 ones
        {0b00000000000000000000000010000000u, 1}, // 128 -> 1 one
        {0u, 0},                                  // 0 -> 0 ones
        {0xFFFFFFFFu, 32},                        // all ones -> 32
        {0x80000000u, 1},                         // highest bit only -> 1
        {0x7FFFFFFFu, 31}                         // all low 31 bits set -> 31
    };

    for (const auto &tc : tests) {
        uint32_t n = tc.first;
        int expected = tc.second;
        int actual = sol.hammingWeight(n);
        print_result(actual, expected);
    }

    return 0;
}
