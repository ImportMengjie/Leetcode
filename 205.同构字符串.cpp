/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (47.29%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    37.4K
 * Total Submissions: 79.2K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string isIsomorphicHelper(string str){
        string ans = "";
        unordered_map<char, int> m;
        int count = 0;
        for(char& n:str){
            if(!m.count(n))
                m[n] = count++;
            ans.push_back(m[n]+'0');
        }
        return ans;
    }

    bool isIsomorphic(string s, string t) {
        return isIsomorphicHelper(s)==isIsomorphicHelper(t);
    }

};
// @lc code=end

