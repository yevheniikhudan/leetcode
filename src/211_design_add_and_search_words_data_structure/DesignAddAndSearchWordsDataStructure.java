public class DesignAddAndSearchWordsDataStructure {
    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd = false;
    }
    static class WordDictionary {
        private TrieNode root;
        public WordDictionary() {
            root = new TrieNode();
        }
        public void addWord(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                int idx = c - 'a';
                if (node.children[idx] == null) {
                    node.children[idx] = new TrieNode();
                }
                node = node.children[idx];
            }
            node.isEnd = true;
        }
        public boolean search(String word) {
            return searchHelper(word, 0, root);
        }
        private boolean searchHelper(String word, int index, TrieNode node) {
            if (index == word.length()) return node.isEnd;
            char c = word.charAt(index);
            if (c != '.') {
                int idx = c - 'a';
                if (node.children[idx] == null) return false;
                return searchHelper(word, index + 1, node.children[idx]);
            } else {
                for (int i = 0; i < 26; ++i) {
                    if (node.children[i] != null && searchHelper(word, index + 1, node.children[i])) {
                        return true;
                    }
                }
                return false;
            }
        }
    }
    // Test scaffolding
    public static void main(String[] args) {
        WordDictionary wd = new WordDictionary();
        wd.addWord("bad");
        wd.addWord("dad");
        wd.addWord("mad");
        System.out.println(wd.search("pad")); // false
        System.out.println(wd.search("bad")); // true
        System.out.println(wd.search(".ad")); // true
        System.out.println(wd.search("b..")); // true
    }
}
