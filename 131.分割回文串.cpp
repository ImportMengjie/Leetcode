/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (66.55%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    29.6K
 * Total Submissions: 44.1K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */
#include <string>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.empty()) return ans;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        for(int right=0;right<s.size();right++)
            for(int left=0;left<=right;left++)
                dp[left][right] = s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1]);

        vector<string> path;
        backtrack(s, ans, dp, path, 0);
        return ans;
    }

    void backtrack(string& s, vector<vector<string>> &ans, vector<vector<bool>> dp, vector<string> &path, int start){
        if(s.size()){
            for(int i=0;i<s.size();i++){
                if(dp[start][start+i]){
                    path.push_back(s.substr(0, i+1));
                    string substr = s.substr(i+1, s.size());
                    backtrack(substr,ans,dp,path,start+i+1);
                    path.pop_back();
                }
            }
        }else
            ans.push_back(path);
    }

};
// @lc code=end

