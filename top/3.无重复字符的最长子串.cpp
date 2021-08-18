/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.76%)
 * Likes:    5928
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 3.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: s = ""
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */
#include <string>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring2(string s) {
        int ans = 0;
        int map[256] = {0};
        for(int left=0,right=0;right<s.size();right++){
            left = max(left, map[s[right]]);
            ans = max(ans, right-left+1);
            map[s[right]] = right+1;
        }
        return ans;
    }

    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        int right = 1, ans = 1;
        set<char> st;
        for(int left=0;left<s.size();left++){
            st.insert(s[left]);
            right = max(right, left+1);
            while(right<s.size()&&!st.count(s[right])){
                st.insert(s[right]);
                right++;
            }
            ans = max(ans, right-left);
            st.erase(s[left]);
        }
        return ans;
    }
};
// @lc code=end

