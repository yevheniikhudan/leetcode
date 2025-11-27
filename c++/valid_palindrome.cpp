#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    /**
     * Valid Palindrome
     *
     * @param s String to check
     * @return True if palindrome, False otherwise
     */
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isAlphaNum(s[left])) {
                left += 1;
            }
            while (left < right && !isAlphaNum(s[right])) {
                right -= 1;
            }
            if (tolower(s[left++]) != tolower(s[right--])) {
                return false;
            }
        }
        return true;
    }

   private:
    bool isAlphaNum(char c) {
        return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
    }
};

void test_valid_palindrome() {
    Solution solution;

    // Test case 1
    string s1 = "A man, a plan, a canal: Panama";
    bool result1 = solution.isPalindrome(s1);
    cout << "Test 1: '" << s1 << "' -> " << (result1 ? "true" : "false") << endl;
    assert(result1 == true);

    // Test case 2
    string s2 = "race a car";
    bool result2 = solution.isPalindrome(s2);
    cout << "Test 2: '" << s2 << "' -> " << (result2 ? "true" : "false") << endl;
    assert(result2 == false);

    // Test case 3
    string s3 = " ";
    bool result3 = solution.isPalindrome(s3);
    cout << "Test 3: '" << s3 << "' -> " << (result3 ? "true" : "false") << endl;
    assert(result3 == true);

    // Test case 4: Single character
    string s4 = "a";
    bool result4 = solution.isPalindrome(s4);
    cout << "Test 4: '" << s4 << "' -> " << (result4 ? "true" : "false") << endl;
    assert(result4 == true);

    // Test case 5: With numbers
    string s5 = "0P";
    bool result5 = solution.isPalindrome(s5);
    cout << "Test 5: '" << s5 << "' -> " << (result5 ? "true" : "false") << endl;
    assert(result5 == false);

    // Test case 6: Empty after filtering
    string s6 = ".,;";
    bool result6 = solution.isPalindrome(s6);
    cout << "Test 6: '" << s6 << "' -> " << (result6 ? "true" : "false") << endl;
    assert(result6 == true);

    cout << "All test cases passed!" << endl;
}

int main() {
    test_valid_palindrome();
    return 0;
}
