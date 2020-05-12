/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (35.82%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    29.4K
 * Total Submissions: 81.4K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(all_of(nums.begin(),nums.end(),[](int &x){
            return x==0;
        })) return "0";

        vector<string> strNums(nums.size());
        transform(nums.begin(),nums.end(),strNums.begin(),[](int& x){return to_string(x);});

        sort(strNums.begin(),strNums.end(),[](const string& x,const string& y){return x+y>y+x;});

        return std::accumulate(strNums.begin(),strNums.end(),string());

    }
};
// @lc code=end

