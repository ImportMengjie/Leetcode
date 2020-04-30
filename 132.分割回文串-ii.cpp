/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (42.57%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 23.8K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回符合要求的最少分割次数。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出: 1
 * 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 */
#include <string>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:

    int minCut(string s) {
        vector<vector<bool>> checkPalindrome(s.size(), vector<bool>(s.size(), false));
        for(int right=0;right<s.size();right++)
            for(int left=0;left<=right;left++)
                checkPalindrome[left][right] = s[right]==s[left]&&(right-left<=2||checkPalindrome[left+1][right-1]);
        int dp[s.size()];

        for(int i=0;i<s.size();i++){
            if(checkPalindrome[0][i])
                dp[i] = 0;
            else{
                int min_cut = s.size();               
                for(int j=0;j<i;j++)
                    if(checkPalindrome[j+1][i])
                        min_cut = min(min_cut, dp[j]);
                dp[i] = min_cut+1;
            }
        }
        return dp[s.size()-1];
    }

    int minCut2(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int right=0;right<s.size();right++)
            for(int left=0;left<=right;left++)
                dp[left][right] = s[right]==s[left]&&(right-left<=2||dp[left+1][right-1]);

        queue<int> q;
        q.push(0);
        int ans = -1;
        while(q.size()){
            int queue_size = q.size();
            ans++;
            for(int i=0;i<queue_size;i++){
                int be = q.front();
                q.pop();
                if(dp[be][s.size()-1]) return ans;
                for(int ids = be; ids<s.size();ids++){
                    if(dp[be][ids])
                        q.push(ids+1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

