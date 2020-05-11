/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (25.80%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 41.9K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 示例 1:
 * 
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 * 
 * 
 * 示例 2:
 * 
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 * 
 * 示例 3:
 * 
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 * 
 * 
 */
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        if(!denominator) return "";
        string ans;
        auto num = static_cast<long long>(numerator);
        auto denom = static_cast<long long>(denominator);
        if((num>0)^(denom>0)) ans.push_back('-');
        num = llabs(num);
        denom = llabs(denom);

        ans.append(to_string(num/denom));
        num%=denom;
        if(num){
            ans.push_back('.');
            int insert_ids = ans.size()-1;

            unordered_map<int,int> record;
            while(num&&!record.count(num)){
                record[num] = ++insert_ids;
                num*=10;
                ans+=to_string(num/denom);
                num%=denom;
            }
            if(record.count(num)){
                ans.insert(record[num],"(");
                ans.push_back(')');
            }
        }
        return ans;
    }
};
// @lc code=end

