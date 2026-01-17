#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

void printVec(const vector<char>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    vector<char> arr1 = {'h','e','l','l','o'}; sol.reverseString(arr1); printVec(arr1); cout << " | [o, l, l, e, h]" << endl;
    vector<char> arr2 = {'a'}; sol.reverseString(arr2); printVec(arr2); cout << " | [a]" << endl;
    vector<char> arr3 = {}; sol.reverseString(arr3); printVec(arr3); cout << " | []" << endl;
    vector<char> arr4 = {'a','b'}; sol.reverseString(arr4); printVec(arr4); cout << " | [b, a]" << endl;
    vector<char> arr5 = {'r','a','c','e','c','a','r'}; sol.reverseString(arr5); printVec(arr5); cout << " | [r, a, c, e, c, a, r]" << endl;
    return 0;
}
