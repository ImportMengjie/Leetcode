/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (38.81%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 33.3K
 * Testcase Example:  '"bcabc"'
 *
 * 
 * 给你一个仅包含小写字母的字符串，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: "bcabc"
 * 输出: "abc"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "cbacdcbc"
 * 输出: "acdb"
 * 
 * 
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 */
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> last_occurrence;
        unordered_set<int> seen;
        stack<char> ans;
        for(int i=0;i<s.size();i++)
            last_occurrence[s[i]] = i;
        for(int i=0;i<s.size();i++){
            if(!seen.count(s[i])){
                while(ans.size()&&ans.top()>s[i]&&last_occurrence[ans.top()]>i){
                    seen.erase(ans.top());
                    ans.pop();
                }
                ans.push(s[i]);
                seen.insert(s[i]);
            }
        }
        string ret;
        while (ans.size()) {
            ret = ans.top()+ret;
            ans.pop();
        }
        return ret;
    }
};
// @lc code=end

