#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int line = 1; line <= rowIndex; ++line) {
            vector<int> nextLine(line + 1, 0);
            for (int i = 0; i < res.size(); ++i) {
                nextLine[i] += res[i];
                nextLine[i + 1] += res[i];
            }
            res = nextLine;
        }
        return res;
    }
};

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    printVec(sol.getRow(3));
    cout << " | [1, 3, 3, 1]" << endl;
    printVec(sol.getRow(0));
    cout << " | [1]" << endl;
    printVec(sol.getRow(1));
    cout << " | [1, 1]" << endl;
    printVec(sol.getRow(4));
    cout << " | [1, 4, 6, 4, 1]" << endl;
    printVec(sol.getRow(5));
    cout << " | [1, 5, 10, 10, 5, 1]" << endl;
    return 0;
}
