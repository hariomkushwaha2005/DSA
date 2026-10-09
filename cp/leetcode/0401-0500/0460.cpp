#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int key;
    int data;
    int cnt;
    Node(int _key, int _data) {
        next = nullptr;
        prev = nullptr;
        key = _key;
        data = _data;
        cnt = 1;
    }
};
class List {
public:
    Node* head;
    Node* tail;
    int size;
    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void add(Node* temp) {
        temp->next = head->next;
        temp->prev = head;
        head->next = temp;
        temp->next->prev = temp;
        size++;
    }
    void remove(Node* temp) {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->next = nullptr;
        temp->prev = nullptr;
        size--;
    }
};
class LFUCache {
public:
    int cursize;
    int cap;
    unordered_map<int, Node*> mp;
    unordered_map<int, List*> freq;
    int minfreq;

    LFUCache(int capacity) {
        minfreq = 0;
        cursize = 0;
        cap = capacity;
        mp = {};
        freq = {};
    }
    void update(Node* temp) {
        freq[temp->cnt]->remove(temp);
        if (temp->cnt == minfreq && freq[minfreq]->size == 0)
            minfreq++;
        temp->cnt++;
        if (!freq.count(temp->cnt))
            freq[temp->cnt] = new List();
        freq[temp->cnt]->add(temp);
    }
    int get(int key) {
        if (mp.count(key)) {
            update(mp[key]);
            return mp[key]->data;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->data = value;
            update(mp[key]);
        } else {
            if (cursize == cap) {
                mp.erase(freq[minfreq]->tail->prev->key);
                freq[minfreq]->remove(freq[minfreq]->tail->prev);
                cursize--;
            }
            minfreq = 1;
            Node* temp = new Node(key, value);
            if (!freq.count(temp->cnt))
                freq[temp->cnt] = new List();
            freq[temp->cnt]->add(temp);
            mp[key] = temp;
            cursize++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */