/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (46.93%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    104.4K
 * Total Submissions: 220.7K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 
 * 
 * 示例：
 * 
 * s = "leetcode"
 * 返回 0
 * 
 * s = "loveleetcode"
 * 返回 2
 * 
 * 
 * 
 * 
 * 提示：你可以假定该字符串只包含小写字母。
 * 
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {

public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (char &c : s) {
            if (m.count(c))
                m[c]++;
            else
                m[c] = 1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
