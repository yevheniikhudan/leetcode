#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // ...existing code...
        return {};
    }
};

void printVector(vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution s;
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    auto result1 = s.topKFrequent(nums1, k1);
    printVector(result1);

    vector<int> nums2 = {1};
    int k2 = 1;
    auto result2 = s.topKFrequent(nums2, k2);
    printVector(result2);

    return 0;
}
