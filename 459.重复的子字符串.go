/*
 * @lc app=leetcode.cn id=459 lang=golang
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (50.95%)
 * Likes:    621
 * Dislikes: 0
 * Total Accepted:    95.6K
 * Total Submissions: 187.6K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "aba"
 * 输出: false
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 *
 *
 */
package Leetcode

// @lc code=start
func repeatedSubstringPattern(s string) (match bool) {
	match = false
	for i := 1; i*2 <= len(s); i++ {
		if len(s)%i == 0 {
			match = true
			for j := i; j < len(s); j++ {
				if s[j] != s[j-i] {
					match = false
					break
				}
			}
		}
		if match {
			return match
		}
	}
	return match
}

// @lc code=end
