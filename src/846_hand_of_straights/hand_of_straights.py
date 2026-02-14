from collections import Counter
from typing import List


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        length = len(hand)
        if length % groupSize != 0:
            return False

        card_count = Counter(hand)

        for card in hand:
            start_card = card
            # Get the first card to start from
            while card_count[start_card - 1]:
                start_card -= 1

            while start_card <= card:
                while card_count[start_card]:
                    for i in range(start_card, start_card + groupSize):
                        if not card_count[i]:
                            return False
                        card_count[i] -= 1
                start_card += 1
        return True


def test_isNStraightHand():
    sol = Solution()
    print(f"{sol.isNStraightHand([1,2,3,6,2,3,4,7,8], 3)} | True")
    print(f"{sol.isNStraightHand([1,2,3,4,5], 4)} | False")
    print(f"{sol.isNStraightHand([1,1,2,2,3,3], 3)} | True")
    print(f"{sol.isNStraightHand([1,2,3,4], 2)} | True")
    print(f"{sol.isNStraightHand([1], 1)} | True")


if __name__ == "__main__":
    test_isNStraightHand()
