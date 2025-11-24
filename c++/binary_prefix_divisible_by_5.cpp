#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int cur = 0;

        for (int num : nums) {
            cur = (cur * 2 + num) % 5;

            ans.push_back(cur % 5 == 0);
        }
        return ans;
    }
};

void printVector(vector<bool>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << (vec[i] ? "true" : "false");
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    vector<int> nums1 = {0, 1, 1};
    auto result1 = s.prefixesDivBy5(nums1);
    printVector(result1);

    vector<int> nums2 = {1, 1, 1};
    auto result2 = s.prefixesDivBy5(nums2);
    printVector(result2);

    return 0;
}
