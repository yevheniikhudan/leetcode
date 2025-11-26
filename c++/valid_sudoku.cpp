#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> boxes(9, 0);

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char cell = board[row][col];
                if (cell == '.') {
                    continue;
                }

                int val = 1 << ((cell - '0') - 1);
                if (rows[row] & val || cols[col] & val || boxes[row / 3 * 3 + col / 3] & val) {
                    return false;
                }

                rows[row] |= val;
                cols[col] |= val;
                boxes[row / 3 * 3 + col / 3] |= val;
            }
        }

        return true;
    }
};

void test_valid_sudoku() {
    Solution solution;

    // Test case 1: Valid board
    vector<vector<char>> board1 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool result1 = solution.isValidSudoku(board1);
    cout << "Test 1: " << (result1 ? "true" : "false") << endl;
    assert(result1 == true);

    // Test case 2: Invalid board (duplicate in sub-box)
    vector<vector<char>> board2 = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool result2 = solution.isValidSudoku(board2);
    cout << "Test 2: " << (result2 ? "true" : "false") << endl;
    assert(result2 == false);

    // Test case 3: Invalid board (duplicate in row)
    vector<vector<char>> board3 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'5', '.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool result3 = solution.isValidSudoku(board3);
    cout << "Test 3: " << (result3 ? "true" : "false") << endl;
    assert(result3 == false);

    // Test case 4: All empty
    vector<vector<char>> board4 = {{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    bool result4 = solution.isValidSudoku(board4);
    cout << "Test 4: " << (result4 ? "true" : "false") << endl;
    assert(result4 == true);

    cout << "All test cases passed!" << endl;
}

int main() {
    test_valid_sudoku();
    return 0;
}
