import java.util.*;

class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        int i = num.length - 1;
        int carry = 0;
        LinkedList<Integer> res = new LinkedList<>();
        while (k > 0 || carry > 0 || i >= 0) {
            int sum = carry + (k % 10);
            if (i >= 0) sum += num[i];
            res.addFirst(sum % 10);
            k /= 10;
            carry = sum / 10;
            i--;
        }
        return res;
    }
}

public class AddToArrayFormOfInteger {
    public static void main(String[] args) {
        int[][] testNums = {
                { 1, 2, 0, 0 },
                { 2, 7, 4 },
                { 2, 1, 5 },
                { 0 },
                { 9, 9, 9, 9, 9 }
        };
        int[] ks = { 34, 181, 806, 23, 1 };
        int[][] expected = {
                { 1, 2, 3, 4 },
                { 4, 5, 5 },
                { 1, 0, 2, 1 },
                { 2, 3 },
                { 1, 0, 0, 0, 0, 0 }
        };
        Solution sol = new Solution();
        for (int i = 0; i < testNums.length; i++) {
            List<Integer> actual = sol.addToArrayForm(testNums[i], ks[i]);
            System.out.println(actual + " | " + Arrays.toString(expected[i]));
        }
    }
}
