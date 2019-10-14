/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        bool use[nums.size()] = {false};
        vector<int> track;
        sort(nums.begin(), nums.end());

        backtrack(res, nums, track, use, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &nums, vector<int> &track, bool use[], int depth)
    {
        if (depth == nums.size())
            res.push_back(track);
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (!use[i] && (i == 0 || nums[i] != nums[i - 1] || !use[i - 1]))
                {
                    use[i] = true;
                    track.push_back(nums[i]);
                    backtrack(res, nums, track, use, depth + 1);
                    track.pop_back();
                    use[i] = false;
                }
            }
        }
    }
};
// @lc code=end
