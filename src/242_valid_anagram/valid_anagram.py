class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        counts = [0] * 26

        for i in range(len(s)):
            counts[ord(s[i]) - ord("a")] += 1
            counts[ord(t[i]) - ord("a")] -= 1

        for val in counts:
            if val != 0:
                return False

        return True


sol = Solution()
s = "anagram"
t = "nagaram"
print(sol.isAnagram(s, t), True)
s = "rat"
t = "car"
print(sol.isAnagram(s, t), False)
