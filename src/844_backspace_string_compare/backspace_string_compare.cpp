#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int indexS = s.size() - 1, indexT = t.size() - 1;
        while (indexS >= 0 || indexT >= 0) {
            indexS = nextValidChar(s, indexS);
            indexT = nextValidChar(t, indexT);
            char charS = indexS >= 0 ? s[indexS] : 0;
            char charT = indexT >= 0 ? t[indexT] : 0;
            if (charS != charT) return false;
            indexS--;
            indexT--;
        }
        return true;
    }
    int nextValidChar(const string& st, int index) {
        int backspace = 0;
        while (index >= 0) {
            if (backspace == 0 && st[index] != '#') {
                break;
            } else if (st[index] == '#') {
                backspace++;
            } else {
                backspace--;
            }
            index--;
        }
        return index;
    }
};

int main() {
    Solution sol;
    cout << boolalpha << sol.backspaceCompare("ab#c", "ad#c") << " | True" << endl;
    cout << boolalpha << sol.backspaceCompare("ab##", "c#d#") << " | True" << endl;
    cout << boolalpha << sol.backspaceCompare("a#c", "b") << " | False" << endl;
    cout << boolalpha << sol.backspaceCompare("a##b", "#a#b") << " | True" << endl;
    cout << boolalpha << sol.backspaceCompare("", "") << " | True" << endl;
    return 0;
}
