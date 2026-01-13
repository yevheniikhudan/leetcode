import java.util.*;

public class WordSearchII {
    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd = false;
        String word = null;
    }

    public List<String> findWords(char[][] board, String[] words) {
        Set<String> res = new HashSet<>();
        int rows = board.length, cols = board[0].length;
        int[] dr = { -1, 1, 0, 0 }, dc = { 0, 0, -1, 1 };
        TrieNode trie = buildTrie(words);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                dfs(board, trie, row, col, rows, cols, dr, dc, res);
            }
        }
        return new ArrayList<>(res);
    }

    private void dfs(char[][] board, TrieNode node, int row, int col, int rows, int cols, int[] dr, int[] dc,
            Set<String> res) {
        char c = board[row][col];
        if (c == '#' || node.children[c - 'a'] == null)
            return;
        node = node.children[c - 'a'];
        if (node.isEnd)
            res.add(node.word);
        board[row][col] = '#';
        for (int d = 0; d < 4; ++d) {
            int nr = row + dr[d], nc = col + dc[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                dfs(board, node, nr, nc, rows, cols, dr, dc, res);
            }
        }
        board[row][col] = c;
    }

    private TrieNode buildTrie(String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                if (node.children[c - 'a'] == null)
                    node.children[c - 'a'] = new TrieNode();
                node = node.children[c - 'a'];
            }
            node.isEnd = true;
            node.word = word;
        }
        return root;
    }

    // Test scaffolding
    public static void main(String[] args) {
        char[][] board = {
                { 'o', 'a', 'a', 'n' },
                { 'e', 't', 'a', 'e' },
                { 'i', 'h', 'k', 'r' },
                { 'i', 'f', 'l', 'v' }
        };
        String[] words = { "oath", "pea", "eat", "rain" };
        System.out.println(new WordSearchII().findWords(board, words)); // [eat, oath]
    }
}
