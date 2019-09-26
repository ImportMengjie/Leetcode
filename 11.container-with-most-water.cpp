/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        for (int i = 0, j = height.size() - 1; i < j;)
        {
            max_area = max((j - i) * min(height[i], height[j]), max_area);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};
