#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.emplace(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

int main() {
    vector<pair<vector<int>, int>> tests = {{{3, 2, 1, 5, 6, 4}, 2},
                                            {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4},
                                            {{1}, 1},
                                            {{2, 1}, 2},
                                            {{7, 6, 5, 4, 3, 2, 1}, 5}};
    vector<int> expected = {5, 4, 1, 1, 3};
    Solution sol;
    for (int i = 0; i < tests.size(); ++i) {
        int actual = sol.findKthLargest(tests[i].first, tests[i].second);
        cout << actual << " | " << expected[i] << endl;
    }
    return 0;
}
