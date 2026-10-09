#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> f(n, vector<int>(m, 0));
        vector<vector<int>> g(n, vector<int>(m, 0));
        vector<vector<int>> h(n, vector<int>(m, 0));

        f[0][0] = mat[0][0];
        g[0][m - 1] = mat[0][m - 1];
        g[n - 1][0] = mat[n - 1][0];
        h[n - 1][m - 1] = mat[n - 1][m - 1];

        for (int i = 1; i < n; ++i) {
            f[i][0] = mat[i][0];
            g[i][m - 1] = mat[i][m - 1];
            int ri = n - 1 - i;
            h[ri][m - 1] = max(h[ri + 1][m - 1], mat[ri][m - 1]);
        }

        for (int i = 1; i < m; ++i) {
            f[0][i] = mat[0][i];
            g[n - 1][i] = mat[n - 1][i];
            int ri = m - 1 - i;
            h[n - 1][ri] = max(h[n - 1][ri + 1], mat[n - 1][ri]);
        }

        for (int i = 1; i < n; ++i) {
            int ri = n - i - 1;
            for (int j = 1; j < m; ++j) {
                int rj = m - j - 1;
                if (mat[i][j])
                    f[i][j] =
                        1 + min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]});
                if (mat[ri][rj])
                    g[ri][rj] = 1 + min({g[ri + 1][rj], g[ri][rj + 1],
                                         g[ri + 1][rj + 1]});
                h[ri][rj] = max({h[ri + 1][rj], h[ri][rj + 1], g[ri][rj]});
            }
        }

        int maxx = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int z = 0;
                if (i + 1 < n)
                    z = max(z, h[i + 1][0]);
                if (j + 1 < m)
                    z = max(z, h[0][j + 1]);
                maxx = max(maxx, min(f[i][j], z));
            }

        return maxx * maxx;
    }
};