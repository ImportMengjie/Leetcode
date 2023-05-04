#include <string>

/*
给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：

输入: s1 = "abc", s2 = "bca"
输出: true 
示例 2：

输入: s1 = "abc", s2 = "bad"
输出: false
说明：

0 <= len(s1) <= 100
0 <= len(s2) <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-permutation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

class Solution {
public:
    bool CheckPermutation(const string& s1, const string& s2) {
        if(s1.size() != s2.size()) return false;
        int map[26] = {0};
        for(auto& c:s1)
            map[c-'a']++;
        for(auto& c:s2){
            if(!map[c-'a'])
                return false;
            map[c-'a']--;
        }
        return true;
    }
};
