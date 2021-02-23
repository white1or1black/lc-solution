#include<iostream>
#include<unordered_map>
using namespace std;


struct Node {
    int value;
    Node *nxt;
    Node *last;
    Node (int val):value(val), nxt(nullptr), last(nullptr) {}
};

class List {
    private:
    Node* head;
    Node* tail;
    int len;
public:
    List() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    int size() {
        return len;
    }
    void top(Node* node) {
        if (node == head) return;
        Node* last = node->last;
        Node* nxt = node->nxt;
        if (last != nullptr) last->nxt = nxt;
        if (nxt != nullptr) nxt->last = last;
        node->nxt = head;
        head->last = node;
        head = node;
        if (tail == node) tail = last;
    }

    void remove(Node* cur) {
        if (len == 0) return;
        len--;
        Node* last = cur->last;
        Node* nxt = cur->nxt;
        if (last == nullptr) {
            head = cur->nxt;
            if (cur->nxt != nullptr) cur->nxt->last = nullptr;
        } else {
            last->nxt = nxt;
            if (nxt != nullptr) nxt->last = last;
        }
        if (cur == tail) tail = last;
    }

    Node* push_back(int val) {
        Node* node = new Node(val);
        tail->nxt = node;
        node->last = tail;
        tail = node;
        len++;
        return node;
    }

    Node* push_front(int val) {
        Node* node = new Node(val);
        node->nxt = head;
        if (head != nullptr) head->last = node;
        if (head == nullptr) tail = node;
        head = node;
        len++;
        return node;
    }

    Node* back() {
        return tail;
    }

    void pop_back() {
        Node* last = tail->last;
        tail->last = nullptr;
        if (last != nullptr) last->nxt = nullptr;
        tail = last;
        len--;
    }

    Node* front() {
        return head;
    }

    void pop_front() {
        if (head == nullptr) return;
        Node* n = head->nxt;
        head->nxt = nullptr;
        n->last = nullptr;
        head = n;
        len--;
    }
    void print() {
        Node* dummy = head;
        while (dummy != nullptr) {
            cout << dummy->value << " ";
            dummy = dummy->nxt;
        }
        cout << endl;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> k2pos;
    unordered_map<int, int> kv;
    List node_list;
    int len;
    LRUCache(int capacity) {
        cap = capacity;
        len = 0;
    }

    int get(int key) {
        if (kv.find(key) != kv.end()) {
            node_list.top(k2pos[key]);
            return kv[key];
        }
        return -1;
    }

    void put(int key, int value) {
        if (kv.find(key) != kv.end()) {
            node_list.top(k2pos[key]);
            kv[key] = value;
            return;
        }

        Node* front = node_list.push_front(key);
        if (node_list.size() > cap) {
            Node* tail = node_list.back();
            node_list.pop_back();
            kv.erase(tail->value);
            k2pos.erase(tail->value);
        }
        kv[key] = value;
        k2pos[key] = front;
    }
    void print() {
        node_list.print();
    }
};

int main() {
    LRUCache* obj = new LRUCache(1);
    obj->put(2,1);
    obj->print();
    cout << "res: " << obj->get(2) << endl;
    obj->print();
    obj->put(3,2);
    obj->print();
    cout << "res: " << obj->get(2) << endl;
    obj->print();
    cout << "res: " << obj->get(3) << endl;
    obj->print();
    return 0;
}
