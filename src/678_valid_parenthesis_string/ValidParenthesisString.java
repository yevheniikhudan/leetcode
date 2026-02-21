import java.util.*;

class Solution {
    public Boolean checkValidString(String s) {
        int low = 0, high = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                low = Math.max(0, low - 1);
                high++;
            } else if (ch == ')') {
                low = Math.max(0, low - 1);
                high--;
            } else {
                low = Math.max(0, low - 1);
                high++;
            }

            if (high < 0) {
                return false;
            }
        }
        return low == 0;
    }
}

public class ValidParenthesisString {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.checkValidString("()") + " | True");
        System.out.println(sol.checkValidString("(*)") + " | True");
        System.out.println(sol.checkValidString("(*))") + " | True");
        System.out.println(sol.checkValidString("***") + " | True");
        System.out.println(sol.checkValidString(")((") + " | False");
    }
}
