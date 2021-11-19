package Leetcode

/*
 * @lc app=leetcode.cn id=438 lang=golang
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (51.49%)
 * Likes:    645
 * Dislikes: 0
 * Total Accepted:    103.5K
 * Total Submissions: 198.7K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 *
 *
 */

// @lc code=start

func equalMap(m1 map[byte]int, m2 map[byte]int) bool {
	for k, v := range m1 {
		if v2, exist := m2[k]; !exist || v2 != v {
			return false
		}
	}
	return true
}

func findAnagrams(s string, p string) []int {
	if len(s) < len(p) {
		return []int{}
	}

	ret := make([]int, 0)
	pMap := make(map[byte]int)
	sMap := make(map[byte]int)

	for i := 0; i < len(p); i++ {
		pMap[p[i]]++
		sMap[s[i]]++
	}
	for i, j := 0, len(p)-1; j < len(s); i, j = i+1, j+1 {
		if equalMap(pMap, sMap) {
			ret = append(ret, i)
		}
		if j+1 < len(s) {
			sMap[s[i]]--
			sMap[s[j+1]]++
		}
	}
	return ret
}

// @lc code=end
