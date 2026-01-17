#include <iostream>
using namespace std;

class Solution {
   public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;
    cout << boolalpha << sol.isPowerOfFour(16) << " | True" << endl;
    cout << boolalpha << sol.isPowerOfFour(5) << " | False" << endl;
    cout << boolalpha << sol.isPowerOfFour(1) << " | True" << endl;
    cout << boolalpha << sol.isPowerOfFour(64) << " | True" << endl;
    cout << boolalpha << sol.isPowerOfFour(0) << " | False" << endl;
    cout << boolalpha << sol.isPowerOfFour(-4) << " | False" << endl;
    return 0;
}
