#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        bool rowZero = false;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if (r > 0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        for (int r = 1; r < ROWS; r++) {
            for (int c = 1; c < COLS; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int r = 0; r < ROWS; r++) {
                matrix[r][0] = 0;
            }
        }

        if (rowZero) {
            for (int c = 0; c < COLS; c++) {
                matrix[0][c] = 0;
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
            {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
            {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}},
        },
        {
            {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
            {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}},
        },
        {
            {{1}},
            {{1}},
        },
        {
            {{0}},
            {{0}},
        },
        {
            {{1, 2, 3, 4}},
            {{1, 2, 3, 4}},
        },
        {
            {{1}, {0}, {3}},
            {{0}, {0}, {0}},
        },
    };

    for (const auto& [input, expected] : testCases) {
        vector<vector<int>> actual = cloneMatrix(input);
        solution.setZeroes(actual);
        cout << formatMatrix(actual) << " | " << formatMatrix(expected) << endl;
    }

    return 0;
}
