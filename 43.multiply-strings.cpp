/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string res(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int t = res[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = '0' + t % 10;
                res[i + j] += t / 10;
            }
        }

        for (int i = 0; i < num1.size() + num2.size(); i++)
            if (res[i] != '0')
                return res.substr(i);
        return "0";
    }
};
// @lc code=end
