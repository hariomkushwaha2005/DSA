class Solution {
public:
    bool consecutiveSetBits(int n) {
        bool last = 0;
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            bool cur = (1 << i) & n;
            if (cur & last)
                cnt++;
            last = cur;
        }
        return cnt == 1;
    }
};