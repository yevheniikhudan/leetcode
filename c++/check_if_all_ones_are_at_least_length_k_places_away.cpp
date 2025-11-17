#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        int previousId = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (previousId != -1 && nums[i] == 1 && i - previousId - 1 < k) {
                return false;
            }

            if (nums[i] == 1) {
                previousId = i;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 0, 0, 0, 1, 0, 0, 1};
    int k1 = 2;
    cout << (s.kLengthApart(nums1, k1) ? "true" : "false") << " true" << endl;
    vector<int> nums2 = {1, 0, 0, 1, 0, 1};
    int k2 = 2;
    cout << (s.kLengthApart(nums2, k2) ? "true" : "false") << " false" << endl;
    vector<int> nums3 = {0, 1, 0, 1};
    int k3 = 1;
    cout << (s.kLengthApart(nums3, k3) ? "true" : "false") << " true" << endl;
    return 0;
}
