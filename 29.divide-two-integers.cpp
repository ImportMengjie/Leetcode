/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        bool sign = true;
        if (dividend > 0)
        {
            dividend = -dividend;
            sign = !sign;
        }
        if (divisor > 0)
        {
            divisor = -divisor;
            sign = !sign;
        }
        int ans = 0;
        while (dividend <= divisor)
        {
            int i = 0;
            int x = divisor;
            while (true)
            {
                if (x < -(1 << 30))
                    break;
                if (dividend > x + x)
                    break;
                x = x + x;
                i++;
            }
            ans += 1 << i;
            dividend -= x;
        }
        if (ans == (1 << 31))
            return sign ? (1 << 31) - 1 : 1 << 31;
        return sign ? ans : -ans;
    }
};
// @lc code=end
