public class CheckIfTwoStringArraysAreEquivalent {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        return String.join("", word1).equals(String.join("", word2));
    }

    public static void main(String[] args) {
        CheckIfTwoStringArraysAreEquivalent sol = new CheckIfTwoStringArraysAreEquivalent();
        System.out
                .println(sol.arrayStringsAreEqual(new String[] { "ab", "c" }, new String[] { "a", "bc" }) + " | True");
        System.out
                .println(sol.arrayStringsAreEqual(new String[] { "a", "cb" }, new String[] { "ab", "c" }) + " | False");
        System.out.println(
                sol.arrayStringsAreEqual(new String[] { "abc", "d", "defg" }, new String[] { "abcddefg" }) + " | True");
        System.out.println(sol.arrayStringsAreEqual(new String[] { "" }, new String[] { "" }) + " | True");
        System.out
                .println(sol.arrayStringsAreEqual(new String[] { "a", "b", "c" }, new String[] { "abc" }) + " | True");
    }
}
