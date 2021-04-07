/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (55.43%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    73.9K
 * Total Submissions: 133.3K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> m(128,0);
        for(char& c:s)
            m[c]++;
        int ans = 0;
        for(auto& num:m){
            ans += num/2*2;
            if(ans%2==0&&num%2==1)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

