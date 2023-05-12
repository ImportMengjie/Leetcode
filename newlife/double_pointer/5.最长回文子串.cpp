/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int maxLen = 1, begin = 0;
        for(int i=0;i<s.size();i++)
            dp[i][i] = true;
        for(int j=1;j<s.size();j++){
            dp[j-1][j] = s[j-1] == s[j];
            if(dp[j-1][j]) {
                maxLen = 2;
                begin = j-1;
            }
        }
        for(int L=2;L<s.size();L++) {
            for(int i=0,j=L;j<s.size();j++,i++) {
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                if(dp[i][j]&&j-i+1>maxLen) {
                    maxLen = j-i+1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
// @lc code=end

