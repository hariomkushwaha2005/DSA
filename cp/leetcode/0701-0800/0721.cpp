#include <bits/stdc++.h>
using namespace std;

class DS {
    vector<int> parent, rank;

public:
    DS(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void ubr(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DS ds(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.count(accounts[i][j])) {
                    ds.ubr(i, mp[accounts[i][j]]);
                } else
                    mp[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> merge(n);
        for (auto& it : mp) {
            int node = ds.find(it.second);
            merge[node].push_back(it.first);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merge[i].empty())
                continue;
            vector<string> nope;
            nope.push_back(accounts[i][0]);
            sort(merge[i].begin(), merge[i].end());
            nope.insert(nope.end(), merge[i].begin(), merge[i].end());
            ans.push_back(nope);
        }
        return ans;
    }
};
