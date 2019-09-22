/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reverse_num = 0;
        while (x > reverse_num)
        {
            reverse_num = reverse_num * 10 + x % 10;
            x /= 10;
        }
        return reverse_num == x || reverse_num / 10 == x;
    }
};
