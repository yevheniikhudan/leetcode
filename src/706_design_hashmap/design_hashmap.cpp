#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int key, val;
    Node* next;
    Node(int key = 0, int val = 0, Node* next = nullptr) : key(key), val(val), next(next) {}
};

class MyHashMap {
    int capacity;
    vector<Node*> hashMap;

   public:
    MyHashMap() {
        capacity = 1009;
        hashMap.resize(capacity, nullptr);
        for (int i = 0; i < capacity; i++) {
            hashMap[i] = new Node();
        }
    }
    void put(int key, int value) {
        Node* node = hashMap[key % capacity];
        while (node->next) {
            if (node->next->key == key) {
                node->next->val = value;
                return;
            }

            node = node->next;
        }

        node->next = new Node(key, value);
    }
    int get(int key) {
        Node* node = hashMap[key % capacity]->next;

        while (node) {
            if (node->key == key) return node->val;

            node = node->next;
        }

        return -1;
    }

    void remove(int key) {
        Node* node = hashMap[key % capacity];

        while (node->next) {
            if (node->next->key == key) {
                Node* toDelete = node->next;
                node->next = node->next->next;
                delete toDelete;
                return;
            }
            node = node->next;
        }
    }

    ~MyHashMap() {
        for (int i = 0; i < capacity; i++) {
            Node* node = hashMap[i];
            while (node) {
                Node* next = node->next;
                delete node;
                node = next;
            }
        }
    }
};

int main() {
    vector<string> ops = {"MyHashMap", "put", "put", "get", "put", "get", "remove", "get"};
    vector<vector<int>> args = {{}, {1, 1}, {2, 2}, {1}, {2, 1}, {2}, {2}, {2}};
    vector<int> expected = {0, 0, 0, 1, 0, 1, 0, -1};
    MyHashMap* obj = nullptr;
    for (int i = 0; i < ops.size(); ++i) {
        int actual = 0;
        if (ops[i] == "MyHashMap") {
            obj = new MyHashMap();
            actual = 0;
        } else if (ops[i] == "put") {
            obj->put(args[i][0], args[i][1]);
            actual = 0;
        } else if (ops[i] == "get") {
            actual = obj->get(args[i][0]);
        } else if (ops[i] == "remove") {
            obj->remove(args[i][0]);
            actual = 0;
        }
        cout << actual << " | " << expected[i] << endl;
    }
    delete obj;
    return 0;
}
