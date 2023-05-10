/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (80.59%)
 * Likes:    2029
 * Dislikes: 0
 * Total Accepted:    622.1K
 * Total Submissions: 767.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有元素 互不相同
 * 
 * 
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:

    void backtrack(vector<vector<int>>& ans,vector<int>& nums, vector<int>&& path, int start){
        ans.push_back(path);
        for(int i=start;i<nums.size();i++) {
            path.push_back(nums[i]);
            backtrack(ans, nums, std::move(path), i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, {}, 0);
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        本质是动态规划思想，属于较简单的线性动规。
        可以这么表示，dp[i]表示前i个数的解集，dp[i] = dp[i - 1] + collections(i)。其中，collections(i)表示把dp[i-1]的所有子集都加上第i个数形成的子集。
        【具体操作】
        因为nums大小不为0，故解集中一定有空集。令解集一开始只有空集，然后遍历nums，每遍历一个数字，拷贝解集中的所有子集，将该数字与这些拷贝组成新的子集再放入解集中即可。时间复杂度为O(n^2)。
        例如[1,2,3]，一开始解集为[[]]，表示只有一个空集。
        遍历到1时，依次拷贝解集中所有子集，只有[]，把1加入拷贝的子集中得到[1]，然后加回解集中。此时解集为[[], [1]]。
        遍历到2时，依次拷贝解集中所有子集，有[], [1]，把2加入拷贝的子集得到[2], [1, 2]，然后加回解集中。此时解集为[[], [1], [2], [1, 2]]。
        遍历到3时，依次拷贝解集中所有子集，有[], [1], [2], [1, 2]，把3加入拷贝的子集得到[3], [1, 3], [2, 3], [1, 2, 3]，然后加回解集中。此时解集为[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]。
        */
        vector<vector<int>> ans= {{}};
        for(int i=0;i<nums.size();i++) {
            int size = ans.size();
            for(int j=0;j<size;j++) {
                vector<int> nxt = ans[j];
                nxt.push_back(nums[i]);
                ans.push_back(nxt);
            }
        }
        return ans;
    }
};
// @lc code=end

