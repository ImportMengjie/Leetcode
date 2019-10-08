/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i])
                j--;
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        i++;
        int j = nums.size() - 1;
        while (i < j)
        {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++;
            j--;
        }
    }
};
// @lc code=end
