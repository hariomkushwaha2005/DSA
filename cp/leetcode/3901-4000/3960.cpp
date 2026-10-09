#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLength(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> ids;
        int cnt = 0;
        for (int num : nums)
            if (!ids.count(num))
                ids[num] = cnt++;

        vector<int> freq(cnt, 0);
        vector<int> fgen(cnt, 0);
        vector<int> ffreq(n + 1, 0);
        vector<int> ffgen(n + 1, 0);
        vector<int> afreq(n + 1);
        vector<int> pos(n + 1);

        for (int i = 0; i < n; ++i)
        {
            int freqsize = 0;
            int ffreqsize = 0;

            for (int j = i; j < n; ++j)
            {
                int id = ids[nums[j]];
                if (fgen[id] != i)
                {
                    freq[id] = 0;
                    fgen[id] = i;
                }
                int oldf = freq[id];

                if (freq[id] > 0)
                {
                    ffreq[oldf]--;

                    if (ffreq[oldf] == 0)
                    {
                        --ffreqsize;
                        int curpos = pos[oldf];
                        int curfreq = afreq[ffreqsize];

                        afreq[curpos] = curfreq;
                        pos[curfreq] = curpos;
                    }
                }

                freq[id]++;
                int newf = freq[id];

                if (newf == 1)
                    freqsize++;
                if (ffgen[newf] != i)
                {
                    ffgen[newf] = i;
                    ffreq[newf] = 0;
                }
                ffreq[newf]++;

                if (ffreq[newf] == 1)
                {
                    afreq[ffreqsize] = newf;
                    pos[newf] = ffreqsize;
                    ffreqsize++;
                }

                if (freqsize == 1)
                {
                    ans = max(ans, j - i + 1);
                }
                else if (ffreqsize == 2)
                {
                    int one = afreq[0];
                    int two = afreq[1];

                    if (one == (two << 1) || two == (one << 1))
                        ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};