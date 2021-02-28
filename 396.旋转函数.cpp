/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 *
 * https://leetcode-cn.com/problems/rotate-function/description/
 *
 * algorithms
 * Medium (40.73%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 15.6K
 * Testcase Example:  '[]'
 *
 * 给定一个长度为 n 的整数数组 A 。
 * 
 * 假设 Bk 是数组 A 顺时针旋转 k 个位置后的数组，我们定义 A 的“旋转函数” F 为：
 * 
 * F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]。
 * 
 * 计算F(0), F(1), ..., F(n-1)中的最大值。
 * 
 * 注意:
 * 可以认为 n 的值小于 10^5。
 * 
 * 示例:
 * 
 * 
 * A = [4, 3, 2, 6]
 * 
 * F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
 * F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
 * F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
 * F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
 * 
 * 所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long ret = 0;
        long long sumA = 0;
        for(int i=0;i<A.size();i++){
            ret += i*A[i];
            sumA += A[i];
        }
        long long f_ret = ret;
        for(int i=A.size()-1;i>0;i--){
            f_ret = f_ret+sumA-A.size()*A[i];
            ret = max(ret, f_ret);
        }
        return ret;
    }
};
// @lc code=end

