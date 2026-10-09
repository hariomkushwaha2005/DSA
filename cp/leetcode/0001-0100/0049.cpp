#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    vector<string> anagrams;
    Node* links[26];
    Node() {
        for (int i = 0; i < 26; ++i)
            links[i] = nullptr;
    }
};
class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }
    Node* insert(string& key) {
        Node* temp = root;
        string cur = key;
        sort(cur.begin(), cur.end());
        for (char c : cur) {
            if (temp->links[c - 'a'] == nullptr) {
                temp->links[c - 'a'] = new Node();
            }
            temp = temp->links[c - 'a'];
        }
        temp->anagrams.push_back(key);
        return temp;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        Trie trie;
        vector<Node*> res;
        for (int i = 0; i < n; ++i) {
            res.push_back(trie.insert(strs[i]));
        }
        vector<vector<string>> ans;
        for (auto it : res) {
            if (!it->anagrams.empty()) {
                ans.push_back(it->anagrams);
                it->anagrams = {};
            }
        }
        return ans;
    }
};