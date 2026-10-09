class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
            return s;
        else if (n == 2)
            return s + m;
        long long maxx = s + 1LL * m * (n / 2) - (n - 2) / 2;
        return maxx;
    }
};