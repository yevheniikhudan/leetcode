class Node:
    def __init__(self, key=0, next=None):
        self.key = key
        self.next = next


class MyHashSet:

    def __init__(self):
        self.capacity = 10_007
        self.keys = [Node() for _ in range(self.capacity)]

    def add(self, key: int) -> None:
        cur = self.keys[self.hash(key)]

        while cur.next:
            if cur.next.key == key:
                return

            cur = cur.next

        cur.next = Node(key)

    def remove(self, key: int) -> None:
        cur = self.keys[self.hash(key)]

        while cur.next:
            if cur.next.key == key:
                cur.next = cur.next.next
                return

            cur = cur.next

    def contains(self, key: int) -> bool:
        cur = self.keys[self.hash(key)].next

        while cur:
            if cur.key == key:
                return True

            cur = cur.next

        return False

    def hash(self, key: int) -> int:
        return key % self.capacity


# Test scaffolding
if __name__ == "__main__":
    hs = MyHashSet()
    hs.add(1)
    hs.add(2)
    print(hs.contains(1), "|", True)
    print(hs.contains(3), "|", False)
    hs.add(2)
    print(hs.contains(2), "|", True)
    hs.remove(2)
    print(hs.contains(2), "|", False)
