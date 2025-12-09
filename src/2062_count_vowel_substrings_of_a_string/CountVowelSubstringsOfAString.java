import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;

public class CountVowelSubstringsOfAString {
    public int countVowelSubstrings(String word) {
        HashSet<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        int result = 0;
        HashMap<Character, Integer> vowelIds = new HashMap<>();
        int start = 0;
        int n = word.length();

        for (int i = 0; i < n; i++) {
            char c = word.charAt(i);

            if (!vowels.contains(c)) {
                vowelIds = new HashMap<>();
                continue;
            }

            if (vowelIds.isEmpty())
                start = i;

            vowelIds.put(c, i);

            if (vowelIds.size() == 5)
                result += Collections.min(vowelIds.values()) - start + 1;

        }

        return result;
    }

    public static void main(String[] args) {
        CountVowelSubstringsOfAString sol = new CountVowelSubstringsOfAString();
        assert sol.countVowelSubstrings("aeiouu") == 2;
        assert sol.countVowelSubstrings("unicornarihan") == 0;
        assert sol.countVowelSubstrings("cuaieuouac") == 7;
        System.out.println("All test cases passed!");
    }
}
