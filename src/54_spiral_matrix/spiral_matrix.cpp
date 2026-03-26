#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();

        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i < bottom; i++) {
                res.push_back(matrix[i][right - 1]);
            }
            right--;
            if (!(left < right && top < bottom)) {
                break;
            }
            for (int i = right - 1; i >= left; i--) {
                res.push_back(matrix[bottom - 1][i]);
            }
            bottom--;
            for (int i = bottom - 1; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};

string formatResult(const vector<int>& result) {
    ostringstream out;
    out << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        out << result[i];
        if (i + 1 < result.size()) {
            out << ",";
        }
    }
    out << "]";
    return out.str();
}

int main() {
    Solution solution;

    vector<pair<vector<vector<int>>, vector<int>>> testCases = {
        {
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            {1, 2, 3, 6, 9, 8, 7, 4, 5},
        },
        {
            {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
            {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7},
        },
        {
            {{1}},
            {1},
        },
        {
            {{1, 2, 3, 4, 5}},
            {1, 2, 3, 4, 5},
        },
        {
            {{1}, {2}, {3}, {4}, {5}},
            {1, 2, 3, 4, 5},
        },
        {
            {{1, 2}, {3, 4}},
            {1, 2, 4, 3},
        },
    };

    for (const auto& [input, expected] : testCases) {
        vector<vector<int>> actual_input = input;
        vector<int> actual = solution.spiralOrder(actual_input);
        cout << formatResult(actual) << " | " << formatResult(expected) << endl;
    }

    return 0;
}
