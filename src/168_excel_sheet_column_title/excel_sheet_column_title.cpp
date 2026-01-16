#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber > 0) {
            int offset = (columnNumber - 1) % 26;
            res += char('A' + offset);
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(1) << " | A" << endl;
    cout << s.convertToTitle(28) << " | AB" << endl;
    cout << s.convertToTitle(701) << " | ZY" << endl;
    cout << s.convertToTitle(52) << " | AZ" << endl;
    cout << s.convertToTitle(2147483647) << " | FXSHRXW" << endl;
    return 0;
}
