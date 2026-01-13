class TrieNode:
    def __init__(self):
        self.children = {}
        self.endWord = False


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        currentNode = self.root

        for c in word:
            if c not in currentNode.children:
                currentNode.children[c] = TrieNode()

            currentNode = currentNode.children[c]

        currentNode.endWord = True

    def search(self, word: str) -> bool:
        def searchSuffix(node: TrieNode, index: int) -> bool:
            if index == len(word):
                return node.endWord

            c = word[index]
            if c != ".":
                if c not in node.children:
                    return False

                return searchSuffix(node.children[c], index + 1)
            else:
                return any(
                    searchSuffix(node.children[key], index + 1) for key in node.children
                )

        return searchSuffix(self.root, 0)


# Test scaffolding
if __name__ == "__main__":
    wd = WordDictionary()
    wd.addWord("bad")
    wd.addWord("dad")
    wd.addWord("mad")
    print(wd.search("pad"))  # False
    print(wd.search("bad"))  # True
    print(wd.search(".ad"))  # True
    print(wd.search("b.."))  # True
