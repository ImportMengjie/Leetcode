/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (35.07%)
 * Likes:    3969
 * Dislikes: 0
 * Total Accepted:    684.6K
 * Total Submissions: 2M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int max = 1, left = 0;
        for(int i=0;i<s.size();i++){
            dp[i][i] = true;
            if(i+1<s.size()&&s[i]==s[i+1]){
                dp[i][i+1] = true;
                max = 2;
                left = i;
            }
        }
        for(int l=3;l<=s.size();l++){
            for(int i=0;i+l-1<s.size();i++){
                int j = i+l-1;
                if(s[i]==s[j]&&dp[i+1][j-1]){
                    dp[i][j] = true;
                    max = l;
                    left = i;
                }
            }
        }
        return s.substr(left, max);
    }
};
// @lc code=end

