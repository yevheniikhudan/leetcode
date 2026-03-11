#include <iostream>
#include <vector>

class Solution {
   public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }

        int mask = 0;
        int value = n;

        while (value > 0) {
            mask = (mask << 1) | 1;
            value >>= 1;
        }

        return mask ^ n;
    }
};

void runTests() {
    Solution sol;
    std::vector<int> inputs = {5, 7, 10, 0, 1, 8};
    std::vector<int> expecteds = {2, 0, 5, 1, 0, 7};

    for (size_t i = 0; i < inputs.size(); ++i) {
        int actual = sol.bitwiseComplement(inputs[i]);
        std::cout << actual << " | " << expecteds[i] << std::endl;
    }
}

int main() {
    runTests();
    return 0;
}