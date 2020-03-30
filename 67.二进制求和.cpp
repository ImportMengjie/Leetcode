/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.31%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    72.3K
 * Total Submissions: 138.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 && j >= 0)
        {
            int a_bit = a[i] - '0';
            int b_bit = b[j] - '0';
            int t = a_bit + b_bit + carry;
            char c = t % 2 + '0';
            ans = string(&c, 1) + ans;
            carry = t / 2;
            i--;
            j--;
        }
        if (i >= 0 || j >= 0)
        {
            string &left = i >= 0 ? a : b;
            int i = i >= 0 ? i : j;
            while (i >= 0)
            {
                int t = (left[i] - '0') + carry;
                char c = t % 2 + '0';
                carry = t / 2;
                ans = string(&c, 1) + ans;
                i--;
            }
        }
        if (carry > 0)
            ans = "1" + ans;
        return ans;
    }
};
// @lc code=end
