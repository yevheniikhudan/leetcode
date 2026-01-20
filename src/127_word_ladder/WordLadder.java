import java.util.*;

public class WordLadder {
    private String pattern(String word, int i) {
        return word.substring(0, i) + "*" + word.substring(i + 1);
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord) || beginWord.equals(endWord))
            return 0;
        Map<String, List<String>> adjList = new HashMap<>();
        for (String word : wordList) {
            for (int i = 0; i < word.length(); i++) {
                String pattern = pattern(word, i);
                adjList.computeIfAbsent(pattern, k -> new ArrayList<>()).add(word);
            }
        }
        Queue<String> q = new ArrayDeque<>();
        q.offer(beginWord);
        Set<String> visit = new HashSet<>();
        visit.add(beginWord);
        int result = 1;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                String word = q.poll();
                if (word.equals(endWord))
                    return result;
                for (int j = 0; j < word.length(); j++) {
                    String pattern = pattern(word, j);
                    if (adjList.containsKey(pattern)) {
                        for (String adj : adjList.get(pattern)) {
                            if (!visit.contains(adj)) {
                                q.offer(adj);
                                visit.add(adj);
                            }
                        }
                    }
                }
            }
            result++;
        }
        return 0;
    }

    // Test scaffolding
    public static void main(String[] args) {
        WordLadder sol = new WordLadder();
        System.out.println(
                sol.ladderLength("hit", "cog", Arrays.asList("hot", "dot", "dog", "lot", "log", "cog")) + " | 5");
        System.out.println(sol.ladderLength("hit", "cog", Arrays.asList("hot", "dot", "dog", "lot", "log")) + " | 0");
        System.out.println(sol.ladderLength("a", "c", Arrays.asList("a", "b", "c")) + " | 2");
        System.out.println(
                sol.ladderLength("red", "tax", Arrays.asList("ted", "tex", "red", "tax", "tad", "den", "rex", "pee"))
                        + " | 4");
    }
}
