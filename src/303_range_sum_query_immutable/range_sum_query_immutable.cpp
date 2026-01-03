#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    vector<int> prefix;

   public:
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
    }
    int sumRange(int left, int right) {
        int sum = prefix[right];
        if (left > 0) sum -= prefix[left - 1];

        return sum;
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    vector<pair<pair<int, int>, int>> tests = {
        {{0, 2}, 1}, {{2, 5}, -1}, {{0, 5}, -3}, {{3, 3}, -5}, {{1, 1}, 0}};
    for (auto& [query, expected] : tests) {
        int actual = numArray.sumRange(query.first, query.second);
        cout << actual << " | " << expected << endl;
    }
    return 0;
}
