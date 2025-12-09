from typing import List


class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        previous_count = 0
        result = 0

        for lasers in bank:
            count = lasers.count("1")
            if count > 0:
                if previous_count > 0:
                    result += previous_count * count

                previous_count = count

        return result


s = Solution()

bank = ["011001", "000000", "010100", "001000"]
print(s.numberOfBeams(bank), 8)

bank = ["000", "111", "000"]
print(s.numberOfBeams(bank), 0)
