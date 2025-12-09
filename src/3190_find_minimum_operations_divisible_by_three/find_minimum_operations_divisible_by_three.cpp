#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            if (num % 3 != 0) {
                ans += 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4};
    cout << s.minimumOperations(nums1) << " 3" << endl;
    vector<int> nums2 = {3, 6, 9};
    cout << s.minimumOperations(nums2) << " 0" << endl;
    return 0;
}
