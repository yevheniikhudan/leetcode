#include <iostream>
using namespace std;

class Solution {
   public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; ++i) {
            int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }
};

// Test scaffolding
int main() {
    Solution sol;
    cout << sol.tribonacci(0) << endl;   // 0
    cout << sol.tribonacci(1) << endl;   // 1
    cout << sol.tribonacci(2) << endl;   // 1
    cout << sol.tribonacci(3) << endl;   // 2
    cout << sol.tribonacci(4) << endl;   // 4
    cout << sol.tribonacci(25) << endl;  // 1389537
    return 0;
}
