/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 *
 * https://leetcode-cn.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (34.44%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 21.3K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 * 
 * 示例:
 * 
 * 输入: 13
 * 输出: 6 
 * 解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
 * 
 */

#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for(long long i=1;i<=n;i*=10){
            long long div = i*10;
            count += (n/div)*i + min(i,max(n%div-i+1, 0LL));
        }
        return count;
    }
};
// @lc code=end

