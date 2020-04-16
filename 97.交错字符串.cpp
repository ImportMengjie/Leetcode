/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (39.36%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    11.9K
 * Total Submissions: 30.3K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出: false
 * 
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        bool dp[s1.size()+1][s2.size()+1];

        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(i==0&&j==0)
                    dp[i][j] = true;
                else if(j==0)
                    dp[i][j] = dp[i-1][j] && s1[i-1]==s3[i+j-1];
                else if(i==0)
                    dp[i][j] = dp[i][j-1] && s2[j-1]==s3[i+j-1];
                else
                    dp[i][j] = (s1[i-1]==s3[i+j-1]&&dp[i-1][j])||(s2[j-1]==s3[i+j-1]&&dp[i][j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
// @lc code=end

