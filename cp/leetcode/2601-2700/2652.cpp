class Solution
{
public:
    int sumOfMultiples(int n)
    {
        int a = n / 3, b = n / 5, c = n / 7;
        int ans =
            (3 * a * (a + 1) / 2 + 5 * b * (b + 1) / 2 + 7 * c * (c + 1) / 2);
        a = n / 15, b = n / 35, c = n / 21;
        ans -= (15 * a * (a + 1) / 2 + 35 * b * (b + 1) / 2 +
                21 * c * (c + 1) / 2);
        a = n / 105;
        ans += (105 * (a * (a + 1) / 2));
        return ans;
    }
};