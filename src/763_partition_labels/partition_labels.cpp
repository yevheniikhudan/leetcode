#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> partitionLabels(string S) {
        vector<int> lastIndex(26, 0);
        int n = S.size();

        for (int i = 0; i < n; i++) {
            lastIndex[S[i] - 'a'] = i;
        }

        int start = 0, end = 0;
        vector<int> partitions;
        for (int i = 0; i < n; i++) {
            end = max(end, lastIndex[S[i] - 'a']);

            if (i == end) {
                partitions.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return partitions;
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

    string s1 = "ababcbacadefegdehijhklij";
    printVec(sol.partitionLabels(s1));
    cout << " | [9, 7, 8]" << endl;

    string s2 = "eccbbbbdec";
    printVec(sol.partitionLabels(s2));
    cout << " | [10]" << endl;

    string s3 = "qwerty";
    printVec(sol.partitionLabels(s3));
    cout << " | [1,1,1,1,1,1]" << endl;

    string s4 = "abca";
    printVec(sol.partitionLabels(s4));
    cout << " | [4]" << endl;

    string s5 = "";
    printVec(sol.partitionLabels(s5));
    cout << " | []" << endl;

    return 0;
}
