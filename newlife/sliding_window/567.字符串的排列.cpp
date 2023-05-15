/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode.cn/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.42%)
 * Likes:    914
 * Dislikes: 0
 * Total Accepted:    260.4K
 * Total Submissions: 586.1K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含
 * s1 的排列。如果是，返回 true ；否则，返回 false 。
 *
 * 换句话说，s1 的排列之一是 s2 的 子串 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s1 = "ab" s2 = "eidbaooo"
 * 输出：true
 * 解释：s2 包含 s1 的排列之一 ("ba").
 *
 *
 * 示例 2：
 *
 *
 * 输入：s1= "ab" s2 = "eidboaoo"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 和 s2 仅包含小写字母
 *
 *
 */
#include <array>
#include <string>

using namespace std;

// @lc code=start
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        std::array<int, 256> m{0};
        for (auto& c : s1) m[c]++;
        int needCnt = s1.size();
        for (int i = 0, j = 0; j < s2.size(); j++) {
            if (m[s2[j]] > 0) needCnt--;
            m[s2[j]]--;
            int len = j - i + 1;
            if (len > s1.size()) {
                if (m[s2[i]] >= 0) needCnt++;
                m[s2[i]]++;
                i++;
                len--;
            }
            if (len == s1.size() && needCnt == 0) return true;
        }
        return false;
    }
};
// @lc code=end
