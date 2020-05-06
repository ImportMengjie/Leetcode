/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (44.14%)
 * Likes:    411
 * Dislikes: 0
 * Total Accepted:    50K
 * Total Submissions: 112.1K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_dict_set(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.size(), false);
        queue<int> q;
        q.push(0);
        while(q.size()){
            int be = q.front();
            q.pop();
            if(!visited[be]){
                visited[be] = true;
                for(int i=be+1 ; i<=s.size();i++){
                    if(word_dict_set.find(s.substr(be, i-be))!=word_dict_set.end()){
                        q.push(i);
                        if(i==s.size())
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

