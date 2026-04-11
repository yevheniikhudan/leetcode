#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Find the length of the last word in a string.
     *
     * A word is a maximal substring consisting of non-space characters only.
     *
     * @param s A string consisting of words and spaces (1 <= s.length <= 10^4)
     * @return The length of the last word in the string
     */
    int lengthOfLastWord(string s) {
        int right = s.length() - 1;
        while (s[right] == ' ') right--;
        int left = right;
        while (left > 0 && s[left] != ' ') left--;
        if (s[left] == ' ') left++;

        return right - left + 1;
    }
};

/**
 * Helper function to run a single test case
 */
void runTest(int result, int expected, const string& testDescription) {
    string status = (result == expected) ? "PASS" : "FAIL";
    cout << result << " | " << expected << " | " << status << endl;
}

/**
 * Main function with test cases
 */
int main() {
    Solution solution;

    // Test case 1: Basic example with two words
    string test1 = "Hello World";
    int result1 = solution.lengthOfLastWord(test1);
    int expected1 = 5;
    cout << "Test 1 (\"Hello World\"): ";
    runTest(result1, expected1, "Two words");

    // Test case 2: String with leading and trailing spaces
    string test2 = "   fly me   to   the moon  ";
    int result2 = solution.lengthOfLastWord(test2);
    int expected2 = 4;
    cout << "Test 2 (\"   fly me   to   the moon  \"): ";
    runTest(result2, expected2, "Multiple spaces and trailing spaces");

    // Test case 3: Multiple words with consistent spacing
    string test3 = "luffy is still joyboy";
    int result3 = solution.lengthOfLastWord(test3);
    int expected3 = 6;
    cout << "Test 3 (\"luffy is still joyboy\"): ";
    runTest(result3, expected3, "Multiple words");

    // Test case 4: Single character
    string test4 = "a";
    int result4 = solution.lengthOfLastWord(test4);
    int expected4 = 1;
    cout << "Test 4 (\"a\"): ";
    runTest(result4, expected4, "Single character");

    // Test case 5: Single word with trailing spaces
    string test5 = "hello   ";
    int result5 = solution.lengthOfLastWord(test5);
    int expected5 = 5;
    cout << "Test 5 (\"hello   \"): ";
    runTest(result5, expected5, "Single word with trailing spaces");

    // Test case 6: Single word with leading spaces
    string test6 = "    world";
    int result6 = solution.lengthOfLastWord(test6);
    int expected6 = 5;
    cout << "Test 6 (\"    world\"): ";
    runTest(result6, expected6, "Single word with leading spaces");

    // Test case 7: Multiple consecutive spaces between words
    string test7 = "a  b  c";
    int result7 = solution.lengthOfLastWord(test7);
    int expected7 = 1;
    cout << "Test 7 (\"a  b  c\"): ";
    runTest(result7, expected7, "Multiple consecutive spaces");

    // Test case 8: Word with spaces around it
    string test8 = "  world  ";
    int result8 = solution.lengthOfLastWord(test8);
    int expected8 = 5;
    cout << "Test 8 (\"  world  \"): ";
    runTest(result8, expected8, "Word with surrounding spaces");

    return 0;
}
