public class ValidAnagram {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;

        int[] counters = new int[26];

        for (int i = 0; i < s.length(); i++) {
            counters[s.charAt(i) - 'a'] += 1;
            counters[t.charAt(i) - 'a'] -= 1;
        }

        for (int counter : counters) {
            if (counter != 0)
                return false;
        }

        return true;
    }

    public static void main(String[] args) {
        ValidAnagram sol = new ValidAnagram();
        String s1 = "anagram", t1 = "nagaram";
        System.out.println(sol.isAnagram(s1, t1) + " true");
        String s2 = "rat", t2 = "car";
        System.out.println(sol.isAnagram(s2, t2) + " false");
    }
}
