public class ValidPalindrome {
    /**
     * Valid Palindrome
     *
     * @param s String to check
     * @return True if palindrome, False otherwise
     */
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !isAlphaNum(s.charAt(left))) {
                left += 1;
            }
            while (left < right && !isAlphaNum(s.charAt(right))) {
                right -= 1;
            }

            if (Character.toLowerCase(s.charAt(left++)) != Character.toLowerCase(s.charAt(right--))) {
                return false;
            }
        }
        return true;
    }

    private boolean isAlphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }

    public static void main(String[] args) {
        ValidPalindrome solution = new ValidPalindrome();

        // Test case 1
        String s1 = "A man, a plan, a canal: Panama";
        boolean result1 = solution.isPalindrome(s1);
        System.out.println("Test 1: '" + s1 + "' -> " + result1);
        assert result1 == true : "Expected true, got " + result1;

        // Test case 2
        String s2 = "race a car";
        boolean result2 = solution.isPalindrome(s2);
        System.out.println("Test 2: '" + s2 + "' -> " + result2);
        assert result2 == false : "Expected false, got " + result2;

        // Test case 3
        String s3 = " ";
        boolean result3 = solution.isPalindrome(s3);
        System.out.println("Test 3: '" + s3 + "' -> " + result3);
        assert result3 == true : "Expected true, got " + result3;

        // Test case 4: Single character
        String s4 = "a";
        boolean result4 = solution.isPalindrome(s4);
        System.out.println("Test 4: '" + s4 + "' -> " + result4);
        assert result4 == true : "Expected true, got " + result4;

        // Test case 5: With numbers
        String s5 = "0P";
        boolean result5 = solution.isPalindrome(s5);
        System.out.println("Test 5: '" + s5 + "' -> " + result5);
        assert result5 == false : "Expected false, got " + result5;

        // Test case 6: Empty after filtering
        String s6 = ".,;";
        boolean result6 = solution.isPalindrome(s6);
        System.out.println("Test 6: '" + s6 + "' -> " + result6);
        assert result6 == true : "Expected true, got " + result6;

        System.out.println("All test cases passed!");
    }
}
