import java.util.*;

class Solution {

    public boolean areSentencesSimilar(
        String[] sentence1,
        String[] sentence2,
        List<List<String>> similarPairs
    ) {
        if (sentence1.length != sentence2.length) {
            return false;
        }

        Set<String> pairs = new HashSet<>();
        for (List<String> pair : similarPairs) {
            pairs.add(pair.get(0) + "#" + pair.get(1));
            pairs.add(pair.get(1) + "#" + pair.get(0));
        }

        for (int i = 0; i < sentence1.length; i++) {
            if (sentence1[i].equals(sentence2[i])) {
                continue;
            }
            if (!pairs.contains(sentence1[i] + "#" + sentence2[i])) {
                return false;
            }
        }

        return true;
    }
}
