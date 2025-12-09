#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen = {};

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }

            seen.insert(num);
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << (s.containsDuplicate(nums1) ? "true" : "false") << " true" << endl;
    vector<int> nums2 = {1, 2, 3, 4};
    cout << (s.containsDuplicate(nums2) ? "true" : "false") << " false" << endl;
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << (s.containsDuplicate(nums3) ? "true" : "false") << " true" << endl;
    return 0;
}
