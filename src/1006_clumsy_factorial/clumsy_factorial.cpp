#include <iostream>
using namespace std;

class Solution {
   public:
    int clumsy(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;
        if (n == 4) return 7;
        if (n % 4 == 0) return n + 1;
        if (n % 4 == 1 || n % 4 == 2) return n + 2;
        return n - 1;
    }
};

// Test scaffolding
int main() {
    Solution sol;

    // Test case 1
    cout << sol.clumsy(4) << " | " << 7 << endl;

    // Test case 2
    cout << sol.clumsy(10) << " | " << 12 << endl;

    // Test case 3
    cout << sol.clumsy(1) << " | " << 1 << endl;

    // Test case 4
    cout << sol.clumsy(2) << " | " << 2 << endl;

    // Test case 5
    cout << sol.clumsy(3) << " | " << 6 << endl;

    // Test case 6
    cout << sol.clumsy(5) << " | " << 7 << endl;

    return 0;
}
