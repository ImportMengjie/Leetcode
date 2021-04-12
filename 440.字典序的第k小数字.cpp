/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 *
 * https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (36.97%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 32.5K
 * Testcase Example:  '13\n2'
 *
 * 给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。
 * 
 * 注意：1 ≤ k ≤ n ≤ 10^9。
 * 
 * 示例 :
 * 
 * 
 * 输入:
 * n: 13   k: 2
 * 
 * 输出:
 * 10
 * 
 * 解释:
 * 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
 * 
 * 
 */
#include <algorithm>

// @lc code=start
class Solution {
public:
    int count(long long c1, long long c2, const long long& n){
        int step = 0;
        while(c1<=n){
            step += std::min(c2, n+1) - c1;
            c1 *= 10;
            c2 *= 10;
        }
        return step;
    }

    int findKthNumber(int n, int k) {
        long long cur = 1;
        k--;
        while(k){
            int step = count(cur, cur+1, n);
            if(step<=k){
                k -= step;
                cur++;
            }else{
                k--;
                cur*=10;
            }
        }
        return cur;
    }
};
// @lc code=end

