#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    priority_queue<int> small;                             // max-heap
    priority_queue<int, vector<int>, greater<int>> large;  // min-heap
   public:
    Solution() {}
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        return (small.top() + large.top()) / 2.0;
    }
};

// Test scaffolding
int main() {
    Solution sol;
    sol.addNum(1);
    sol.addNum(2);
    cout << sol.findMedian() << " | " << 1.5 << endl;
    sol.addNum(3);
    cout << sol.findMedian() << " | " << 2.0 << endl;
    Solution sol2;
    for (int n : vector<int>{5, 3, 8, 9, 2}) sol2.addNum(n);
    cout << sol2.findMedian() << " | " << 5 << endl;
    Solution sol3;
    for (int n : vector<int>{10, 20, 30, 40}) sol3.addNum(n);
    cout << sol3.findMedian() << " | " << 25.0 << endl;
    Solution sol4;
    sol4.addNum(7);
    cout << sol4.findMedian() << " | " << 7 << endl;
    return 0;
}
