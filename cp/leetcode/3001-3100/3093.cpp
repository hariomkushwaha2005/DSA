#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
private:
    TrieNode *link[26] = {nullptr};
    int match = -1;
    int length = 1e4;

public:
    TrieNode(int mini) { match = mini; }
    TrieNode()
    {
        //
    }
    void put(char c, TrieNode *node) { link[c - 'a'] = node; }
    TrieNode *get(char c) { return link[c - 'a']; }
    void set(int len, int ind)
    {
        if (len < length)
        {
            match = ind;
            length = len;
        }
    }
    int getm() { return match; }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (link[i] != nullptr)
            {
                delete link[i];
                link[i] = nullptr;
            }
        }
    }
};
class Trie
{
private:
    TrieNode *root;

public:
    Trie(int mini) { root = new TrieNode(mini); }
    void insertq(string &s)
    {
        int n = s.size();
        TrieNode *node = root;
        for (int i = n - 1; i >= 0; i--)
        {
            if (node->get(s[i]) == nullptr)
            {
                node->put(s[i], new TrieNode());
            }
            node = node->get(s[i]);
        }
    }
    void insertword(string &s, int a)
    {
        TrieNode *node = root;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (node->get(s[i]) != nullptr)
            {
                node = node->get(s[i]);
                node->set(n, a);
            }
            else
                break;
        }
    }
    int searchq(string &s)
    {
        int n = s.size();
        TrieNode *node = root;
        int ans = node->getm();
        for (int i = n - 1; i >= 0; i--)
        {
            node = node->get(s[i]);
            int m = node->getm();
            if (m == -1)
                break;
            ans = m;
        }
        return ans;
    }
    ~Trie() { delete root; }
};
class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer,
                              vector<string> &wordsQuery)
    {
        int minl = 1e9, mini = 0;
        for (int i = 0; i < wordsContainer.size(); i++)
        {
            if (wordsContainer[i].size() < minl)
            {
                minl = wordsContainer[i].size();
                mini = i;
            }
        }
        Trie *t = new Trie(mini);
        for (auto &it : wordsQuery)
        {
            t->insertq(it);
        }
        for (int i = 0; i < wordsContainer.size(); i++)
        {
            t->insertword(wordsContainer[i], i);
        }
        vector<int> ans;
        for (auto &it : wordsQuery)
        {
            ans.push_back(t->searchq(it));
        }
        return ans;
    }
};
