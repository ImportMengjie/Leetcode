/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 *
 * https://leetcode-cn.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (71.87%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 18.1K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n, 返回从 1 到 n 的字典顺序。
 * 
 * 例如，
 * 
 * 给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
 * 
 * 请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {

public:
    void dfs(vector<int> &ans, int num, int n) {
        if (num <= n) {
            ans.push_back(num);
            for (int i = 0; i < 10; i++)
                dfs(ans, num * 10 + i, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i < 10; i++)
            dfs(ans, i, n);
        return ans;
    }
};
// @lc code=end
