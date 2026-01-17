#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0;
        for (int num : nums) {
            res += count[num];
            count[num]++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> t1 = {1, 2, 3, 1, 1, 3};
    cout << sol.numIdenticalPairs(t1) << " | 4" << endl;
    vector<int> t2 = {1, 1, 1, 1};
    cout << sol.numIdenticalPairs(t2) << " | 6" << endl;
    vector<int> t3 = {1, 2, 3};
    cout << sol.numIdenticalPairs(t3) << " | 0" << endl;
    vector<int> t4 = {};
    cout << sol.numIdenticalPairs(t4) << " | 0" << endl;
    vector<int> t5 = {2, 2, 2, 2, 2};
    cout << sol.numIdenticalPairs(t5) << " | 10" << endl;
    return 0;
}
