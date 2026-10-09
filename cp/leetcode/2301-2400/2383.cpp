#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience,
                         vector<int> &energy, vector<int> &experience)
    {
        int ene = 0;
        for (auto &x : energy)
        {
            ene += x;
        }
        int ans = max(0, ene + 1 - initialEnergy);
        int exp = initialExperience;
        for (auto &x : experience)
        {
            if (exp <= x)
            {
                ans += (x - exp + 1);
                exp = x + 1;
            }
            exp += x;
        }
        return ans;
    }
};