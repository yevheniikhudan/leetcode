class Node {
    int key;
    Node next;
    Node(int key) {
        this.key = key;
        this.next = null;
    }
}

class MyHashSet {
    private final int capacity = 10007;
    private Node[] keys;

    public MyHashSet() {
        keys = new Node[capacity];
        for (int i = 0; i < capacity; i++) {
            keys[i] = new Node(0); // dummy head
        }
    }

    public void add(int key) {
        Node cur = keys[hash(key)];
        while (cur.next != null) {
            if (cur.next.key == key) return;
            cur = cur.next;
        }
        cur.next = new Node(key);
    }

    public void remove(int key) {
        Node cur = keys[hash(key)];
        while (cur.next != null) {
            if (cur.next.key == key) {
                cur.next = cur.next.next;
                return;
            }
            cur = cur.next;
        }
    }

    public boolean contains(int key) {
        Node cur = keys[hash(key)].next;
        while (cur != null) {
            if (cur.key == key) return true;
            cur = cur.next;
        }
        return false;
    }

    private int hash(int key) {
        return key % capacity;
    }
}

public class DesignHashSet {
    public static void main(String[] args) {
        MyHashSet hs = new MyHashSet();
        hs.add(1);
        hs.add(2);
        System.out.println(hs.contains(1) + " | true");
        System.out.println(hs.contains(3) + " | false");
        hs.add(2);
        System.out.println(hs.contains(2) + " | true");
        hs.remove(2);
        System.out.println(hs.contains(2) + " | false");
    }
}