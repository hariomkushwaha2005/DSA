#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* link[26] = {nullptr};
    bool flag = false;
    bool containskey(char c) { return link[c - 'a'] != nullptr; }
    bool isend() { return flag; }
    void setend() { flag = true; }
    void put(char c, Node* node) { link[c - 'a'] = node; }
    Node* get(char c) { return link[c - 'a']; }
    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (link[i] != nullptr) {
                delete link[i];
                link[i] = nullptr;
            }
        }
    }
};
class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (auto c : word) {
            if (!node->containskey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setend();
    }

    bool search(string word) {
        Node* node = root;
        for (auto c : word) {
            if (!node->containskey(c)) {
                return false;
            }
            node = node->get(c);
        }
        return node->isend();
    }

    bool startsWith(string word) {
        Node* node = root;
        for (auto c : word) {
            if (!node->containskey(c)) {
                return false;
            }
            node = node->get(c);
        }
        return true;
    }
    ~Trie() { delete root; }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */