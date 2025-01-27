#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> map;
    Node *head, *tail;

    void addNode(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node *node) {
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;

        Node *node = map[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node *node = map[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (map.size() == capacity) {
                Node *lru = tail->prev;
                map.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            Node *newNode = new Node(key, value);
            map[key] = newNode;
            addNode(newNode);
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int capacity;
        cin >> capacity;
        LRUCache cache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string command;
            cin >> command;
            if (command == "PUT") {
                int key, value;
                cin >> key >> value;
                cache.put(key, value);
            } else if (command == "GET") {
                int key;
                cin >> key;
                cout << cache.get(key) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
