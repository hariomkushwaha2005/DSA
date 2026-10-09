class Solution
{
public:
    bool checkGoodInteger(int n)
    {
        int diff = 0;
        while (n > 0)
        {
            int ld = n % 10;
            diff += ld * (ld - 1);
            if (diff >= 50)
                return true;
            n /= 10;
        }
        return false;
    }
};