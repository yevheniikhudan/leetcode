#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};

int main() {
    Solution sol;
    vector<int> g1 = {1, 2, 3, 4, 5};
    vector<int> c1 = {3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(g1, c1) << " | 3" << endl;
    vector<int> g2 = {2, 3, 4};
    vector<int> c2 = {3, 4, 3};
    cout << sol.canCompleteCircuit(g2, c2) << " | -1" << endl;
    vector<int> g3 = {5};
    vector<int> c3 = {4};
    cout << sol.canCompleteCircuit(g3, c3) << " | 0" << endl;
    vector<int> g4 = {0, 0};
    vector<int> c4 = {0, 0};
    cout << sol.canCompleteCircuit(g4, c4) << " | 0" << endl;
    vector<int> g5 = {1, 2, 3, 4};
    vector<int> c5 = {2, 2, 2, 2};
    cout << sol.canCompleteCircuit(g5, c5) << " | 1" << endl;
    return 0;
}
