/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        int pop = 0;
        int max = (1 << 31) - 1;
        int min = 1 << 31;

        while (x != 0)
        {
            pop = x % 10;
            x /= 10;
            if (rev > max / 10 || (rev == max / 10 && pop > (max % 10)))
                return 0;
            if (rev < min / 10 || (rev == min / 10 && pop < (min % 10)))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
