/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode-cn.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (47.39%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 25.4K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
 * 
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 * 
 * 题目数据保证答案符合 32 位带符号整数范围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：S = "rabbbit", T = "rabbit"
 * 输出：3
 * 解释：
 * 
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * 示例 2：
 * 
 * 输入：S = "babgbag", T = "bag"
 * 输出：5
 * 解释：
 * 
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size()<t.size())
            return 0;
        
       unsigned int dp[t.size()][s.size()];

       for(int i=0;i<t.size();i++){
           for(int j=i;j<s.size();j++){
               unsigned int up = i!=0?dp[i-1][j-1]:1;
               unsigned int back = i!=j?dp[i][j-1]:0;
               if(t[i]==s[j])
                   dp[i][j] = up + back;
               else
                   dp[i][j] = back;
           }
        }
        return dp[t.size()-1][s.size()-1];
    }
};
// @lc code=end

