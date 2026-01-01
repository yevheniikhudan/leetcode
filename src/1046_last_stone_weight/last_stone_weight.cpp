#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Returns the weight of the last remaining stone (or 0 if none remain).
     */
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            if (s1 != s2) {
                pq.push(s1 - s2);
            }
        }

        return pq.size() > 0 ? pq.top() : 0;
    }
};

// Helper for testing
int main() {
    Solution sol;
    vector<int> t1 = {2, 7, 4, 1, 8, 1};
    cout << sol.lastStoneWeight(t1) << endl;  // 1
    vector<int> t2 = {1};
    cout << sol.lastStoneWeight(t2) << endl;  // 1
    vector<int> t3 = {3, 3, 3, 3};
    cout << sol.lastStoneWeight(t3) << endl;  // 0
    vector<int> t4 = {10, 4, 2, 10};
    cout << sol.lastStoneWeight(t4) << endl;  // 2
    vector<int> t5 = {5, 5, 5, 1};
    cout << sol.lastStoneWeight(t5) << endl;  // 2
    return 0;
}
