import java.util.*;

// Solution class for logic
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack(res, "", 0, 0, n);
        return res;
    }

    private void backtrack(List<String> res, String s, int left, int right, int n) {
        if (s.length() == 2 * n) {
            res.add(s);
            return;
        }
        if (left < n)
            backtrack(res, s + "(", left + 1, right, n);
        if (right < left)
            backtrack(res, s + ")", left, right + 1, n);
    }
}

// Main/test class
public class GenerateParentheses {
    public static void main(String[] args) {
        Solution sol = new Solution();
        List<String> e1 = Arrays.asList("((()))", "(()())", "(())()", "()(())", "()()()");
        List<String> r1 = sol.generateParenthesis(3);
        Collections.sort(r1);
        Collections.sort(e1);
        System.out.println(r1.equals(e1) ? "PASS" : "FAIL");
        List<String> e2 = Arrays.asList("()");
        List<String> r2 = sol.generateParenthesis(1);
        Collections.sort(r2);
        Collections.sort(e2);
        System.out.println(r2.equals(e2) ? "PASS" : "FAIL");
        System.out.println(sol.generateParenthesis(4).size() == 14 ? "PASS" : "FAIL");
    }
}
