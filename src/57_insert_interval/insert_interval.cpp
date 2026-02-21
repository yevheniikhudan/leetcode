#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                for (int j = i; j < n; ++j) res.push_back(intervals[j]);
                return res;
            } else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

void printVec(const vector<vector<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<vector<int>> in1 = {{1, 3}, {6, 9}};
    vector<int> new1 = {2, 5};
    printVec(sol.insert(in1, new1));
    cout << " | [[1,5],[6,9]]" << endl;

    vector<vector<int>> in2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> new2 = {4, 8};
    printVec(sol.insert(in2, new2));
    cout << " | [[1,2],[3,10],[12,16]]" << endl;

    vector<vector<int>> in3 = {};
    vector<int> new3 = {5, 7};
    printVec(sol.insert(in3, new3));
    cout << " | [[5,7]]" << endl;

    vector<vector<int>> in4 = {{1, 5}};
    vector<int> new4 = {2, 3};
    printVec(sol.insert(in4, new4));
    cout << " | [[1,5]]" << endl;

    vector<vector<int>> in5 = {{1, 2}, {3, 4}};
    vector<int> new5 = {5, 6};
    printVec(sol.insert(in5, new5));
    cout << " | [[1,2],[3,4],[5,6]]" << endl;

    return 0;
}
