/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.23%)
 * Likes:    229
 * Dislikes: 0
 * Total Accepted:    35K
 * Total Submissions: 75.6K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isVaild(string &&s){
        int val = stoi(s);
        if(val>255) return false;
        if(s.size()>1&&s[0]=='0') return false;
        return true;
    }

    void backtrack(vector<string> &ans, vector<string> &path, string &s,int i){
        if(s.size()-i>(4-path.size())*3) return;
        if(path.size()==4 && i==s.size()){
            string temp= "";
            for(int ids=0; ids<path.size();ids++){
                temp += path[ids];
                if(ids<3) temp+=".";
            }
            ans.push_back(temp);
            return;
        }
        for(int len=1;len<=3 && i+len<=s.size();len++){
            if(isVaild(s.substr(i,len))){
                path.push_back(s.substr(i,len));
                backtrack(ans, path, s, i+len);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans,path;
        backtrack(ans, path, s, 0);
        return ans;
    }
};
// @lc code=end

