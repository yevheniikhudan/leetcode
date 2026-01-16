#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

class MyHashSet {
    static const int capacity = 10007;
    Node* keys[capacity];

   public:
    MyHashSet() {
        for (int i = 0; i < capacity; ++i) {
            keys[i] = new Node(0);  // dummy head
        }
    }
    ~MyHashSet() {
        for (int i = 0; i < capacity; ++i) {
            Node* cur = keys[i];
            while (cur) {
                Node* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
        }
    }
    void add(int key) {
        Node* cur = keys[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) return;
            cur = cur->next;
        }
        cur->next = new Node(key);
    }
    void remove(int key) {
        Node* cur = keys[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                Node* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                return;
            }
            cur = cur->next;
        }
    }
    bool contains(int key) {
        Node* cur = keys[hash(key)]->next;
        while (cur) {
            if (cur->key == key) return true;
            cur = cur->next;
        }
        return false;
    }

   private:
    int hash(int key) { return key % capacity; }
};

int main() {
    MyHashSet hs;
    hs.add(1);
    hs.add(2);
    cout << boolalpha << hs.contains(1) << " | true" << endl;
    cout << boolalpha << hs.contains(3) << " | false" << endl;
    hs.add(2);
    cout << boolalpha << hs.contains(2) << " | true" << endl;
    hs.remove(2);
    cout << boolalpha << hs.contains(2) << " | false" << endl;
    return 0;
}
