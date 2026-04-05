#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        dp.push_back(0);

        for (int i = 1; i <= n; i++) {
            dp.push_back(dp[i / 2] + (i % 2));
        }

        return dp;
    }
};

static void print_vector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]";
}

static void print_result(const std::vector<int>& actual, const std::vector<int>& expected) {
    print_vector(actual);
    std::cout << " | ";
    print_vector(expected);
    std::cout << " | ";
    std::cout << (actual == expected ? "PASS" : "FAIL") << "\n";
}

int main() {
    Solution sol;

    // Test cases: {input n, expected output vector}
    std::vector<std::pair<int, std::vector<int>>> tests = {
        {2, {0, 1, 1}},
        {5, {0, 1, 1, 2, 1, 2}},
        {0, {0}},
        {1, {0, 1}},
        {10, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2}}
    };

    for (const auto& tc : tests) {
        int n = tc.first;
        const std::vector<int>& expected = tc.second;
        std::vector<int> actual = sol.countBits(n);
        print_result(actual, expected);
    }

    return 0;
}
