/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        bool use[nums.size()] = {false};
        vector<int> track;

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
                if (!use[i])
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
