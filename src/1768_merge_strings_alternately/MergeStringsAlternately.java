public class MergeStringsAlternately {
    public String mergeAlternately(String word1, String word2) {
        int n1 = word1.length(), n2 = word2.length();
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < Math.max(n1, n2); ++i) {
            if (i < n1)
                res.append(word1.charAt(i));
            if (i < n2)
                res.append(word2.charAt(i));
        }
        return res.toString();
    }

    // Test scaffolding
    public static void main(String[] args) {
        MergeStringsAlternately sol = new MergeStringsAlternately();
        System.out.println(sol.mergeAlternately("abc", "pqr")); // apbqcr
        System.out.println(sol.mergeAlternately("ab", "pqrs")); // apbqrs
        System.out.println(sol.mergeAlternately("abcd", "pq")); // apbqcd
        System.out.println(sol.mergeAlternately("a", "z")); // az
        System.out.println(sol.mergeAlternately("abcde", "")); // abcde
    }
}
