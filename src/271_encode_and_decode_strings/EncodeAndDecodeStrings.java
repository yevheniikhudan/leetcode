import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class EncodeAndDecodeStrings {
    /**
     * Encodes a list of strings to a single string.
     * 
     * @param strs List of strings to encode
     * @return Encoded string
     */
    public String encode(List<String> strs) {
        String delimiter = "#";
        String encoded = "";

        for (String s : strs) {
            encoded = encoded + s.length() + delimiter + s;
        }

        return encoded;
    }

    /**
     * Decodes a single string to a list of strings.
     * 
     * @param s Encoded string
     * @return List of decoded strings
     */
    public List<String> decode(String s) {
        char delimiter = '#';
        int end = 0;
        int pointer = 0;
        List<String> decoded = new ArrayList<>();

        while (pointer < s.length()) {
            while (s.charAt(pointer) != delimiter) {
                pointer += 1;
            }
            int start = pointer + 1;
            int nextLength = Integer.parseInt(s.substring(end, pointer));
            end = start + nextLength;
            decoded.add(s.substring(start, end));

            pointer = end;
        }

        return decoded;
    }

    public static void main(String[] args) {
        EncodeAndDecodeStrings solution = new EncodeAndDecodeStrings();

        // Test case 1: Basic example
        List<String> strs1 = Arrays.asList("Hello", "World");
        String encoded1 = solution.encode(strs1);
        List<String> decoded1 = solution.decode(encoded1);
        System.out.println("Test 1: " + strs1 + " -> " + encoded1 + " -> " + decoded1);
        assert decoded1.equals(strs1) : "Expected " + strs1 + ", got " + decoded1;

        // Test case 2: Empty string
        List<String> strs2 = Arrays.asList("");
        String encoded2 = solution.encode(strs2);
        List<String> decoded2 = solution.decode(encoded2);
        System.out.println("Test 2: " + strs2 + " -> " + encoded2 + " -> " + decoded2);
        assert decoded2.equals(strs2) : "Expected " + strs2 + ", got " + decoded2;

        // Test case 3: Empty list
        List<String> strs3 = new ArrayList<>();
        String encoded3 = solution.encode(strs3);
        List<String> decoded3 = solution.decode(encoded3);
        System.out.println("Test 3: " + strs3 + " -> " + encoded3 + " -> " + decoded3);
        assert decoded3.equals(strs3) : "Expected " + strs3 + ", got " + decoded3;

        // Test case 4: Strings with special characters
        List<String> strs4 = Arrays.asList("a#b", "c#d");
        String encoded4 = solution.encode(strs4);
        List<String> decoded4 = solution.decode(encoded4);
        System.out.println("Test 4: " + strs4 + " -> " + encoded4 + " -> " + decoded4);
        assert decoded4.equals(strs4) : "Expected " + strs4 + ", got " + decoded4;

        // Test case 5: Multiple empty strings
        List<String> strs5 = Arrays.asList("", "", "");
        String encoded5 = solution.encode(strs5);
        List<String> decoded5 = solution.decode(encoded5);
        System.out.println("Test 5: " + strs5 + " -> " + encoded5 + " -> " + decoded5);
        assert decoded5.equals(strs5) : "Expected " + strs5 + ", got " + decoded5;

        // Test case 6: Strings with numbers
        List<String> strs6 = Arrays.asList("123", "456", "789");
        String encoded6 = solution.encode(strs6);
        List<String> decoded6 = solution.decode(encoded6);
        System.out.println("Test 6: " + strs6 + " -> " + encoded6 + " -> " + decoded6);
        assert decoded6.equals(strs6) : "Expected " + strs6 + ", got " + decoded6;

        // Test case 7: Mixed length strings
        List<String> strs7 = Arrays.asList("a", "ab", "abc", "abcd");
        String encoded7 = solution.encode(strs7);
        List<String> decoded7 = solution.decode(encoded7);
        System.out.println("Test 7: " + strs7 + " -> " + encoded7 + " -> " + decoded7);
        assert decoded7.equals(strs7) : "Expected " + strs7 + ", got " + decoded7;

        System.out.println("All test cases passed!");
    }
}
