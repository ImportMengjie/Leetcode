#include <vector>
#include <map>

using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> target_map = map<int, int>();
        for (int i = 0; i < nums.size(); i++)
        {
            if (target_map.find(nums[i]) == target_map.end())
            {
                target_map[target - nums[i]] = i;
            }
            else
                return vector<int>{target_map[nums[i]], i};
        }
        return vector<int>();
    }
};
