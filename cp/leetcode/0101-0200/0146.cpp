#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int val, int key) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    int get(int key) {
        if (mp.count(key)) {
            if (mp[key]->prev != head) {
                mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;
                mp[key]->next = head->next;
                mp[key]->prev = head;
                head->next->prev = mp[key];
                head->next = mp[key];
            }
            return mp[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            if (mp[key]->prev != head) {
                mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;
                mp[key]->next = head->next;
                mp[key]->prev = head;
                head->next->prev = mp[key];
                head->next = mp[key];
            }
            mp[key]->val = value;
        } else {
            if (mp.size() == cap) {
                mp[key] = tail->prev;
                mp.erase(mp[key]->key);
                mp[key]->key = key;
                mp[key]->val = value;
                mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;
                mp[key]->next = head->next;
                mp[key]->prev = head;
                head->next->prev = mp[key];
                head->next = mp[key];
            } else {
                mp[key] = new Node(value, key);
                mp[key]->next = head->next;
                mp[key]->prev = head;
                head->next->prev = mp[key];
                head->next = mp[key];
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */