/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 *
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/description/
 *
 * algorithms
 * Medium (47.58%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    2.7K
 * Total Submissions: 5.6K
 * Testcase Example:  '"cdadabcc"'
 *
 * 返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："cdadabcc"
 * 输出："adbc"
 * 
 * 
 * 示例 2：
 * 
 * 输入："abcd"
 * 输出："abcd"
 * 
 * 
 * 示例 3：
 * 
 * 输入："ecbacba"
 * 输出："eacb"
 * 
 * 
 * 示例 4：
 * 
 * 输入："leetcode"
 * 输出："letcod"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 1000
 * text 由小写英文字母组成
 * 
 * 
 * 
 * 
 * 注意：本题目与 316 https://leetcode-cn.com/problems/remove-duplicate-letters/ 相同
 * 
 */
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
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

