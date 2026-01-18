#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inEdges(numCourses, 0);
        for (const auto& pair : prerequisites) {
            int dest = pair[0], src = pair[1];
            inEdges[dest]++;
            adjList[src].push_back(dest);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inEdges[i] == 0) q.push(i);
        }
        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (int adj : adjList[course]) {
                if (inEdges[adj] > 0) inEdges[adj]--;
                if (inEdges[adj] == 0) q.push(adj);
            }
        }
        if (order.size() == numCourses) return order;
        return {};
    }
};

// Test scaffolding
void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

void test() {
    Solution sol;
    vector<vector<int>> p1 = {{1, 0}};
    printVec(sol.findOrder(2, p1));
    cout << " | [0, 1]" << endl;
    vector<vector<int>> p2 = {{1, 0}, {0, 1}};
    printVec(sol.findOrder(2, p2));
    cout << " | []" << endl;
    vector<vector<int>> p3 = {};
    printVec(sol.findOrder(1, p3));
    cout << " | [0]" << endl;
    vector<vector<int>> p4 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    printVec(sol.findOrder(4, p4));
    cout << " | [0,2,1,3] or [0,1,2,3]" << endl;
    vector<vector<int>> p5 = {{1, 0}, {0, 2}, {2, 1}};
    printVec(sol.findOrder(3, p5));
    cout << " | []" << endl;
}

int main() {
    test();
    return 0;
}
