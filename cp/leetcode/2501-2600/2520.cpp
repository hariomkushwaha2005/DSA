class Solution {
public:
    int countDigits(int num) {
        int c = num;
        int cnt = 0;
        while (c > 0) {
            int ld = c % 10;
            c /= 10;
            if (num % ld == 0)
                cnt++;
        }
        return cnt;
    }
};