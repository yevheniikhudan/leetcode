from typing import List


class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.endWord = False
        self.word = ""


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        res = set()
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        rows = len(board)
        cols = len(board[0])
        trie = self.buildTrie(words)

        def dfs(node: TrieNode, row: int, col: int):
            # Check current character
            c = board[row][col]
            if c == "#" or node.children[self.index(c)] is None:
                return
            
            # Move to next node in trie
            node = node.children[self.index(c)]
            
            # Check if we found a word
            if node.endWord:
                res.add(node.word)
            
            # Mark as visited and explore neighbors
            board[row][col] = "#"
            for rD, cD in directions:
                newRow, newCol = row + rD, col + cD
                if 0 <= newRow < rows and 0 <= newCol < cols:
                    dfs(node, newRow, newCol)
            board[row][col] = c  # Backtrack

        for row in range(rows):
            for col in range(cols):
                dfs(trie, row, col)

        return list(res)

    def buildTrie(self, words):
        root = TrieNode()

        for word in words:
            currentNode = root

            for c in word:
                if currentNode.children[self.index(c)] == None:
                    currentNode.children[self.index(c)] = TrieNode()

                currentNode = currentNode.children[self.index(c)]

            currentNode.endWord = True
            currentNode.word = word

        return root

    def index(self, c: chr) -> int:
        return ord(c) - ord("a")


# Test scaffolding
if __name__ == "__main__":
    board = [
        ["o", "a", "a", "n"],
        ["e", "t", "a", "e"],
        ["i", "h", "k", "r"],
        ["i", "f", "l", "v"],
    ]
    words = ["oath", "pea", "eat", "rain"]
    print(Solution().findWords(board, words))  # ["eat","oath"]

    board = [
        ["a"],
    ]
    words = ["a"]
    print(Solution().findWords(board, words))  # ["eat","oath"]

    board = [["a", "a"]]
    words = ["aaa"]
    print(Solution().findWords(board, words))  # []
