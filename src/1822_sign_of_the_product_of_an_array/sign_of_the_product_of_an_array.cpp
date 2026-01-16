#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int num : nums) {
            if (num == 0) return 0;
            if (num < 0) sign = -sign;
        }
        return sign;
    }
};

// Test scaffolding
int main() {
    Solution sol;
    cout << sol.arraySign(vector<int>{1, -2, -3, 4}) << " | 1" << endl;
    cout << sol.arraySign(vector<int>{1, 5, 0, 2, -3}) << " | 0" << endl;
    cout << sol.arraySign(vector<int>{-1, 1, -1, 1, -1}) << " | -1" << endl;
    cout << sol.arraySign(vector<int>{2, 3, 4, 5}) << " | 1" << endl;
    cout << sol.arraySign(vector<int>{-2, -3, -4}) << " | -1" << endl;
    return 0;
}
