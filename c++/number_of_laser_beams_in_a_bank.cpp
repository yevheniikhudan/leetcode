#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int result = 0;

        for (string lasers : bank) {
            int cur = 0;

            for (char c : lasers) {
                if (c == '1') {
                    cur++;
                }
            }
            if (cur == 0) continue;

            result += cur * prev;
            prev = cur;
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<string> bank1 = {"011001", "000000", "010100", "001000"};
    cout << s.numberOfBeams(bank1) << " Expected: 8" << endl;

    vector<string> bank2 = {"000", "111", "000"};
    cout << s.numberOfBeams(bank2) << " Expected: 0" << endl;

    return 0;
}
