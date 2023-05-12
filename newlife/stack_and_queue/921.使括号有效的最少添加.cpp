/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftCount = 0;
        int ans = 0;
        for(auto& c:s) {
            if(c == '(') leftCount++;
            else {
                if(leftCount>0) leftCount--;
                else ans++;
            }
        }
        ans += leftCount;
        return ans;
    }
};
// @lc code=end

