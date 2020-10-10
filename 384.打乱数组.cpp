/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 *
 * https://leetcode-cn.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (53.55%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 51.5K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * 打乱一个没有重复元素的数组。
 * 
 * 
 * 
 * 示例:
 * 
 * // 以数字集合 1, 2 和 3 初始化数组。
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
 * solution.shuffle();
 * 
 * // 重设数组到它的初始状态[1,2,3]。
 * solution.reset();
 * 
 * // 随机返回数组[1,2,3]打乱后的结果。
 * solution.shuffle();
 * 
 * 
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{

private:
    vector<int> nums;

public:
    int randRange(int start, int end)
    {
        return start + (rand() % (end - start));
    }

    Solution(vector<int> &nums) : nums(nums)
    {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> ret(nums);
        for(int i=0;i<ret.size();i++){
            int random = randRange(i, ret.size());
            int t = ret[random];
            ret[random] = ret[i];
            ret[i] = t;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
