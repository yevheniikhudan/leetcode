#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) dec = false;
            if (nums[i] < nums[i - 1]) inc = false;
        }
        return inc || dec;
    }
};

void test() {
    Solution sol;
    vector<vector<int>> tests = {{1, 2, 2, 3}, {6, 5, 4, 4}, {1, 3, 2}, {1, 1, 1}, {1}, {}};
    vector<string> expected = {"True", "True", "False", "True", "True", "True"};
    for (int i = 0; i < tests.size(); ++i) {
        cout << boolalpha << sol.isMonotonic(tests[i]) << " | " << expected[i] << endl;
    }
}

int main() {
    test();
    return 0;
}
