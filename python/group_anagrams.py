class Solution:
    def groupAnagrams(self, strs):
        # ...existing code...
        return []


s = Solution()
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(s.groupAnagrams(strs))  # [["bat"],["nat","tan"],["ate","eat","tea"]]
strs = [""]
print(s.groupAnagrams(strs))  # [[""]]
strs = ["a"]
print(s.groupAnagrams(strs))  # [["a"]]
