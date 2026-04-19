import java.util.Arrays;

class Solution {

    public int[] anagramMappings(int[] nums1, int[] nums2) {
        Map<Integer, Integer> mapping = new HashMap<>();

        for (int i = 0; i < nums2.length; i++) {
            mapping.put(nums2[i], i);
        }

        int[] res = new int[nums1.length];

        for (int i = 0; i < nums1.length; i++) {
            res[i] = mapping.get(nums1[i]);
        }

        return res;
    }
}

public class FindAnagramMappings {

    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(
            "================================================================================"
        );
        System.out.println("Testing: Problem 760 - Find Anagram Mappings");
        System.out.println(
            "================================================================================\n"
        );

        int passed = 0;
        int failed = 0;

        // Test Case 1: Basic example
        {
            int[] nums1 = { 12, 28, 46, 32, 50 };
            int[] nums2 = { 50, 12, 32, 46, 28 };
            int[] expected = { 1, 4, 3, 2, 0 };
            int[] actual = solution.anagramMappings(nums1, nums2);
            boolean pass = arraysEqual(actual, expected);
            System.out.println(
                arrayToString(actual) +
                    " | " +
                    arrayToString(expected) +
                    " | " +
                    (pass ? "PASS" : "FAIL")
            );
            if (pass) passed++;
            else failed++;
        }

        // Test Case 2: Single element
        {
            int[] nums1 = { 1 };
            int[] nums2 = { 1 };
            int[] expected = { 0 };
            int[] actual = solution.anagramMappings(nums1, nums2);
            boolean pass = arraysEqual(actual, expected);
            System.out.println(
                arrayToString(actual) +
                    " | " +
                    arrayToString(expected) +
                    " | " +
                    (pass ? "PASS" : "FAIL")
            );
            if (pass) passed++;
            else failed++;
        }

        // Test Case 3: Two elements in order
        {
            int[] nums1 = { 84, 46 };
            int[] nums2 = { 84, 46 };
            int[] expected = { 0, 1 };
            int[] actual = solution.anagramMappings(nums1, nums2);
            boolean pass = arraysEqual(actual, expected);
            System.out.println(
                arrayToString(actual) +
                    " | " +
                    arrayToString(expected) +
                    " | " +
                    (pass ? "PASS" : "FAIL")
            );
            if (pass) passed++;
            else failed++;
        }

        // Test Case 4: Two elements reversed
        {
            int[] nums1 = { 1, 2 };
            int[] nums2 = { 2, 1 };
            int[] expected = { 1, 0 };
            int[] actual = solution.anagramMappings(nums1, nums2);
            boolean pass = arraysEqual(actual, expected);
            System.out.println(
                arrayToString(actual) +
                    " | " +
                    arrayToString(expected) +
                    " | " +
                    (pass ? "PASS" : "FAIL")
            );
            if (pass) passed++;
            else failed++;
        }

        // Test Case 5: Three elements
        {
            int[] nums1 = { 3, 5, 7 };
            int[] nums2 = { 7, 5, 3 };
            int[] expected = { 2, 1, 0 };
            int[] actual = solution.anagramMappings(nums1, nums2);
            boolean pass = arraysEqual(actual, expected);
            System.out.println(
                arrayToString(actual) +
                    " | " +
                    arrayToString(expected) +
                    " | " +
                    (pass ? "PASS" : "FAIL")
            );
            if (pass) passed++;
            else failed++;
        }

        // Test Case 6: Larger array reversed
        {
            int[] nums1 = { 1, 2, 3, 4, 5 };
            int[] nums2 = { 5, 4, 3, 2, 1 };
            int[] expected = { 4, 3, 2, 1, 0 };
            int[] actual = solution.anagramMappings(nums1, nums2);
            boolean pass = arraysEqual(actual, expected);
            System.out.println(
                arrayToString(actual) +
                    " | " +
                    arrayToString(expected) +
                    " | " +
                    (pass ? "PASS" : "FAIL")
            );
            if (pass) passed++;
            else failed++;
        }

        // Test Case 7: Larger numbers
        {
            int[] nums1 = { 10, 20, 30 };
            int[] nums2 = { 30, 10, 20 };
            int[] expected = { 1, 2, 0 };
            int[] actual = solution.anagramMappings(nums1, nums2);
            boolean pass = arraysEqual(actual, expected);
            System.out.println(
                arrayToString(actual) +
                    " | " +
                    arrayToString(expected) +
                    " | " +
                    (pass ? "PASS" : "FAIL")
            );
            if (pass) passed++;
            else failed++;
        }

        System.out.println(
            "\n================================================================================"
        );
        System.out.println(
            "Results: " +
                passed +
                " passed, " +
                failed +
                " failed out of 7 tests"
        );
        System.out.println(
            "================================================================================"
        );
    }

    static String arrayToString(int[] arr) {
        if (arr == null) return "null";
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i]);
            if (i < arr.length - 1) sb.append(", ");
        }
        sb.append("]");
        return sb.toString();
    }

    static boolean arraysEqual(int[] arr1, int[] arr2) {
        if (arr1 == null && arr2 == null) return true;
        if (arr1 == null || arr2 == null) return false;
        if (arr1.length != arr2.length) return false;
        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }
}
