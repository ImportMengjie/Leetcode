/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int map[] = new int[128];
        for (int i = 0, j = 0; j < s.length(); j++) {
            i = Math.max(i, map[s.charAt(j)]);
            ans = Math.max(ans, j - i + 1);
            map[s.charAt(j)] = j + 1;
        }
        return ans;

    }
}
