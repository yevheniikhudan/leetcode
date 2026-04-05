#include <iostream>
#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= n & 1;
            n >>= 1;
        }

        return res;
    }
};

// ---------- Test Helpers ----------

void check(uint32_t actual, uint32_t expected, const std::string& label) {
    bool ok = actual == expected;
    std::cout << actual << " | " << expected << " | "
              << (ok ? "PASS" : "FAIL")
              << " (" << label << ")\n";
}

// ---------- Tests ----------

int main() {
    Solution sol;

    check(sol.reverseBits(43261596), 964176192, "Example 1");
    check(sol.reverseBits(4294967293), 3221225471, "Example 2");
    check(sol.reverseBits(0), 0, "All zeros");
    check(sol.reverseBits(1), 2147483648, "Single bit at position 0");
    check(sol.reverseBits(2147483648), 1, "Single bit at position 31");
    check(sol.reverseBits(4294967295), 4294967295, "All ones");
    check(sol.reverseBits(2), 1073741824, "00000000000000000000000000000010");

    return 0;
}
