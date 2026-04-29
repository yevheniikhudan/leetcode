#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> indices;
        for (int i = 0; i < keyboard.length(); i++) {
            indices[keyboard[i]] = i;
        }

        int ans = indices[word[0]];
        for (int i = 1; i < word.length(); i++) {
            ans += abs(indices[word[i-1]] - indices[word[i]]);
        }
        return ans;
    }
};

// Helper function for testing
void testSolution() {
    Solution solution;

    // Test case 1
    string keyboard1 = "abcdefghijklmnopqrstuvwxyz";
    string word1 = "cba";
    int result1 = solution.calculateTime(keyboard1, word1);
    int expected1 = 4;
    cout << "Test 1: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test case 2
    string keyboard2 = "pqrstuvwxyzabcdefghijklmno";
    string word2 = "leetcode";
    int result2 = solution.calculateTime(keyboard2, word2);
    int expected2 = 73;
    cout << "Test 2: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test case 3
    string keyboard3 = "abcdefghijklmnopqrstuvwxyz";
    string word3 = "abc";
    int result3 = solution.calculateTime(keyboard3, word3);
    int expected3 = 2;
    cout << "Test 3: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test case 4
    string keyboard4 = "abcdefghijklmnopqrstuvwxyz";
    string word4 = "a";
    int result4 = solution.calculateTime(keyboard4, word4);
    int expected4 = 0;
    cout << "Test 4: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test case 5
    string keyboard5 = "zyxwvutsrqponmlkjihgfedcba";
    string word5 = "z";
    int result5 = solution.calculateTime(keyboard5, word5);
    int expected5 = 25;
    cout << "Test 5: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

int main() {
    testSolution();
    return 0;
}
