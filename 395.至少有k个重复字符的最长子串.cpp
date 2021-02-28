/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (44.32%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 32.1K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "aaabb", k = 3
 * 
 * 输出:
 * 3
 * 
 * 最长子串为 "aaa" ，其中 'a' 重复了 3 次。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "ababbc", k = 2
 * 
 * 输出:
 * 5
 * 
 * 最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 * 
 * 
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int dfs(string& s, int left, int right, int k){
        if(right-left<k) return 0;
        vector<int> cnt(26,0);
        for(int i=left;i<right;i++)
            cnt[s[i]-'a']++;
        int ret = -1;
        int i=left, j=left;
        for(;j<right;j++){
            if(cnt[s[j]-'a']<k){
                ret = max(ret, dfs(s, i, j, k));
                i = j+1;
            }
        }
        if (i>left&&i<j)
            ret = max(ret, dfs(s, i,j,k));
        return ret<0?right-left:ret;
    }

public:
    int longestSubstring(string s, int k) {
        return dfs(s, 0, s.size(), k);
    }
};
// @lc code=end

