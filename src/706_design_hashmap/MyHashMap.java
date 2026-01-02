import java.util.*;

public class MyHashMap {
    private class Node {
        int key;
        int value;
        Node next;

        public Node(int key, int value, Node next) {
            this.key = key;
            this.value = value;
            this.next = next;
        }
    }

    int capacity;
    Node[] hashMap;

    public MyHashMap() {
        this.capacity = 1009;
        this.hashMap = new Node[this.capacity];
        for (int i = 0; i < capacity; i++) {
            hashMap[i] = new Node(0, 0, null);
        }
    }

    public void put(int key, int value) {
        Node node = this.hashMap[key % this.capacity];

        while (node.next != null) {
            if (node.next.key == key) {
                node.next.value = value;
                return;
            }
            node = node.next;
        }

        node.next = new Node(key, value, null);
    }

    public int get(int key) {
        Node node = this.hashMap[key % this.capacity].next;

        while (node != null) {
            if (node.key == key) {
                return node.value;
            }

            node = node.next;
        }

        return -1;
    }

    public void remove(int key) {
        Node node = this.hashMap[key % this.capacity];

        while (node.next != null) {
            if (node.next.key == key) {
                node.next = node.next.next;
                return;
            }

            node = node.next;
        }
    }

    // Test scaffolding
    public static void main(String[] args) {
        String[] ops = { "MyHashMap", "put", "put", "get", "put", "get", "remove", "get" };
        int[][] argsArr = { {}, { 1, 1 }, { 2, 2 }, { 1 }, { 2, 1 }, { 2 }, { 2 }, { 2 } };
        Object[] expected = { null, null, null, 1, null, 1, null, -1 };
        MyHashMap obj = null;
        for (int i = 0; i < ops.length; i++) {
            Object actual;
            switch (ops[i]) {
                case "MyHashMap":
                    obj = new MyHashMap();
                    actual = null;
                    break;
                case "put":
                    obj.put(argsArr[i][0], argsArr[i][1]);
                    actual = null;
                    break;
                case "get":
                    actual = obj.get(argsArr[i][0]);
                    break;
                case "remove":
                    obj.remove(argsArr[i][0]);
                    actual = null;
                    break;
                default:
                    actual = null;
            }
            System.out.println(actual + " | " + expected[i]);
        }
    }
}
