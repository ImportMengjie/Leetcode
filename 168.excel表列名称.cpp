/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (37.21%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 67.6K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n>0){
            ans.push_back('A'+(n-1)%26);
            n = (n-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

