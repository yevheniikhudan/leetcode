#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        int jumps = 0, end = 0, farthest = 0;
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == end) {
                ++jumps;
                end = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    Solution sol;
    vector<int> a1 = {2, 3, 1, 1, 4};
    cout << sol.jump(a1) << " | 2" << endl;
    vector<int> a2 = {2, 3, 0, 1, 4};
    cout << sol.jump(a2) << " | 2" << endl;
    vector<int> a3 = {0};
    cout << sol.jump(a3) << " | 0" << endl;
    vector<int> a4 = {1, 2};
    cout << sol.jump(a4) << " | 1" << endl;
    vector<int> a5 = {2, 3, 1, 1, 4, 0, 0};
    cout << sol.jump(a5) << " | 2" << endl;
    return 0;
}
