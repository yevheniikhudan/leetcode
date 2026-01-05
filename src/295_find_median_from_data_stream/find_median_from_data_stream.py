import heapq


class MedianFinder:
    def __init__(self):
        self.small = []
        self.large = []

    def addNum(self, num: int) -> None:
        heapq.heappush(self.small, -num)
        heapq.heappush(self.large, -heapq.heappop(self.small))

        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):
            return -self.small[0]

        return (-self.small[0] + self.large[0]) / 2


# Test scaffolding
if __name__ == "__main__":
    mf = MedianFinder()
    mf.addNum(1)
    mf.addNum(2)
    print(mf.findMedian(), "|", 1.5)
    mf.addNum(3)
    print(mf.findMedian(), "|", 2.0)
    mf2 = MedianFinder()
    for n in [5, 3, 8, 9, 2]:
        mf2.addNum(n)
    print(mf2.findMedian(), "|", 5)
    mf3 = MedianFinder()
    for n in [10, 20, 30, 40]:
        mf3.addNum(n)
    print(mf3.findMedian(), "|", 25.0)
    mf4 = MedianFinder()
    for n in [7]:
        mf4.addNum(n)
    print(mf4.findMedian(), "|", 7)
