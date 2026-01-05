import java.util.*;

public class Solution {
    PriorityQueue<Integer> small;
    PriorityQueue<Integer> large;

    public Solution() {
        small = new PriorityQueue<>(Collections.reverseOrder());
        large = new PriorityQueue<>();
    }

    public void addNum(int num) {
        small.offer(num);
        large.offer(small.poll());
        if (large.size() > small.size()) {
            small.offer(large.poll());
        }
    }

    public Double findMedian() {
        if (small.size() > large.size()) {
            return (double)small.peek();
        }

        return (double)(small.peek() + large.peek()) / 2;
    }
}

public class FindMedianFromDataStream {
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.addNum(1);
        sol.addNum(2);
        System.out.println(sol.findMedian() + " | " + 1.5);
        sol.addNum(3);
        System.out.println(sol.findMedian() + " | " + 2.0);
        Solution sol2 = new Solution();
        for (int n : new int[]{5, 3, 8, 9, 2}) sol2.addNum(n);
        System.out.println(sol2.findMedian() + " | " + 5);
        Solution sol3 = new Solution();
        for (int n : new int[]{10, 20, 30, 40}) sol3.addNum(n);
        System.out.println(sol3.findMedian() + " | " + 25.0);
        Solution sol4 = new Solution();
        sol4.addNum(7);
        System.out.println(sol4.findMedian() + " | " + 7);
    }
}
