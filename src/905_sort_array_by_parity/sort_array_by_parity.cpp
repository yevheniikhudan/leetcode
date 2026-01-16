#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int insertIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                int temp = nums[insertIndex];
                nums[insertIndex] = nums[i];
                nums[i] = temp;
                insertIndex++;
            }
        }
        return nums;
    }
};

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    vector<int> t1 = {3,1,2,4}; printVec(sol.sortArrayByParity(t1)); cout << " | [2, 4, 3, 1]" << endl;
    vector<int> t2 = {0}; printVec(sol.sortArrayByParity(t2)); cout << " | [0]" << endl;
    vector<int> t3 = {1,2,3,4,5,6}; printVec(sol.sortArrayByParity(t3)); cout << " | [2, 4, 6, 1, 3, 5]" << endl;
    vector<int> t4 = {2,4,6,8}; printVec(sol.sortArrayByParity(t4)); cout << " | [2, 4, 6, 8]" << endl;
    vector<int> t5 = {1,3,5,7}; printVec(sol.sortArrayByParity(t5)); cout << " | [1, 3, 5, 7]" << endl;
    return 0;
}
