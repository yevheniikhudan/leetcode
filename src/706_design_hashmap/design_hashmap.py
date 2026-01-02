class Node:
    def __init__(self, key=0, val=0, next=None):
        self.key = key
        self.val = val
        self.next = next


class MyHashMap:
    def __init__(self):
        self.capacity = 1009
        self.hashMap = [Node() for _ in range(self.capacity)]

    def put(self, key: int, value: int) -> None:
        node = self.hashMap[key % self.capacity]

        while node.next:
            if node.next.key == key:
                node.next.val = value
                return
            node = node.next

        node.next = Node(key, value)

    def get(self, key: int) -> int:
        node = self.hashMap[key % self.capacity].next

        while node:
            if node.key == key:
                return node.val
            node = node.next

        return -1

    def remove(self, key: int) -> None:
        node = self.hashMap[key % self.capacity]

        while node.next:
            if node.next.key == key:
                node.next = node.next.next
                return
            node = node.next


# Test scaffolding
if __name__ == "__main__":
    ops = ["MyHashMap", "put", "put", "get", "put", "get", "remove", "get"]
    args = [[], [1, 1], [2, 2], [1], [2, 1], [2], [2], [2]]
    expected = [None, None, None, 1, None, 1, None, -1]
    obj = None
    for op, arg, exp in zip(ops, args, expected):
        if op == "MyHashMap":
            obj = MyHashMap()
            actual = None
        else:
            actual = getattr(obj, op)(*arg)
        print(f"{actual} | {exp}")
