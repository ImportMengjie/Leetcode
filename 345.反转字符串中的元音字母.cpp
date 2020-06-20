/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        unordered_set<char> vowels{'a','e','i','o','u'};
        while (i<j) {
            while (i<j&&!(vowels.count(s[i])||vowels.count('a'+s[i]-'A')))
                i++;
            while (i<j&&!(vowels.count(s[j])||vowels.count('a'-'A'+s[j])))
                j--;
            if(i<j)
                swap(s[i++],s[j--]);
        }
        return s;
    }
};
// @lc code=end

