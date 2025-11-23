#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, 0, 0};

        for (int num : nums) {
            vector<int> temp(dp);
            for (int i : dp) {
                temp[(i + num) % 3] = max(temp[(i + num) % 3], i + num);
            }
            dp = temp;
        }

        return dp[0];
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {3, 6, 5, 1, 8};
    cout << s.maxSumDivThree(nums1) << " 18" << endl;
    vector<int> nums2 = {4};
    cout << s.maxSumDivThree(nums2) << " 0" << endl;
    vector<int> nums3 = {1, 2, 3, 4, 4};
    cout << s.maxSumDivThree(nums3) << " 12" << endl;
    return 0;
}
