#
# @lc app=leetcode.cn id=290 lang=python3
#
# [290] 单词规律
#
# https://leetcode-cn.com/problems/word-pattern/description/
#
# algorithms
# Easy (42.35%)
# Likes:    152
# Dislikes: 0
# Total Accepted:    24.2K
# Total Submissions: 56.6K
# Testcase Example:  '"abba"\n"dog cat cat dog"'
#
# 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
# 
# 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
# 
# 示例1:
# 
# 输入: pattern = "abba", str = "dog cat cat dog"
# 输出: true
# 
# 示例 2:
# 
# 输入:pattern = "abba", str = "dog cat cat fish"
# 输出: false
# 
# 示例 3:
# 
# 输入: pattern = "aaaa", str = "dog cat cat dog"
# 输出: false
# 
# 示例 4:
# 
# 输入: pattern = "abba", str = "dog dog dog dog"
# 输出: false
# 
# 说明:
# 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
# 
#

# @lc code=start
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        split_str = str.split()
        if len(pattern) == len(split_str):
            pattern_dict = {}
            str_dict = {}
            for i in range(len(pattern)):
                if pattern[i] not in pattern_dict:
                    pattern_dict[pattern[i]] = i
                if split_str[i] not in str_dict:
                    str_dict[split_str[i]] = i
                if pattern_dict[pattern[i]]!=str_dict[split_str[i]]:
                    return False
            return True
        return False
        
# @lc code=end

