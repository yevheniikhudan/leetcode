#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int res = 0;
        int p1 = -1, p2 = -1;

        for (const auto& interval : intervals) {
            int left = interval[0], right = interval[1];

            if (p2 < left) {
                p1 = right - 1;
                p2 = right;
                res += 2;
            } else if (p1 < left) {
                p1 = p2;
                p2 = right;
                res += 1;
            }
        }
        return res;
    }

   private:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return b[0] < a[0];
        }

        return a[1] < b[1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals1 = {{1, 3}, {3, 7}, {8, 9}};
    cout << s.intersectionSizeTwo(intervals1) << " 5" << endl;
    vector<vector<int>> intervals2 = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    cout << s.intersectionSizeTwo(intervals2) << " 3" << endl;
    vector<vector<int>> intervals3 = {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
    cout << s.intersectionSizeTwo(intervals3) << " 5" << endl;
    return 0;
}
