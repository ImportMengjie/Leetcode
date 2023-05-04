/*
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

回文串不一定是字典当中的单词。

 

示例1：

输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）


来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/palindrome-permutation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <map>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int map[128] = {0};
        int need_twice = s.size()/2;
        for(auto& c:s){
            if(map[c]==0){
                map[c] = 1;
            } else if(map[c]==1){
                need_twice--;
                map[c] = 0;
            } else
                assert(false);
             
        }
        return need_twice == 0;
    }
};

