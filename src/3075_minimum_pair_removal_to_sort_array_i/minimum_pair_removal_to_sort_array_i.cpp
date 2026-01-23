#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> arr(nums);
        int count = 0;
        while (true) {
            int n = arr.size();
            if (n <= 1) break;
            bool sorted = true;
            for (int i = 0; i < n - 1; ++i) {
                if (arr[i] > arr[i + 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) break;
            int minSum = INT_MAX, minIdx = -1;
            for (int i = 0; i < n - 1; ++i) {
                int pairSum = arr[i] + arr[i + 1];
                if (pairSum < minSum) {
                    minSum = pairSum;
                    minIdx = i;
                }
            }
            arr[minIdx] = arr[minIdx] + arr[minIdx + 1];
            arr.erase(arr.begin() + minIdx + 1);
            ++count;
        }
        return count;
    }
};

// Test scaffolding
void test() {
    Solution sol;
    vector<int> v1 = {5, 2, 3, 1};
    cout << sol.minimumPairRemoval(v1) << " | 2\n";
    vector<int> v2 = {1, 2, 2};
    cout << sol.minimumPairRemoval(v2) << " | 0\n";
    vector<int> v3 = {1};
    cout << sol.minimumPairRemoval(v3) << " | 0\n";
    vector<int> v4 = {2, 1};
    cout << sol.minimumPairRemoval(v4) << " | 1\n";
    vector<int> v5 = {3, 1, 2};
    cout << sol.minimumPairRemoval(v5) << " | 1\n";
}

int main() {
    test();
    return 0;
}
