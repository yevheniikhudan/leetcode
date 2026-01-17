import java.util.*;

public class ReverseString {
    public void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    public static void main(String[] args) {
        ReverseString sol = new ReverseString();
        char[] arr1 = "hello".toCharArray();
        sol.reverseString(arr1);
        System.out.println(Arrays.toString(arr1) + " | [o, l, l, e, h]");
        char[] arr2 = "a".toCharArray();
        sol.reverseString(arr2);
        System.out.println(Arrays.toString(arr2) + " | [a]");
        char[] arr3 = "".toCharArray();
        sol.reverseString(arr3);
        System.out.println(Arrays.toString(arr3) + " | []");
        char[] arr4 = "ab".toCharArray();
        sol.reverseString(arr4);
        System.out.println(Arrays.toString(arr4) + " | [b, a]");
        char[] arr5 = "racecar".toCharArray();
        sol.reverseString(arr5);
        System.out.println(Arrays.toString(arr5) + " | [r, a, c, e, c, a, r]");
    }
}
