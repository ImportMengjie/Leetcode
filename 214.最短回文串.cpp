/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 *
 * https://leetcode-cn.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (31.05%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 25.7K
 * Testcase Example:  '"aacecaaa"'
 *
 * 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
 * 
 * 示例 1:
 * 
 * 输入: "aacecaaa"
 * 输出: "aaacecaaa"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "abcd"
 * 输出: "dcbabcd"
 * 
 */
#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        int i=0;
        for(int j=s.size()-1;j>=0;j--)
            if(s[i]==s[j]) i++;
        if(i==s.size()) return s;
        string reverse_str = s.substr(i, s.size());
        reverse(reverse_str.begin(),reverse_str.end());
        return reverse_str+shortestPalindrome(s.substr(0, i))+s.substr(i, s.size());

    }
};
// @lc code=end

