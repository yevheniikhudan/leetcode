#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int coursesFinished = 0;
        while (!q.empty()) {
            int course = q.front(); q.pop();
            coursesFinished++;
            for (int adj : adjList[course]) {
                if (inEdges[adj] > 0) inEdges[adj]--;
                if (inEdges[adj] == 0) q.push(adj);
            }
        }
        return coursesFinished == numCourses;
    }
};

// Test scaffolding
void test() {
    Solution sol;
    vector<vector<int>> p1 = {{1,0}};
    cout << boolalpha << sol.canFinish(2, p1) << " | true" << endl;
    vector<vector<int>> p2 = {{1,0},{0,1}};
    cout << boolalpha << sol.canFinish(2, p2) << " | false" << endl;
    vector<vector<int>> p3 = {};
    cout << boolalpha << sol.canFinish(1, p3) << " | true" << endl;
    vector<vector<int>> p4 = {{1,0},{2,1}};
    cout << boolalpha << sol.canFinish(3, p4) << " | true" << endl;
    vector<vector<int>> p5 = {{1,0},{0,2},{2,1}};
    cout << boolalpha << sol.canFinish(3, p5) << " | false" << endl;
}

int main() {
    test();
    return 0;
}
