#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<double, int, int>> pq;

        for (auto& point : points) {
            double dist = pow(point[0], 2) + pow(point[1], 2);

            pq.emplace(dist, point[0], point[1]);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            auto [dist, x, y] = pq.top();
            pq.pop();
            res.push_back({x, y});
        }
        return res;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> tests = {{{{1, 3}, {-2, 2}}, 1},
                                                    {{{3, 3}, {5, -1}, {-2, 4}}, 2},
                                                    {{{0, 1}, {1, 0}}, 2},
                                                    {{{2, 2}, {2, 2}, {2, 2}}, 2},
                                                    {{{1, 2}, {2, 1}, {0, 0}}, 1}};
    vector<vector<vector<int>>> expected = {
        {{-2, 2}}, {{3, 3}, {-2, 4}}, {{0, 1}, {1, 0}}, {{2, 2}, {2, 2}}, {{0, 0}}};
    Solution sol;
    for (int i = 0; i < tests.size(); ++i) {
        auto actual = sol.kClosest(tests[i].first, tests[i].second);
        cout << "[";
        for (size_t j = 0; j < actual.size(); ++j) {
            cout << "[" << actual[j][0] << "," << actual[j][1] << "]";
            if (j + 1 < actual.size()) cout << ",";
        }
        cout << "] | [";
        for (size_t j = 0; j < expected[i].size(); ++j) {
            cout << "[" << expected[i][j][0] << "," << expected[i][j][1] << "]";
            if (j + 1 < expected[i].size()) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
