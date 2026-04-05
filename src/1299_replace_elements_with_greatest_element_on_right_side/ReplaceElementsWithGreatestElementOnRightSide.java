import java.util.*;

class Solution {

    public int[] replaceElements(int[] arr) {
        int rightMax = -1;

        for (int i = arr.length - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = rightMax;
            rightMax = Math.max(temp, rightMax);
        }
        return arr;
    }
}

class ReplaceElementsWithGreatestElementOnRightSide {

    static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(",");
        }
        System.out.print("]");
    }

    static void testReplaceElements() {
        Solution solution = new Solution();

        // Test 1: Example from problem
        int[] arr1 = { 17, 18, 5, 4, 6, 1 };
        int[] result1 = solution.replaceElements(arr1.clone());
        int[] expected1 = { 18, 6, 6, 6, 1, -1 };
        printArray(result1);
        System.out.print(" | ");
        printArray(expected1);
        System.out.println(
            " | " + (Arrays.equals(result1, expected1) ? "PASS" : "FAIL")
        );

        // Test 2: Single element
        int[] arr2 = { 400 };
        int[] result2 = solution.replaceElements(arr2.clone());
        int[] expected2 = { -1 };
        printArray(result2);
        System.out.print(" | ");
        printArray(expected2);
        System.out.println(
            " | " + (Arrays.equals(result2, expected2) ? "PASS" : "FAIL")
        );

        // Test 3: Strictly increasing
        int[] arr3 = { 1, 2, 3, 4, 5 };
        int[] result3 = solution.replaceElements(arr3.clone());
        int[] expected3 = { 5, 5, 5, 5, -1 };
        printArray(result3);
        System.out.print(" | ");
        printArray(expected3);
        System.out.println(
            " | " + (Arrays.equals(result3, expected3) ? "PASS" : "FAIL")
        );

        // Test 4: Strictly decreasing
        int[] arr4 = { 5, 4, 3, 2, 1 };
        int[] result4 = solution.replaceElements(arr4.clone());
        int[] expected4 = { 4, 3, 2, 1, -1 };
        printArray(result4);
        System.out.print(" | ");
        printArray(expected4);
        System.out.println(
            " | " + (Arrays.equals(result4, expected4) ? "PASS" : "FAIL")
        );

        // Test 5: All same elements
        int[] arr5 = { 3, 3, 3, 3 };
        int[] result5 = solution.replaceElements(arr5.clone());
        int[] expected5 = { 3, 3, 3, -1 };
        printArray(result5);
        System.out.print(" | ");
        printArray(expected5);
        System.out.println(
            " | " + (Arrays.equals(result5, expected5) ? "PASS" : "FAIL")
        );
    }

    public static void main(String[] args) {
        testReplaceElements();
    }
}
