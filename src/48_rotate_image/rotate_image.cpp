#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = row + 1; col < matrix[row].size(); col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }

        for (auto& row : matrix) {
            for (int col = 0; col < row.size() / 2; col++) {
                int temp = row[col];
                row[col] = row[row.size() - 1 - col];
                row[row.size() - 1 - col] = temp;
            }
        }
    }
};

vector<vector<int>> cloneMatrix(const vector<vector<int>>& matrix) { return matrix; }

string formatMatrix(const vector<vector<int>>& matrix) {
    ostringstream out;
    out << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        out << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            out << matrix[i][j];
            if (j + 1 < matrix[i].size()) {
                out << ",";
            }
        }
        out << "]";
        if (i + 1 < matrix.size()) {
            out << ",";
        }
    }
    out << "]";
    return out.str();
}

int main() {
    Solution solution;

    vector<pair<vector<vector<int>>, vector<vector<int>>>> testCases = {
        {
            {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}},
        },
        {
            {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
            {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}},
        },
        {
            {{1}},
            {{1}},
        },
        {
            {{1, 2}, {3, 4}},
            {{3, 1}, {4, 2}},
        },
        {
            {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}},
            {{-7, -4, -1}, {-8, -5, -2}, {-9, -6, -3}},
        },
        {
            {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}},
            {{3, 2, 1}, {3, 2, 1}, {3, 2, 1}},
        },
    };

    for (const auto& [input, expected] : testCases) {
        vector<vector<int>> actual = cloneMatrix(input);
        solution.rotate(actual);
        cout << formatMatrix(actual) << " | " << formatMatrix(expected) << endl;
    }

    return 0;
}
