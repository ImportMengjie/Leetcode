/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (43.64%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    135.5K
 * Total Submissions: 310.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1] += 1;
        if(digits[digits.size()-1]>=10){
            int carry = 1;
            digits[digits.size()-1] = 0;
            for(int i=digits.size()-2;i>=0&&carry==1;i--){
                int t = digits[i]+1;
                if(t>9){
                    digits[i]=0;
                    carry = 1;
                }else{
                    digits[i] = t;
                    carry = 0;
                    break;
                }
            }
            if(carry==1)
                digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
// @lc code=end

