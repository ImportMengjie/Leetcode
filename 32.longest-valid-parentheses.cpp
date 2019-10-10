/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() < 2)
            return 0;
        int max_len = 0;
        vector<int> dp = {0};
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ')' && s[i - 1] == '(')
                dp.push_back(i - 2 >= 0 ? dp[i - 2] + 2 : 2);
            else if (s[i] == ')' && s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                dp.push_back(i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] + 2 + dp[i - 1] : dp[i - 1] + 2);
            else
                dp.push_back(0);
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
// @lc code=end
