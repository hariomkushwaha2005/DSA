class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (money < children)
            return -1;
        money = money - children;
        int x = money / 7;
        if (x > children || (x == children && money % 7 > 0))
            return children - 1;
        else if (x == children - 1 && money % 7 == 3)
            return x - 1;
        else
        {
            return x;
        }
    }
};