#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for (int h : hand) count[h]++;
        while (!count.empty()) {
            int start = count.begin()->first;
            int cnt = count.begin()->second;
            for (int i = 0; i < groupSize; ++i) {
                int key = start + i;
                if (!count.count(key)) return false;
                if (count[key] < cnt) return false;
                count[key] -= cnt;
                if (count[key] == 0) count.erase(key);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> h1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << (sol.isNStraightHand(h1, 3) ? "True" : "False") << " | True" << endl;
    vector<int> h2 = {1, 2, 3, 4, 5};
    cout << (sol.isNStraightHand(h2, 4) ? "True" : "False") << " | False" << endl;
    vector<int> h3 = {1, 1, 2, 2, 3, 3};
    cout << (sol.isNStraightHand(h3, 3) ? "True" : "False") << " | True" << endl;
    vector<int> h4 = {1, 2, 3, 4};
    cout << (sol.isNStraightHand(h4, 2) ? "True" : "False") << " | True" << endl;
    vector<int> h5 = {1};
    cout << (sol.isNStraightHand(h5, 1) ? "True" : "False") << " | True" << endl;
    return 0;
}
