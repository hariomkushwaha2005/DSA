#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool end;
    Node* links[26];
    Node() {
        end = false;
        for (int i = 0; i < 26; ++i)
            links[i] = nullptr;
    }
};
void osearch(Node* node, string& s, string& ans) {
    for (int i = 0; i < 26; ++i) {
        if (node->links[i] && node->links[i]->end) {
            s.push_back('a' + i);
            osearch(node->links[i], s, ans);
            s.pop_back();
        }
    }
    if (s.length() > ans.length() || (s.length() == ans.length() && s < ans))
        ans = s;
}
class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }
    void insert(string& key) {
        Node* temp = root;
        for (char c : key) {
            if (!temp->links[c - 'a']) {
                temp->links[c - 'a'] = new Node;
            }
            temp = temp->links[c - 'a'];
        }
        temp->end = true;
    }
    void search(string& s, string& ans) { osearch(root, s, ans); }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for (string& s : words)
            t.insert(s);

        string ans = "";
        string s = "";
        t.search(ans, s);
        return s;
    }
};