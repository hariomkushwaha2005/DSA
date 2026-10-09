#include <bits/stdc++.h>
using namespace std;

struct Node {
private:
    Node* link[2] = {nullptr};

public:
    bool contains(bool bit) { return link[bit] != nullptr; }

    void put(bool bit, Node* node) { link[bit] = node; }

    Node* get(bool bit) { return link[bit]; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            bool bit = (num >> i) & 1;
            if (!node->contains(bit)) {
                node->put(bit, new Node);
            }
            node = node->get(bit);
        }
    }

    int xorr(int num) {
        int maxx = 0;
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            bool bit = (num >> i) & 1;
            if (node->contains(1 - bit)) {
                maxx |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxx;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        Trie obj;
        for (auto num : nums) {
            obj.insert(num);
        }
        for (auto num : nums) {
            ans = max(ans, obj.xorr(num));
        }
        return ans;
    }
};