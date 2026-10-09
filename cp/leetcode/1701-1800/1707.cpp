#include <bits/stdc++.h>
using namespace std;

struct Node
{
private:
    Node *link[2] = {nullptr};

public:
    bool contains(bool bit) { return link[bit] != nullptr; }
    void put(bool bit, Node *node) { link[bit] = node; }
    Node *get(bool bit) { return link[bit]; }
};
class Trie
{
private:
    Node *root;

public:
    Trie() { root = new Node(); }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            bool bit = (num >> i) & 1;
            if (!node->contains(bit))
            {
                node->put(bit, new Node);
            }
            node = node->get(bit);
        }
    }
    int getxor(int num)
    {
        Node *node = root;
        int maxx = 0;
        for (int i = 31; i >= 0; i--)
        {
            bool bit = (num >> i) & 1;
            if (node->contains(1 - bit))
            {
                maxx |= (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxx;
    }
};
class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        Trie obj;
        sort(nums.begin(), nums.end());
        int n = queries.size();
        vector<vector<int>> nq;
        int i = 0;
        for (auto &it : queries)
        {
            nq.push_back({it[1], it[0], i});
            i++;
        }
        sort(nq.begin(), nq.end());
        vector<int> ans(n, -1);
        int j = 0;
        for (auto &it : nq)
        {
            while (j < nums.size() && nums[j] <= it[0])
            {
                obj.insert(nums[j]);
                j++;
            }
            if (j != 0)
                ans[it[2]] = obj.getxor(it[1]);
        }
        return ans;
    }
};