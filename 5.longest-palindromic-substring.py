#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#


class Solution:
    def longestPalindrome(self, s: str) -> str:
        return self.method2(s)

    def method1(self, s: str) -> str:
        table = [[-1]*len(s) for i in range(0, len(s))]
        for i in range(0, len(s)):
            self.construct_table(table, s, 0, i)
            self.construct_table(table, s, i, len(s)-1)
        max_len, ans_i, ans_j = 0, 0, 0
        for i in range(0, len(s)):
            for j in range(0, len(s)):
                if table[i][j] > max_len:
                    max_len = table[i][j]
                    ans_i, ans_j = i, j
        return s[ans_i:ans_j+1]

    def method2(self, s: str) -> str:
        ans_i, ans_j = 0, 0
        for i in range(0, len(s)):
            len1 = self.expand_around_center(s, i, i)
            len2 = self.expand_around_center(s, i, i+1)
            if max(len1, len2) > ans_j-ans_i+1:
                ans_i = i - (max(len1, len2)-1)//2
                ans_j = i + max(len1, len2)//2
        return s[ans_i:ans_j+1]

    def expand_around_center(self, s: str, left, right):
        l, r = left, right
        while l <= r and l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return r-l+1-2

    def construct_table(self, table, s: str, i, j):
        if table[i][j] >= 0 or j < i:
            pass
        elif i == j:
            table[i][j] = 1
        elif i+1 == j:
            table[i][j] = 2 if s[i] == s[j] else 0
        else:
            self.construct_table(table, s, i + 1, j - 1)
            table[i][j] = j-i+1 if table[i+1][j-1] > 0 and s[i] == s[j] else 0
