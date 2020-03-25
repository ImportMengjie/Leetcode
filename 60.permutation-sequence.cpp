/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        k--;
        int gap = 1;
        ostringstream ans;
        vector<int> ids;
        for (int i = n - 1; i > 0; i--)
        {
            gap *= i;
            ids.push_back(n - i);
        }
        ids.push_back(n);
        for (int i = n - 1; i > 0; i--)
        {
            ans << ids[k / gap];
            ids.erase(ids.begin() + k / gap);
            k %= gap;
            gap /= i;
        }
        ans << ids[0];
        return ans.str();
    }
};
// @lc code=end
