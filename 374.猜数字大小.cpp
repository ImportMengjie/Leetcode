/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 */
 int guess(int num);

// @lc code=start

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right=n;
        while (left<=right) {
            int mid = left + (right-left)/2;
            int answer = guess(mid);
            if(answer==0)
                return mid;
            else if(answer>0) 
                left=mid+1;
            else
                right = mid-1;
        }
        return -1;
    }
};
// @lc code=end

