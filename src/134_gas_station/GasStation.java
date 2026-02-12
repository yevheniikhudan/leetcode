class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.length; ++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
}

public class GasStation {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.canCompleteCircuit(new int[] { 1, 2, 3, 4, 5 }, new int[] { 3, 4, 5, 1, 2 }) + " | 3");
        System.out.println(sol.canCompleteCircuit(new int[] { 2, 3, 4 }, new int[] { 3, 4, 3 }) + " | -1");
        System.out.println(sol.canCompleteCircuit(new int[] { 5 }, new int[] { 4 }) + " | 0");
        System.out.println(sol.canCompleteCircuit(new int[] { 0, 0 }, new int[] { 0, 0 }) + " | 0");
        System.out.println(sol.canCompleteCircuit(new int[] { 1, 2, 3, 4 }, new int[] { 2, 2, 2, 2 }) + " | 1");
    }
}
