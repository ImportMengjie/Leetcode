/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode-cn.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (53.16%)
 * Likes:    675
 * Dislikes: 0
 * Total Accepted:    80.8K
 * Total Submissions: 149.4K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "3[a]2[bc]"
 * 输出："aaabcbc"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "3[a2[c]]"
 * 输出："accaccacc"
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "2[abc]3[cd]ef"
 * 输出："abcabccdcdcdef"
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "abc3[cd]xyz"
 * 输出："abccdcdcdxyz"
 * 
 * 
 */
#include <string>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    
    string getDigits(string &s, int &start){
        string ret = "";
        while(isdigit(s[start]))
            ret.push_back(s[start++]);
        return ret;
    }
    string getString(vector<string>& strs){
        string ret;
        for (auto& s:strs)
            ret+=s;
        return ret;
    }

    string decodeString(string s) {
        vector<string> stk;
        string ret = "";
        int i = 0;
        while (i<s.size()){
            if(isdigit(s[i]))
                stk.push_back(getDigits(s, i));
            else if(isalpha(s[i]) || s[i] == '[')
                stk.push_back(string(1,s[i++]));
            else{
                i++;
                vector<string> sub;
                while(stk.back()!="["){
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                reverse(sub.begin(), sub.end());
                string subString = getString(sub);
                int repeat = stoi(stk.back());
                stk.pop_back();
                string repString = "";
                while(repeat--)
                    repString+=subString;
                stk.push_back(repString);
            }
        }
        return getString(stk);
    }
};
// @lc code=end

