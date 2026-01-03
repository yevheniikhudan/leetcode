#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counter;
        for (char t : tasks) counter[t]++;
        priority_queue<int> maxHeap;
        for (auto& p : counter) maxHeap.push(p.second);
        queue<pair<int, int>> q;  // {count, nextAvailableTime}
        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) q.push({cnt, time + n});
            }
            if (!q.empty() && q.front().second <= time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

int main() {
    vector<pair<vector<char>, int>> tests = {
        {{'A', 'A', 'A', 'B', 'B', 'B'}, 2},
        {{'A', 'A', 'A', 'B', 'B', 'B'}, 0},
        {{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 2},
        {{'A'}, 100},
        {{'A', 'B', 'C', 'D'}, 2}};
    vector<int> expected = {8, 6, 16, 1, 4};
    Solution sol;
    for (int i = 0; i < tests.size(); ++i) {
        int actual = sol.leastInterval(tests[i].first, tests[i].second);
        cout << actual << " | " << expected[i] << endl;
    }
    return 0;
}
