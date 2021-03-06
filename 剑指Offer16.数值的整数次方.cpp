/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        for (long long i = N; i > 0; i /= 2) {
            if (i % 2 == 1)
                ans *= current_product;
            current_product = current_product * current_product;
        }
        return ans;
    }
};
// @lc code=end
