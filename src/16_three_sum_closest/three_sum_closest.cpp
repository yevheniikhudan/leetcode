#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int bestSum = 0;
        int bestDistance = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (currentSum == target) {
                    return currentSum;
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }

                int currentDistance = abs(currentSum - target);
                if (currentDistance < bestDistance) {
                    bestDistance = currentDistance;
                    bestSum = currentSum;
                }
            }
        }

        return bestSum;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << s.threeSumClosest(nums1, target1) << " Expected: 2" << endl;

    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << s.threeSumClosest(nums2, target2) << " Expected: 0" << endl;

    return 0;
}
