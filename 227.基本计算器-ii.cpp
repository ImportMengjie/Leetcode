/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode-cn.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (35.02%)
 * Likes:    133
 * Dislikes: 0
 * Total Accepted:    16.7K
 * Total Submissions: 46.4K
 * Testcase Example:  '"3+2*2"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 
 * 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
 * 
 * 示例 1:
 * 
 * 输入: "3+2*2"
 * 输出: 7
 * 
 * 
 * 示例 2:
 * 
 * 输入: " 3/2 "
 * 输出: 1
 * 
 * 示例 3:
 * 
 * 输入: " 3+5 / 2 "
 * 输出: 5
 * 
 * 
 * 说明：
 * 
 * 
 * 你可以假设所给定的表达式都是有效的。
 * 请不要使用内置的库函数 eval。
 * 
 * 
 */
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int calHelper(string& s, int& i){
        char operation = '+';
        stack<int> nums;
        int num=0,res=0;
        bool flag = false;

        for(;i<s.size();i++){
            if('0'<=s[i]&&s[i]<='9')
                num=num*10 + (s[i]-'0');
            else if(s[i]=='('){
                num = calHelper(s, ++i);
                i++;
            }
            if((s[i]!=' '&&(s[i]<'0'||s[i]>'9'))||i==s.size()-1){
                int pre = 0;
                switch (operation) {
                case '+':
                    nums.push(num);
                    break;
                case '-':
                    nums.push(-num);
                    break;
                case '*':
                    pre = nums.top();
                    nums.pop();
                    nums.push(pre*num);
                    break;
                case '/':
                    pre = nums.top();
                    nums.pop();
                    nums.push(pre/num);
                    break;
                }
                operation = s[i];
                num = 0;

            }
            if(s[i]==')')
                break;

        }
        while (nums.size()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }

    int calculate(string s) {
        int be = 0;
        return calHelper(s, be);

    }
};
// @lc code=end

