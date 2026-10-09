#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* link[10] = {nullptr};
    bool contains(int a) { return link[a] != nullptr; }
    void put(int a, Node* node) { link[a] = node; }
    Node* get(int a) { return link[a]; }
    ~Node() {
        for (int i = 0; i < 10; i++) {
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
    ~Trie() { delete root; }
    void insert(int num) {
        string s = to_string(num);
        Node* node = root;
        for (char c : s) {
            if (!node->contains(c - '0')) {
                node->put(c - '0', new Node());
            }
            node = node->get(c - '0');
        }
    }
    int prefix(int num) {
        string s = to_string(num);
        Node* node = root;
        int x = 0;
        for (char c : s) {
            if (node->contains(c - '0'))
                node = node->get(c - '0');
            else
                return x;
            x++;
        }
        return x;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie T;
        for (int a : arr1) {
            T.insert(a);
        }
        int ans = 0;
        for (int num : arr2) {
            ans = max(ans, T.prefix(num));
        }
        return ans;
    }
};