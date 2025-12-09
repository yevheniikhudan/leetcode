import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class UniqueLength3PalindromicSubsequences {
    public int countPalindromicSubsequence(String s) {
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);

        for (int i = 0; i < s.length(); i++) {
            int curr = s.charAt(i) - 'a';
            if (first[curr] == -1) {
                first[curr] = i;
            }

            last[curr] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;
            }

            Set<Character> between = new HashSet<>();
            for (int j = first[i] + 1; j < last[i]; j++) {
                between.add(s.charAt(j));
            }

            ans += between.size();
        }

        return ans;
    }

    public static void main(String[] args) {
        UniqueLength3PalindromicSubsequences sol = new UniqueLength3PalindromicSubsequences();
        String s1 = "aabca";
        System.out.println(sol.countPalindromicSubsequence(s1) + " 3");
        String s2 = "adc";
        System.out.println(sol.countPalindromicSubsequence(s2) + " 0");
        String s3 = "bbcbaba";
        System.out.println(sol.countPalindromicSubsequence(s3) + " 4");
    }
}
