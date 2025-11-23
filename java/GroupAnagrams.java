import java.util.*;

public class GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> res = new HashMap<>();
        for (String s : strs) {
            int[] count = new int[26];
            for (char c : s.toCharArray()) {
                count[c - 'a']++;
            }
            String key = Arrays.toString(count);
            res.putIfAbsent(key, new ArrayList<>());
            res.get(key).add(s);
        }
        return new ArrayList<>(res.values());
    }

    public static void main(String[] args) {
        GroupAnagrams s = new GroupAnagrams();

        String[] strs1 = { "eat", "tea", "tan", "ate", "nat", "bat" };
        System.out.println(s.groupAnagrams(strs1));

        String[] strs2 = { "" };
        System.out.println(s.groupAnagrams(strs2));

        String[] strs3 = { "a" };
        System.out.println(s.groupAnagrams(strs3));
    }
}
