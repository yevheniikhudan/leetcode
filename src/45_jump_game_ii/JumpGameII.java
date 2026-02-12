class Solution {
    public int jump(int[] nums) {
        int jumps = 0, end = 0, farthest = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            farthest = Math.max(farthest, i + nums[i]);
            if (i == end) {
                ++jumps;
                end = farthest;
            }
        }
        return jumps;
    }
}

public class JumpGameII {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.jump(new int[] { 2, 3, 1, 1, 4 }) + " | 2");
        System.out.println(sol.jump(new int[] { 2, 3, 0, 1, 4 }) + " | 2");
        System.out.println(sol.jump(new int[] { 0 }) + " | 0");
        System.out.println(sol.jump(new int[] { 1, 2 }) + " | 1");
        System.out.println(sol.jump(new int[] { 2, 3, 1, 1, 4, 0, 0 }) + " | 2");
    }
}
