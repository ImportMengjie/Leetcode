/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int first=10,sencond=9*9;
        int size = min(10,n);
        for(int i=2;i<=size;i++){
            first+=sencond;
            sencond *= 10-i;
        }
        return first;
    }
};
// @lc code=end

