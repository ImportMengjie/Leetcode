/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (43.08%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    98.2K
 * Total Submissions: 226.4K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:

    bool isNumber(char c){
        return '0'<=c&&c<='9';
    }

    bool isVaild(char c){
        return isNumber(c)||('a'<=c&&c<='z')||('A'<=c&&c<='Z');
    }

    bool isEqual(char c1,char c2){
        if(isVaild(c1)&&isVaild(c2))
            return c1==c2||(!isNumber(c1)&&!isNumber(c2)&&((c1-c2)=='A'-'a'||(c2-c1)=='A'-'a'));
        return false;
    }

    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j&&!isVaild(s[i]))
                i++;
            while(i<j&&!isVaild(s[j]))
                j--;
            if(i<j&&!isEqual(s[i],s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

