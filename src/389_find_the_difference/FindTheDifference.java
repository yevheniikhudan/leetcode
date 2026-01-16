public class FindTheDifference {
    public char findTheDifference(String s, String t) {
        int sSum = 0, tSum = 0;
        for (int i = 0; i < t.length(); i++) {
            if (i < t.length() - 1) {
                sSum += s.charAt(i);
            }
            tSum += t.charAt(i);
        }
        return (char) (tSum - sSum);
    }

    public static void main(String[] args) {
        FindTheDifference sol = new FindTheDifference();
        System.out.println(sol.findTheDifference("abcd", "abcde") + " | e");
        System.out.println(sol.findTheDifference("", "y") + " | y");
        System.out.println(sol.findTheDifference("a", "aa") + " | a");
        System.out.println(sol.findTheDifference("ae", "aea") + " | a");
        System.out.println(sol.findTheDifference("xyz", "xzyq") + " | q");
    }
}
