package Leetcode

import (
	"strconv"
	"strings"
)

/*
 * @lc app=leetcode.cn id=423 lang=golang
 *
 * [423] 从英文中重建数字
 *
 * https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (56.87%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 15.6K
 * Testcase Example:  '"owoztneoer"'
 *
 * 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "owoztneoer"
 * 输出："012"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "fviefuro"
 * 输出："45"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]
 * 这些字符之一
 * s 保证是一个符合题目要求的字符串
 *
 *
 */

// @lc code=start
func originalDigits(s string) string {

	var m [26]int
	for i := 0; i < len(s); i++ {
		m[s[i]-'a']++
	}
	var out [10]int
	out[0] = m['z'-'a']
	out[2] = m['w'-'a']
	out[4] = m['u'-'a']
	out[6] = m['x'-'a']
	out[8] = m['g'-'a']

	out[3] = m['h'-'a'] - out[8]
	out[5] = m['f'-'a'] - out[4]
	out[7] = m['s'-'a'] - out[6]

	out[9] = m['i'-'a'] - out[5] - out[6] - out[8]
	out[1] = m['n'-'a'] - out[7] - 2*out[9]

	ret := ""
	for i := 0; i < 10; i++ {
		if out[i] > 0 {
			ret += strings.Repeat(strconv.Itoa(i), out[i])
		}
	}
	return ret
}

// @lc code=end
